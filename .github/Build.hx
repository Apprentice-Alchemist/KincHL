import haxe.io.Path;

inline function assert(b:Bool, err = "assert")
	if (!b) {
		Sys.println(err);
		Sys.exit(1);
	}

function main() {
	final args = Sys.args();
	final g_api = args[0];
	final sys_name = Sys.systemName().toLowerCase();
	if (sys_name == "windows") {
		Sys.putEnv("HASHLINK_SRC", Path.normalize(Sys.getEnv("GITHUB_WORKSPACE") + "/hashlink/src"));
		Sys.putEnv("HASHLINK_BIN", Path.normalize(Sys.getEnv("GITHUB_WORKSPACE") + "/hashlink/x64/Release"));
	}
	final n_args = ["Kinc/make.js", "--dynlib", "--noshaders", "-g", g_api];
	if (sys_name != "mac")
		n_args.push("--compile");
	assert(Sys.command("node", n_args) == 0, "kincmake error");
	if (sys_name == "mac") {
		Sys.setCwd("build");
		assert(Sys.command("xcodebuild", ["-configuration", "Release", "-project", "KincHL.xcodeproj", "ARCHS=x86_64"]) == 0, "xcodebuild error");
	}
}
