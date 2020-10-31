package kinc;

@:hlNative("kinc", "hl_window_")
extern class Window {
	// Create crashes for some reason. And anyway it doesn't seem to be implemented on anything other than windows
	static function create(win:WindowOptions, fb:FramebufferOptions):Int;
	static function destroy(index:Int):Void;
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
