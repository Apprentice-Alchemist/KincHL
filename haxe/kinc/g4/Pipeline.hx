package kinc.g4;

@:build(kinc.Macros.build_struct("pipeline"))
abstract Pipeline(hl.Abstract<"kinc_g4_pipeline_t">) to hl.Abstract<"kinc_g4_pipeline_t">{
	public var input_layout(get, set):kinc.util.NativeArray<hl.Abstract<"kinc_g4_vertex_structure_t">,"vertex_structure">;
	public var vertex_shader(get, set):hl.Abstract<"kinc_g4_shader_t">;
	public var fragment_shader(get, set):hl.Abstract<"kinc_g4_shader_t">;
	public var geometry_shader(get, set):hl.Abstract<"kinc_g4_shader_t">;
	public var tessellation_control_shader(get, set):hl.Abstract<"kinc_g4_shader_t">;
	public var tessellation_evaluation_shader(get, set):hl.Abstract<"kinc_g4_shader_t">;
	@:hlNative("kinc", "hl_g4_pipeline_compile") public function compile():Void {}
}