package kinc.input;

@:hlNative("kinc", "surface_")
extern class Surface {
	static function setTouchStartCallback(cb:(index:Int, x:Int, y:Int) -> Void):Void;
	static function setMoveCallback(cb:(index:Int, x:Int, y:Int) -> Void):Void;
	static function setTouchEndCallback(cb:(index:Int, x:Int, y:Int) -> Void):Void;
}
