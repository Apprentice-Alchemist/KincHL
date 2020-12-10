package kinc.util;

@:hlNative("kinc", "float_wrapper_")
abstract FloatWrapper(hl.Abstract<"float_wrapper">) {
	@:from
	static function alloc(f:Float):FloatWrapper
		return null;

	@:to function get():Float
		return 0.0;

	@:op(A * B)
	static function multiply(a:FloatWrapper, b:FloatWrapper):FloatWrapper
		return null;

	@:op(A / B)
	static function divide(a:FloatWrapper, b:FloatWrapper):FloatWrapper
		return null;

	@:op(A + B)
	static function add(a:FloatWrapper, b:FloatWrapper):FloatWrapper
		return null;

	@:op(A - B)
	static function substract(a:FloatWrapper, b:FloatWrapper):FloatWrapper
		return null;

	@:op(A > B)
	static function greater(a:FloatWrapper, b:FloatWrapper):Bool
		return false;

	@:op(A < B)
	static inline function smaller(a:FloatWrapper, b:FloatWrapper):Bool
		return greater(b, a);
}
