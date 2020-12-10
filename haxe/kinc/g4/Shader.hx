package kinc.g4;

@:build(kinc.Macros.build_struct("g4_shader"))
abstract Shader(hl.Abstract<"g4_shader">) {
	public static function fromFile(file:String, type:ShaderType):Shader {
		var ret = new Shader();
		ret.initFromFile(file, type);
		return ret;
	}

	public static function create(b:haxe.io.Bytes, type:ShaderType) {
		var ret = new Shader();
		ret._init(b.getData(), b.getData().length, type);
		return ret;
	}

	public function initFromString(s:String, type:ShaderType) init_from_source(@:privateAccess s.toUtf8(), type);
	@:hlNative("kinc", "hl_g4_shader_init_from_source") function init_from_source(b:hl.Bytes, type:Int):Void {};
	@:hlNative("kinc", "hl_g4_shader_init") function _init(b:hl.Bytes, length:Int, type:ShaderType):Void {}
	@:hlNative("kinc", "hl_g4_shader_init_from_file") public function initFromFile(file:String, type:ShaderType):Void {};
}

enum abstract ShaderType(Int) to Int {
	var FragmentShader;
	var VertexShader;
	var GeometryShader;
	var TesselationControlShader;
	var TesselationEvaluationShader;
}
