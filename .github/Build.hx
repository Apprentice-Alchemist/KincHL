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
	assert(Sys.command("node", n_args) == 0, "kincmake error");
	Sys.setCwd("build");
	FileSystem.createDirectory("bin");
	if (sys_name == "mac") {
		assert(Sys.command("xcodebuild", ["-configuration", "Release", "-project", "KincHL.xcodeproj", "ARCHS=x86_64","LD_FINAL_OUTPUT_FILE=bin/kinc.hdll"]) == 0, "xcodebuild error");
	} else if(sys_name == "windows") {
		Sys.command("MSBuild", ["KincHL.vcxproj", "/m", "/p:Configuration=Release,Platform=x64,OutDir=Release/,TargetExt=.hdll,TargetName=kinc"]);
		File.copy("Release/kinc.hdll", "bin/kinc.hdll");
		File.copy("Release/kinc.lib","bin/kinc.lib");
	} else if(sys_name == "linux") {
		File.saveContent("Release/makefile",File.getContent("Release/makefile").replace('-o "KincHL.so"','-o "kinc.hdll"'));
		Sys.setCwd("Release");
		Sys.command("make",["KincHL.so"]);
		Sys.setCwd("..");
		File.copy("Release/kinc.hdll","bin/kinc.hdll");
	}
	File.copy("bin/kinc.hdll",Path.normalize(gw + "/" + "kinc.hdll"));
	try File.copy("bin/kinc.lib", Path.normalize(gw + "/" + "kinc.lib")) catch(_) {};
}
