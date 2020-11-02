package kinc.g4;

import kinc.g4.RenderTarget.RenderTargetFormat;

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

	public var cull_mode(get,set):CullMode;
	public var depth_write(get,set):Bool;
	public var depth_mode(get,set):CompareMode;
	public var stencil_mode(get,set):CompareMode;
	public var stencil_both_pass(get,set):StencilAction;
	public var stencil_depth_fail(get,set):StencilAction;
	public var stencil_fail(get,set):StencilAction;
	public var stencil_reference_value(get,set):Int;
	public var stencil_read_mask(get,set):Int;
	public var stencil_write_mask(get,set):Int;
	public var blend_source(get,set):BlendingOperation;
	public var blend_destination(get,set):BlendingOperation;
	public var alpha_blend_source(get,set):BlendingOperation;
	public var alpha_blend_destination(get,set):BlendingOperation;
	public var color_write_mask_red(get,never):kinc.util.NativeArray<Bool,"bool">;
	public var color_write_mask_green(get, never):kinc.util.NativeArray<Bool, "bool">;
	public var color_write_mask_blue(get, never):kinc.util.NativeArray<Bool, "bool">;
	public var color_write_mask_alpha(get, never):kinc.util.NativeArray<Bool, "bool">;
	public var color_attachment_count(get,set):Int;
	public var color_attachment(get,never):kinc.util.NativeArray<RenderTargetFormat,"rtf">;
	public var depth_attachment_bits(get,set):Int;
	public var stencil_attachment_bits(get,set):Int;
	public var conservative_rasterization(get,set):Bool;

	@:hlNative("kinc","pipeline_hl_init") function init():Void {}
	@:hlNative("kinc", "hl_g4_pipeline_compile") public function compile():Void {}
	@:hlNative("kinc","hl_g4_pipeline_get_constant_location") public function getConstantLocation(name:String):ConstantLocation return null;
	@:hlNative("kinc", "hl_g4_pipeline_get_texture_unit") public function getTextureUnit(name:String):TextureUnit return null;
}

enum abstract BlendingOperation(Int) {
	var ONE;
	var ZERO;
	var SOURCE_ALPHA;
	var DEST_ALPHA;
	var INV_SOURCE_ALPHA;
	var INV_DEST_ALPHA;
	var SOURCE_COLOR;
	var DEST_COLOR;
	var INV_SOURCE_COLOR;
	var INV_DEST_COLOR;
}

enum abstract CompareMode(Int) {
	var ALWAYS;
	var NEVER;
	var EQUAL;
	var NOT_EQUAL;
	var LESS;
	var LESS_EQUAL;
	var GREATER;
	var GREATE_EQUAL;
}

enum abstract CullMode(Int) {
	var CLOCKWISE;
	var COUNTER_CLOCKWISE;
	var NOTHING;
}

enum abstract StencilAction(Int) {
	var KEEP;
	var ZERA;
	var REPLACE;
	var INCREMENT;
	var INCREMENT_WRAP;
	var DECREMENT;
	var DECREMENT_WRAP;
	var INVERT;
}