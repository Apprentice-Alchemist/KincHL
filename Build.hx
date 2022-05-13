import sys.io.File;
import sys.FileSystem;
import haxe.io.Path;

using StringTools;

enum abstract Target(String) to String {
	var Windows = "windows";
	var Linux = "linux";
	var macOS = "macos";
	var Android = "android";
	var iOS = "ios";

	public static function fromString(s:String):Target {
		switch (cast s : Target) {
			case Windows, Linux, macOS, Android, iOS:
				return cast s;
			default:
				throw "Invalid target";
		}
	}
}

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
	var target = null;
	{
		final args = Sys.args();
		while (true) {
			switch args.shift() {
				case null:
					break;
				case "-g":
					g_api = args.shift();
				case "-t":
					target = Target.fromString(args.shift());
				case "--debug":
					debug = true;
				case "--krafix":
					krafix = true;
				case var arg:
					trace('Unknown argument: $arg');
					Sys.exit(1);
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

	final n_args = ["--dynlib", "--noshaders"];
	if (sys_name == "windows") {
		n_args.push("-v");
		n_args.push("vs2019");
	}
	if (g_api != null) {
		n_args.push("-g");
		n_args.push(g_api);
	}
	if (target != null) {
		n_args.push("-t");
		n_args.push(target);
	}
	if (debug)
		n_args.push("--debug");
	if (Sys.command(sys_name == "windows" ? "Kinc/make.bat" : "Kinc/make", n_args) != 0)
		Sys.exit(1);

	Sys.setCwd("build");
	FileSystem.createDirectory("bin");
	switch target == null ? Target.fromString(sys_name) : target {
		case Windows:
			final configuration = debug ? "Debug" : "Release";

			final vswhere = new sys.io.Process('C:/Program Files (x86)/Microsoft Visual Studio/Installer/vswhere.exe',
				['-products', '*', '-latest', '-find', 'VC\\Auxiliary\\Build\\vcvars64.bat']);

			if (vswhere.exitCode(true) == 0) {
				final path = vswhere.stdout.readAll().toString();
				File.saveContent("build.bat",
					'@call "'
					+ path
					+ '"\n'
					+ "@MSBuild.exe"
					+ " KincHL.vcxproj"
					+ " /m"
					+ (num_cpus == null ? "" : ':$num_cpus')
					+ ' /p:Configuration=$configuration,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc');
				if (Sys.command("build.bat") != 0)
					Sys.exit(1);
			} else {
				Sys.println("Visual Studio not found.");
				Sys.exit(0);
			}

		case Linux:
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
		case macOS, iOS:
			final configuration = debug ? "Debug" : "Release";
			final args = [
				"-configuration",
				configuration,
				"-project",
				"KincHL.xcodeproj",
				"EXECUTABLE_NAME=kinc.hdll",
			];
			if (target != iOS)
				args.push("ARCHS=x86_64");
			if (Sys.command("xcodebuild", args) != 0)
				Sys.exit(1);
			File.copy('build/$configuration/kinc.hdll', "bin/kinc.hdll");
		case Android:
			Sys.setCwd("KincHL");
			File.saveContent("app/CMakeLists.txt", File.getContent("app/CMakeLists.txt") + '\nset_target_properties(kinc PROPERTIES SUFFIX ".hdll")');
			final configuration = debug ? "Debug" : "Release";
			switch sys_name {
				case "windows":
					Sys.command("gradlew.bat", ['assemble$configuration']);
				case _:
					Sys.command("bash", ["gradlew", 'assemble$configuration']);
			}
	}

	try {
		File.copy("bin/kinc.hdll", Path.normalize(gw + "/" + "kinc.hdll"));
		File.copy("bin/kinc.lib", Path.normalize(gw + "/" + "kinc.lib"));
	} catch (_) {};
	Sys.setCwd(working_dir);
	resetPatch("krafix");
}
