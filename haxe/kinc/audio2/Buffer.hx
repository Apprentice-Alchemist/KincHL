package kinc.audio2;

@:build(kinc.Macros.build_struct("a2_buffer", true, true, true))
abstract Buffer(hl.Abstract<"kinc_a2_buffer_t">) {
    public var format(get,never):BufferFormat;
    public var data(get,set):hl.Bytes;
    public var data_size(get,set):Int;
    public var read_location(get,set):Int;
    public var write_location(get,set):Int;
}