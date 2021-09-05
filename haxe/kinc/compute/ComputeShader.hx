package kinc.compute;

import kinc.compute.Compute;
import kinc.util.CString;

@:hlNative("kinc", "hl_compute_shader_")
@:build(kinc.Macros.build_struct("compute_shader", true))
abstract ComputeShader(hl.Abstract<"compute_shader">) {
	public function new(source:haxe.io.Bytes) {
		this = alloc();
		init(source, source.length);
	}

	private function init(source:hl.Bytes, length:Int):Void;

	public function getConstantLocation(name:CString):ComputeConstantLocation;

	public function getTextureUnit(name:CString):ComputeTextureUnit;
}
