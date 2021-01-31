package kinc.audio2;

@:build(kinc.Macros.build_struct("a2_buffer_format", true, true, true))
abstract BufferFormat(hl.Abstract<"kinc_a2_buffer_format_t">) {
	public var channels(get, never):Int;
	public var samples_per_second(get, never):Int;
	public var bits_per_sample(get, never):Int;
}
