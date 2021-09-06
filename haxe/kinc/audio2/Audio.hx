package kinc.audio2;

@:hlNative("kinc", "a2_")
extern class Audio {
	static function init():Void;

	/**
	 * Do not allocate anything inside the callback, as it is runs on the audio thread which is not GC registered to avoid any issues.
	 */
	@:hlNative("kinc", "hl_a2_set_callback") static function setCallback(cb:(buffer:Buffer, samples:Int) -> Void):Void;

	static function update():Void;
	static function shutdown():Void;
	static function getSamplesPerSecond():Int;
}
