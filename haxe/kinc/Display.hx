package kinc;

import kinc.util.CString;

extern class Display {
	@:hlNative("kinc", "display_init") static function init():Void;
	@:hlNative("kinc", "primary_display") static function primaryDisplay():Int;
	@:hlNative("kinc", "count_displays") static function countDisplays():Int;
	@:hlNative("kinc", "display_available") static function displayAvailable(index:Int):Bool;
	@:hlNative("kinc", "hl_display_name") static function getName(index:Int):CString;
	@:hlNative("kinc", "hl_display_current_mode") static function currentMode(index:Int):DisplayMode;
	@:hlNative("kinc", "display_count_available_modes") static function countAvailableModes(index:Int):Int;
	@:hlNative("kinc", "hl_display_available_mode") static function availableMode(index:Int, mode_index:Int):DisplayMode;
}

@:build(kinc.Macros.build_struct("display_mode", true, true, true))
abstract DisplayMode(hl.Abstract<"kinc_display_mode_t">) {
	public var x(get, never):Int;
	public var y(get, never):Int;
	public var width(get, never):Int;
	public var height(get, never):Int;
	public var pixels_per_inch(get, never):Int;
	public var frequency(get, never):Int;
	public var bits_per_pixel(get, never):Int;
}
