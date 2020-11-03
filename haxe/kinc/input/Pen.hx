package kinc.input;

@:hlNative("kinc", "pen_")
extern class Pen {
	static function setPressCallback(cb:(window:Int, x:Int, y:Int, pressure:hl.F32) -> Void):Void;
	static function setMoveCallback(cb:(window:Int, x:Int, y:Int, pressure:hl.F32) -> Void):Void;
	static function setReleaseCallback(cb:(window:Int, x:Int, y:Int, pressure:hl.F32) -> Void):Void;
}
