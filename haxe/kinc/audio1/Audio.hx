package kinc.audio1;

extern class Audio {
	@:hlNative("kinc", "a1_init") static function init():Void;
	@:hlNative("kinc", "hl_a1_sound_create") static function createSound(filename:String):Sound;
	@:hlNative("kinc", "a1_play_sound") static function playSound(sound:Sound, loop:Bool, pitch:hl.F32, unique:Bool):Channel;
	@:hlNative("kinc", "a1_stop_sound") static function stopSound(sound:Sound):Void;
}
