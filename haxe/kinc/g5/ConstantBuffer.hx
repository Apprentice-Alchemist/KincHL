package kinc.g5;

import kinc.math.Matrix4;
import kinc.math.Matrix3;

@:build(kinc.Macros.build_struct("g5_constant_buffer", true))
@:hlNative("kinc", "hl_g5_constant_buffer_")
abstract ConstantBuffer(hl.Abstract<"g5_constant_buffer">) {
	public function new(size:Int) {
		this = alloc();
		init(size);
	}

	function init(size:Int):Void;

	public function lock(start:Int, count:Int):Void;
	public function size():Int;

	public function setBool(offset:Int, value:Bool):Void;
	public function setInt(offset:Int, value:Int):Void;
	public function setFloat(offset:Int, value:hl.F32):Void;
	public function setFloat2(offset:Int, v1:hl.F32, v2:hl.F32):Void;
	public function setFloat3(offset:Int, v1:hl.F32, v2:hl.F32, v3:hl.F32):Void;
	public function setFloat4(offset:Int, v1:hl.F32, v2:hl.F32, v3:hl.F32, v4:hl.F32):Void;
	public function setFloats(offset:Int, values:hl.Bytes, count:Int):Void;
	public function setMatrix3(offset:Int, value:Matrix3):Void;
	public function setMatrix4(offset:Int, value:Matrix4):Void;
}