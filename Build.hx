import sys.io.File;
import sys.FileSystem;
import haxe.io.Path;

using StringTools;

inline function assert(b:Bool, err = "assert")
	if (!b) {
		Sys.println(err);
		Sys.exit(1);
	}

function main() {
	final gw = Sys.getEnv("GITHUB_WORKSPACE");
	final args = Sys.args();
	final g_api = args[0];
	final sys_name = Sys.systemName().toLowerCase();
	if (sys_name == "windows") {
		Sys.putEnv("HASHLINK_SRC", Path.normalize(gw + "/hashlink/src"));
		Sys.putEnv("HASHLINK_BIN", Path.normalize(gw + "/hashlink/x64/Release"));
	}
	var debug = Sys.getEnv("DEBUG") != null;
	var krafix = Sys.getEnv("INCLUDE_KRAFIX") != null;
	var g_api = Sys.getEnv("KINCHL_GRAPHICS");
	for (arg in args) {
		if (arg == "-g") {
			g_api = args.shift();
		}
		if (arg == "--debug")
			debug = true;
		if (arg == "--krafix")
			krafix = true;
	}

	if (krafix) {
		Sys.putEnv("INCLUDE_KRAFIX", "1");
	}
	sys.io.File.saveContent("krafix/kincfile.js", sys.io.File.getContent("krafix/kincfile.js").replace("let library = false;", "let library = true;"));
	final n_args = ["Kinc/make.js", "--dynlib", "--noshaders","-k","../Kinc"];
	if (g_api != null) {
		args.push("-g");
		args.push(g_api);
	}

	if (debug)
		n_args.push("--debug");
	if (Sys.command("node", n_args) != 0)
		Sys.exit(1);
	sys.io.File.saveContent("krafix/kincfile.js", sys.io.File.getContent("krafix/kincfile.js").replace("let library = true;", "let library = false;"));
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
			"/m",
			'/p:Configuration=$configuration,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc'
		]) != 0)
			Sys.exit(1);
	} else if (sys_name == "linux") {
		final configuration = debug ? "Debug" : "Release";
		File.saveContent('$configuration/makefile', File.getContent('$configuration/makefile').replace('KincHL.so', 'kinc.hdll'));
		Sys.setCwd(configuration);
		if (Sys.command("make") != 0)
			Sys.exit(1);
		Sys.setCwd("..");
		File.copy('$configuration/kinc.hdll', "bin/kinc.hdll");
	}

	try {
		File.copy("bin/kinc.hdll", Path.normalize(gw + "/" + "kinc.hdll"));
		File.copy("bin/kinc.lib", Path.normalize(gw + "/" + "kinc.lib"));
	} catch (_) {};
}
