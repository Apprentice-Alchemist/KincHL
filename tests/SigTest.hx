package;

/**
 * This test could possibly be used in CI context to check that all function signatures match
 */
class SigTest {
	public static macro function inctypes() {
		haxe.macro.Compiler.keep("kinc", true);
		var arr = [];
		function readRec(dir:String, basePath:String) {
			var p = haxe.io.Path.addTrailingSlash(haxe.io.Path.normalize(haxe.io.Path.join([basePath, dir])));
			var d = sys.FileSystem.readDirectory(p);
			for (x in d) {
				if (sys.FileSystem.isDirectory(p + x)) {
					readRec(dir + "/" + x, basePath);
				} else {
					var tmp = haxe.io.Path.normalize(haxe.io.Path.join([dir, haxe.io.Path.withoutExtension(x)]));
					var tmp2 = StringTools.replace((StringTools.startsWith(tmp, "/") ? tmp.substr(1) : tmp), "/", ".");
					if (StringTools.startsWith(tmp2, "kinc.util") || tmp2.indexOf("g5") > -1)
						continue; // supress macro shenanigans
					arr.push(tmp2);
				}
			}
		}
		readRec("", "haxe");
		for (x in arr)
			haxe.macro.Context.getType(x);
		return macro null;
	}

	#if !macro
	public static function main() {
		inctypes();
		Sys.println("SigTest successful");
	}
	#end
}
