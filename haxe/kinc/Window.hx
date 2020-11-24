package kinc;

@:hlNative("kinc", "hl_window_")
extern class Window {
	/**
	 * Warning : Only implemented on Windows OpenGL
	 */
	static function create(win:WindowOptions, fb:FramebufferOptions):Int;

	static function destroy(index:Int):Void;
	@:hlNative("kinc", "hl_count_windows") static function countWindows():Int;
	static function resize(index:Int, width:Int, height:Int):Void;
	static function move(index:Int, x:Int, y:Int):Void;
	static function changeMode(index:Int, mode:WindowMode):Void;
	static function changeFeatures(index:Int, features:Int):Void;
	static function changeFramebuffer(index:Int, opts:FramebufferOptions):Void;
	static function x(index:Int):Int;
	static function y(index:Int):Int;
	static function width(index:Int):Int;
	static function height(index:Int):Int;
	static function display(index:Int):Int;
	static function getMode(index:Int):Int;
	static function show(index:Int):Void;
	static function hide(index:Int):Void;
	static function setTitle(index:Int, name:String):Void;
	static function setResizeCallback(index:Int, cb:Int->Int->Void):Void;
	static function setPpiChangedCallback(index:Int, cb:Int->Void):Void;
	static function vsynced(index:Int):Bool;
}

enum abstract WindowMode(Int) from Int to Int {
	var WINDOWED;
	var FULLSCREEN;
	var EXCLUSIVE_FULLSCREEN;
}

enum abstract WindowFeatures(Int) from Int to Int {
	var RESIZEABLE = 1;
	var MINIMIZABLE = 2;
	var MAXIMIZABLE = 4;
	var BORDERLESS = 8;
	var ON_TOP = 16;

	@:op(A | B) private inline function op(a):WindowFeatures return this | a;
}

@:structInit
class WindowOptions {
	public var title:String = null;
	public var x:Int = -1;
	public var y:Int = -1;
	public var width:Int = 800;
	public var height:Int = 600;
	public var display_index:Int = 0;
	public var visible:Bool = true;
	public var window_features:WindowFeatures = RESIZEABLE | MINIMIZABLE | MAXIMIZABLE;
	public var mode:WindowMode = WINDOWED;
}

@:structInit
class FramebufferOptions {
	public var color_bits:Int = 32;
	public var depth_bits:Int = 16;
	public var frequency:Int = 60;
	public var samples_per_pixel:Int = 1;
	public var stencil_bits:Int = 8;
	public var vertical_sync:Bool = true;
}
