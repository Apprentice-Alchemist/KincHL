import sys.io.File;
import sys.FileSystem;
import haxe.io.Path;

using StringTools;

function applyPatch(dir:String, patch:String) {
	Sys.command("git", ["-C", dir, "apply", '../patches/$patch']);
}

function resetPatch(dir:String) {
	Sys.command("git", ["-C", dir, "reset", "--hard", "--quiet"]);
}

function main() {
	final gw = Sys.getEnv("GITHUB_WORKSPACE");
	var num_cpus:Null<Int> = null;
	try {
		if (Sys.getEnv("NUMBER_OF_PROCESSORS") != null) {
			num_cpus = Std.parseInt(Sys.getEnv("NUMBER_OF_PROCESSORS"));
		} else {
			#if eval
			final cpus = eval.luv.SystemInfo.cpuInfo().resolve();
			num_cpus = cpus.length;
			#end
		}
	}
	final working_dir = Sys.getCwd();
	final sys_name = Sys.systemName().toLowerCase();
	var debug = Sys.getEnv("DEBUG") != null;
	var krafix = Sys.getEnv("INCLUDE_KRAFIX") != null;
	var g_api = Sys.getEnv("KINCHL_GRAPHICS");
	{
		final args = Sys.args();
		while (true) {
			switch args.shift() {
				case null:
					break;
				case var arg:
					if (arg == "-g") {
						g_api = args.shift();
					}
					if (arg == "--debug")
						debug = true;
					if (arg == "--krafix")
						krafix = true;
			}
		}
	}

	if (krafix) {
		Sys.putEnv("INCLUDE_KRAFIX", "1");
	}

	if (debug) {
		Sys.putEnv("KINCHL_VALIDATE_VULKAN", "1");
	}

	applyPatch("krafix", "krafix.diff");

	final n_args = ["Kinc/make.js", "--dynlib", "--noshaders"];
	if (sys_name == "windows") {
		n_args.push("-v");
		n_args.push("vs2019");
	}
	if (g_api != null) {
		n_args.push("-g");
		n_args.push(g_api);
	}
	if (debug)
		n_args.push("--debug");
	if (Sys.command("node", n_args) != 0)
		Sys.exit(1);

	Sys.setCwd("build");
	FileSystem.createDirectory("bin");
	if (sys_name == "mac") {
		final configuration = debug ? "Debug" : "Release";
		if (Sys.command("xcodebuild", [
			"-configuration",
			configuration,
			"-project",
			"KincHL.xcodeproj",
			"ARCHS=x86_64",
			"EXECUTABLE_NAME=kinc.hdll",
		]) != 0)
			Sys.exit(1);
		File.copy('build/$configuration/kinc.hdll', "bin/kinc.hdll");
	} else if (sys_name == "windows") {
		final configuration = debug ? "Debug" : "Release";
		if (Sys.command("MSBuild", [
			"KincHL.vcxproj",
			"/m" + (num_cpus == null ? "" : ':$num_cpus'),
			'/p:Configuration=$configuration,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc'
		]) != 0)
			Sys.exit(1);
	} else if (sys_name == "linux") {
		final configuration = debug ? "Debug" : "Release";
		File.saveContent('$configuration/makefile', File.getContent('$configuration/makefile').replace('KincHL.so', 'kinc.hdll'));
		Sys.setCwd(configuration);
		final m_args = [];
		if (num_cpus != null) {
			Sys.println('Using $num_cpus cores.');
			m_args.push("-j" + num_cpus);
		}
		if (Sys.command("make", m_args) != 0)
			Sys.exit(1);
		Sys.setCwd("..");
		File.copy('$configuration/kinc.hdll', "bin/kinc.hdll");
	}

	try {
		File.copy("bin/kinc.hdll", Path.normalize(gw + "/" + "kinc.hdll"));
		File.copy("bin/kinc.lib", Path.normalize(gw + "/" + "kinc.lib"));
	} catch (_) {};
	Sys.setCwd(working_dir);
	resetPatch("krafix");
}
