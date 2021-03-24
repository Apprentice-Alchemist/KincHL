package kinc.audio2;

@:hlNative("kinc", "a2_")
extern class Audio {
	static function init():Void;
	/**
	 * Do not allocate anything inside the callback, as it is run on the audio thread which is not GC registered.
	 */
	@:hlNative("kinc", "hl_a2_set_callback") static function setCallback(cb:(buffer:Buffer, samples:Int) -> Void):Void;
	static function update():Void;
	static function shutdown():Void;
	static var samples_per_second(get, never):Int;
	private static function get_samples_per_second():Int;
	// private static function set_samples_per_second(v:Int):Int;
}
