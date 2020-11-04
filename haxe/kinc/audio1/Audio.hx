package kinc.audio1;

extern class Audio {
    @:hlNative("kinc","a1_init") static function init():Void;
    @:hlNative("kinc", "hl_a1_sound_create") static function createSound(filename:String):hl.Abstract<"kinc_a1_sound_t">;
	@:hlNative("kinc", "a1_play_sound") static function playSound(sound:hl.Abstract<"kinc_a1_sound_t">,loop:Bool,pitch:hl.F32,unique:Bool):hl.Abstract<"kinc_a1_channel_t">;
    @:hlNative("kinc", "a1_sound_volume") static function getSoundVolume(sound:hl.Abstract<"kinc_a1_sound_t">):hl.F32;
	@:hlNative("kinc", "a1_sound_set_volume") static function setSoundVolume(sound:hl.Abstract<"kinc_a1_sound_t">,v:hl.F32):Void;
}