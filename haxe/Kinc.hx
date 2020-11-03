package;

import kinc.Window;

@:hlNative("kinc", "hl_")
extern class Kinc {
	public static function init(name:String, width:Int, height:Int, win:WindowOptions, fb:FramebufferOptions):Int;
	public static function start():Void;
	public static function stop():Void;
	public static function log(level:LogLevel,msg:String):Void;
	public static function setUpdateCallback(cb:Void->Void):Void;
	public static function setDropFileCallback(cb:String->Void):Void;
	public static function setCutCallback(cb:Void->String):Void;
	public static function setPasteCallback(cb:String->Void):Void;
}
enum abstract LogLevel(Int) from Int {
	var LOG_LEVEL_INFO;
	var LOG_LEVEL_WARNING;
	var LOG_LEVEL_ERROR;
}