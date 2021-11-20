package kinc.input;

@:hlNative("kinc", "mouse_")
extern class Mouse {
	static function canLock(window:Int):Bool;
	static function isLocked(window:Int):Bool;
	static function lock(window:Int):Void;
	static function unlock(window:Int):Void;
	static function setCursor(cursor:Int):Void;
	static function show():Void;
	static function hide():Void;
	static function setPosition(window:Int, x:Int, y:Int):Void;
	static function getPosition(window:Int, x:hl.Ref<Int>, y:hl.Ref<Int>):Void;
	@:hlNative("kinc", "hl_mouse_set_press_callback")
	static function setPressCallback(cb:(window:Int, button:Int, x:Int, y:Int) -> Void):Void;
	@:hlNative("kinc", "hl_mouse_set_release_callback")
	static function setReleaseCallback(cb:(window:Int, button:Int, x:Int, y:Int) -> Void):Void;
	@:hlNative("kinc", "hl_mouse_set_move_callback")
	static function setMoveCallback(cb:(window:Int, x:Int, y:Int, mov_x:Int, mov_y:Int) -> Void):Void;
	@:hlNative("kinc", "hl_mouse_set_scroll_callback")
	static function setScrollCallback(cb:(window:Int, delta:Int) -> Void):Void;
	@:hlNative("kinc", "hl_mouse_set_enter_window_callback")
	static function setEnterWindowCallback(cb:(window:Int) -> Void):Void;
	@:hlNative("kinc", "hl_mouse_set_leave_window_callback")
	static function setLeaveWindowCallback(cb:(window:Int) -> Void):Void;
}
