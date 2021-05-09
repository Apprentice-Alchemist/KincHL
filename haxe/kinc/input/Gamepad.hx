package kinc.input;

import kinc.util.CString;

@:hlNative("kinc", "hl_gamepad_")
extern class Gamepad {
	static function vendor(gamepad:Int):CString;
	static function productName(gamepad:Int):CString;
	static function connected(gamepad:Int):Bool;
	static function setAxisCallback(cb:(gamepad:Int, axis:Int, value:hl.F32) -> Void):Void;
	static function setButtonCallback(cb:(gamepad:Int, button:Int, value:hl.F32) -> Void):Void;
}
