package kinc.audio1;

@:build(kinc.Macros.build_struct("a1_channel", true, true, true))
abstract Channel(hl.Abstract<"kinc_a1_channel_t">) {
	public var volume(get, set):hl.F32;
}
