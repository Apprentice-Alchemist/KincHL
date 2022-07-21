package kinc.g5;

enum abstract IndexBufferFormat(Int) {
	var IBFormat32Bit;
	var IBFormat16Bit;
}

@:build(kinc.Macros.build_struct("g5_index_buffer", true))
@:hlNative("kinc", "hl_g5_index_buffer_")
abstract IndexBuffer(hl.Abstract<"g5_index_buffer">) {
	public function new(count:Int, format:IndexBufferFormat, gpuMemory:Bool) {
		this = alloc();
		init(count, format, gpuMemory);
	}

	function init(count:Int, format:IndexBufferFormat, gpu_memory:Bool):Void;

	public function lock():hl.Bytes;

	public function unlock():Void;

	public function count():Int;
}
