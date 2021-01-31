package kinc.math;

@:hlNative("kinc", "hl_matrix4x4_")
abstract Matrix4(hl.Abstract<"kinc_matrix4x4_t">) {
	public inline function new() {
		this = cast alloc();
	}

	static function alloc():Matrix4 {
		return null;
	}

	public function get(x:Int, y:Int):hl.F32
		return 0;

	public function set(x:Int, y:Int, v:hl.F32):Void {}
}
