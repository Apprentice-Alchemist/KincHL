package kinc.audio1;

import hl.F32;
import kinc.audio2.BufferFormat;

@:build(kinc.Macros.build_struct("a1_sound", true, true, true))
@:hlNative("kinc", "hl_a1_sound_")
abstract Sound(hl.Abstract<"kinc_a1_sound_t">) {
	public static function create(filename:String):Sound;

	public var format(get, never):BufferFormat;
	public var left(get, never):hl.Bytes;
	public var right(get, never):hl.Bytes;
	public var size(get, set):Int;
	public var sample_rate_pos(get, set):F32;
	public var volume(get, set):F32;

	public function destroy():Void;
}
