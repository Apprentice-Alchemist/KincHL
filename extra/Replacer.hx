using StringTools;

class Replacer {
	static function main() {
		var args = Sys.args();
		var file = args.shift();
		var what = args.shift();
		var with = args.shift();
		sys.io.File.saveContent(file, sys.io.File.getContent(file).replace(what, with));
	}
}
