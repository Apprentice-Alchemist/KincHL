package kinc.g4;

@:build(kinc.Macros.build_struct("index_buffer"))
abstract IndexBuffer(hl.Abstract<"kinc_g4_index_buffer_t">) to hl.Abstract<"kinc_g4_index_buffer_t"> {
	public static function make(count:Int, format:IndexBufferFormat) {
		var ret = new IndexBuffer();
		init(ret, count, format);
		return ret;
	}

	@:hlNative("kinc", "hl_g4_index_buffer_init") static function init(buf:hl.Abstract<"kinc_g4_index_buffer_t">, count:Int, format:Int):Void {}

	@:hlNative("kinc", "hl_g4_index_buffer_lock") public function lock():kinc.util.NativeArray<Int,"int"> {
		return null;
	}

	@:hlNative("kinc", "hl_g4_index_buffer_unlock") public function unlock():Void {}
	@:hlNative("kinc","hl_g4_index_buffer_count") public function count():Int {return 0;};
}

enum abstract IndexBufferFormat(Int) to Int {
	var _32BIT;
	var _16BIT;
}
