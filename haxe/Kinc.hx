package;

import hl.I64;
import kinc.Window;

@:hlNative("kinc", "hl_")
extern class Kinc {
	static function init(name:String, width:Int, height:Int, win:WindowOptions, fb:FramebufferOptions):Int;
	static function start():Void;
	static function stop():Void;
	static function log(level:LogLevel,msg:String):Void;
	static function applicationName():String;
	static function setApplicationName(name:String):Void;
	static function width():Int;
	static function height():Int;
	static function loadUrl(url:String):Void;
	static function systemId():String;
	static function videoFormats():hl.NativeArray<String>;
	static function language():String;
	static function vibrate(milliseconds:Int):Void;
	static function safeZone():hl.F32;
	static function setSafeZone(value:hl.F32):Void;
	static function frequency():Float;
	static function timestamp():hl.I64;
	static function time():Float;
	static function setUpdateCallback(cb:Void->Void):Void;
	static function setDropFileCallback(cb:String->Void):Void;
	static function setCutCallback(cb:Void->String):Void;
	static function setPasteCallback(cb:String->Void):Void;
}
enum abstract LogLevel(Int) from Int {
	var LOG_LEVEL_INFO;
	var LOG_LEVEL_WARNING;
	var LOG_LEVEL_ERROR;
}