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
	final n_args = ["Kinc/make.js", "--dynlib", "--noshaders", "-g", g_api];
	if(Sys.command("node", n_args) != 0)
		Sys.exit(1);
	Sys.setCwd("build");
	FileSystem.createDirectory("bin");
	if (sys_name == "mac") {
		// File.saveContent("KincHL.xcodeproj",File.getContent("KincHL.xcodeproj").replace("KincHL.dylib","kinc.hdll".replace("KincHL","kinc")));
		if (Sys.command("xcodebuild", [
			"-configuration",
			"Release",
			"-project",
			"KincHL.xcodeproj",
			"ARCHS=x86_64",
			"EXECUTABLE_PATH=kinc.hdll",
			"EXECUTABLE_FOLDER_PATH=bin"]) != 0)
			Sys.exit(1);
		// File.copy("build/Release/kinc.hdll","bin/kinc.hdll");
	} else if (sys_name == "windows") {
		if (Sys.command("MSBuild", [
			"KincHL.vcxproj",
			"/m",
			"/p:Configuration=Release,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc"
		]) != 0)
			Sys.exit(1);
		File.copy("Release/kinc.hdll", "bin/kinc.hdll");
		File.copy("Release/kinc.lib", "bin/kinc.lib");
	} else if (sys_name == "linux") {
		File.saveContent("Release/makefile", File.getContent("Release/makefile").replace('-o "KincHL.so"', '-o "kinc.hdll"'));
		Sys.setCwd("Release");
		if (Sys.command("make", ["KincHL.so"]) != 0)
			Sys.exit(1);
		Sys.setCwd("..");
		File.copy("Release/kinc.hdll", "bin/kinc.hdll");
	}
	// try
		File.copy("bin/kinc.hdll", Path.normalize(gw + "/" + "kinc.hdll"))
	// catch (_) {};
	try
		File.copy("bin/kinc.lib", Path.normalize(gw + "/" + "kinc.lib"))
	catch (_) {};
}
