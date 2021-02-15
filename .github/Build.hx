import haxe.io.Path;

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
	Sys.command("node", n_args);
	if (sys_name == "mac")
		Sys.command("xcodebuild", ["-configuration", "Release", "-project", "KincHL.xcodeproj", "ARCHS=x86_64"]);
}
