package kinc.audio1;

import hl.F32;
import kinc.audio2.BufferFormat;

@:build(kinc.Macros.build_struct("a1_sound", true, true, true))
@:hlNative("kinc", "hl_a1_sound_")
abstract Sound(hl.Abstract<"kinc_a1_sound_t">) {
	public var format(get, never):BufferFormat;
	public var left(get, set):hl.BytesAccess<hl.UI16>; // not sure how I should type those
	public var right(get, set):hl.BytesAccess<hl.UI16>;
	public var size(get, set):Int;
	public var sample_rate_pos(get, set):F32;
	@:no_get @:no_set
	public var volume(get, set):F32;
	function get_volume():F32 return 1.0;
	function set_volume(v:F32):F32 return 1.0;
	public static function create(filname:String):Sound return null;
	public function destroy():Void {}
}
