package kinc.g4;

@:build(kinc.Macros.build_struct("pipeline",true))
abstract Pipeline(hl.Abstract<"kinc_g4_pipeline_t">) to hl.Abstract<"kinc_g4_pipeline_t">{
	public function new(){
		this = alloc();
		init();
	}
	public var input_layout(get, set):kinc.util.NativeArray<VertexStructure,"vertex_structure">;
	public var vertex_shader(get, set):Shader;
	public var fragment_shader(get, set):Shader;
	public var geometry_shader(get, set):Shader;
	public var tessellation_control_shader(get, set):Shader;
	public var tessellation_evaluation_shader(get, set):Shader;
	
	@:hlNative("kinc","pipeline_hl_init") function init():Void {}
	@:hlNative("kinc", "hl_g4_pipeline_compile") public function compile():Void {}
	@:hlNative("kinc","hl_g4_pipeline_get_constant_location") public function getConstantLocation(name:String):ConstantLocation return null;
	@:hlNative("kinc", "hl_g4_pipeline_get_texture_unit") public function getTextureUnit(name:String):TextureUnit return null;
}