package kinc.g5;

enum abstract ShaderType(Int) {
	var FRAGMENT;
	var VERTEX;
	var GEOMETRY;
	var TESSELLATION_CONTROL;
	var TESSELLATION_EVALUATION;
}

@:build(kinc.Macros.build_struct("g5_shader", true))
@:hlNative("kinc", "hl_g5_shader_")
abstract Shader(hl.Abstract<"g5_shader">) {
	public function new(source:hl.Bytes, length:Int, type:ShaderType) {
		this = alloc();
		init(source, length, type);
	}

	function init(source:hl.Bytes, length:Int, type:ShaderType):Void;
}
