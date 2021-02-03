package kinc.g4;

@:build(kinc.Macros.build_struct("g4_index_buffer", true))
@:hlNative("kinc", "hl_g4_index_buffer_")
abstract IndexBuffer(hl.Abstract<"g4_index_buffer">) {
	public function new(count:Int, format:IndexBufferFormat) {
		this = alloc();
		init(count, format);
	}

	function init(count:Int, format:Int):Void;

	public function lock():hl.BytesAccess<Int>;

	public function unlock():Void;

	public function count():Int;
}

enum abstract IndexBufferFormat(Int) from Int to Int {
	var IbFormat32BIT;
	var IbFormat16BIT;
}
