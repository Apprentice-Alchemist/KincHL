package kinc;

@:hlNative("kinc", "hl_window_")
extern class Window {
	/**
	 * Warning : Only implemented on Windows OpenGL
	 */
	static function create(win:WindowOptions, fb:FramebufferOptions):Int;
	static function destroy(index:Int):Void;
	@:hlNative("kinc","hl_count_windows") static function countWindows():Int;
	static function resize(index:Int,width:Int,height:Int):Void;
	static function move(index:Int,x:Int,y:Int):Void;
	static function changeMode(index:Int,mode:WindowMode):Void;
	static function changeFeatures(index:Int,features:Int):Void;
	static function changeFramebuffer(index:Int,opts:FramebufferOptions):Void;
	static function x(index:Int):Int;
	static function y(index:Int):Int;
	static function width(index:Int):Int;
	static function height(index:Int):Int;
	static function display(index:Int):Int;
	static function getMode(index:Int):Int;
	static function show(index:Int):Void;
	static function hide(index:Int):Void;
	static function setTitle(index:Int,name:String):Void;
	static function setResizeCallback(index:Int,cb:Int->Int->Void):Void;
	static function setPpiChangedCallback(index:Int,cb:Int->Void):Void;
	static function vsynced(index:Int):Bool;
}

enum abstract WindowMode(Int) from Int to Int {
	var WINDOWED;
	var FULLSCREEN;
	var EXCLUSIVE_FULLSCREEN;
}

@:structInit
class WindowOptions {
	var title:String;
	var x:Int;
	var y:Int;
	var width:Int;
	var height:Int;
	var display_index:Int;
	var visible:Bool;
	var window_features:Int;
	var mode:WindowMode;
}

@:structInit
class FramebufferOptions {
	var color_bits:Int;
	var depth_bits:Int;
	var frequency:Int;
	var samples_per_pixel:Int;
	var stencil_bits:Int;
	var vertical_sync:Bool;
}
