package kinc.math;

@:hlNative("kinc", "hl_matrix3x3_")
abstract Matrix3(hl.Abstract<"kinc_matrix3x3_t">) to hl.Abstract<"kinc_matrix3x3_t"> {
	public inline function new() {
		this = alloc();
	}

	static function alloc():Matrix3 {
		return null;
	}

	public function get(x:Int, y:Int):hl.F32
		return 0;

	public function set(x:Int, y:Int, v:hl.F32):Void {}

	public function transpose():Void {};

	public static function identity():Matrix3
		return null;

	public static function rotationX(alpha:hl.F32):Matrix3
		return null;

	public static function rotationY(alpha:hl.F32):Matrix3
		return null;

	public static function rotationZ(alpha:hl.F32):Matrix3
		return null;

	@:op(A * B) static function multiply(a:Matrix3,b:Matrix3) {
		var ret = new Matrix3();
		// ret.set(0,0,a.get(0,0) * b.get(0,0) + a.get())
		return ret;
	}
}
