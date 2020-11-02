package kinc.g4;

@:build(kinc.Macros.build_struct("index_buffer", true))
@:hlNative("kinc", "hl_g4_index_buffer_")
abstract IndexBuffer(hl.Abstract<"kinc_g4_index_buffer_t">) to hl.Abstract<"kinc_g4_index_buffer_t"> {
	public function new(count:Int, format:IndexBufferFormat) {
		this = alloc();
		init(count, format);
	}
	function init(count:Int, format:Int):Void {}
	public function lock():kinc.util.NativeArray<Int, "int"> return null;
	public function unlock():Void {}
	public function count():Int return 0;
}

enum abstract IndexBufferFormat(Int) to Int {
	var IbFormat32BIT;
	var IbFormat16BIT;
}
