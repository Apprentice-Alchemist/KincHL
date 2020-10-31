package;

import kinc.Window;

@:hlNative("kinc", "hl_")
extern class Kinc {
	public static function init(name:String, width:Int, height:Int, win:WindowOptions, fb:FramebufferOptions):Int;
	public static function start():Void;
	public static function stop():Void;
}