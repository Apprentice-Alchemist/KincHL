package kinc.g4;

import kinc.g4.RenderTarget;
import hl.NativeArray;

@:keep
class Pipeline {
	private var _handle:hl.Abstract<"g4_pipeline">;

	public var input_layout(default, null):NativeArray<VertexStructure>;

	public var vertex_shader:Shader;
	public var fragment_shader:Shader;
	public var geometry_shader:Shader;
	public var tessellation_control_shader:Shader;
	public var tessellation_evaluation_shader:Shader;

	public var cull_mode:CullMode;
	public var depth_write:Bool;
	public var depth_mode:CompareMode;
	public var stencil_mode:CompareMode;
	public var stencil_both_pass:StencilAction;
	public var stencil_depth_fail:StencilAction;
	public var stencil_fail:StencilAction;
	public var stencil_reference_value:Int;
	public var stencil_read_mask:Int;
	public var stencil_write_mask:Int;
	public var blend_source:BlendingFactor;
	public var blend_destination:BlendingFactor;
	public var blend_operation:BlendingOperation;
	public var alpha_blend_source:BlendingFactor;
	public var alpha_blend_destination:BlendingFactor;
	public var alpha_blend_operation:BlendingOperation;

	public var color_write_mask_red(default, null):NativeArray<Bool>;
	public var color_write_mask_green(default, null):NativeArray<Bool>;
	public var color_write_mask_blue(default, null):NativeArray<Bool>;
	public var color_write_mask_alpha(default, null):NativeArray<Bool>;

	public var color_attachment_count:Int;
	public var color_attachment(default, null):NativeArray<RenderTargetFormat>;
	public var depth_attachment_bits:Int;
	public var stencil_attachment_bits:Int;
	public var conservative_rasterization:Bool;

	public function new() {
		this._handle = allocNative();

		@:bypassAccessor this.input_layout = new hl.NativeArray<VertexStructure>(16);
		for (i in 0...16)
			input_layout[i] = null;

		this.cull_mode = NOTHING;

		this.depth_write = false;
		this.depth_mode = ALWAYS;

		this.stencil_mode = ALWAYS;
		this.stencil_both_pass = KEEP;
		this.stencil_depth_fail = KEEP;
		this.stencil_fail = KEEP;
		this.stencil_reference_value = 0;
		this.stencil_read_mask = 0xff;
		this.stencil_write_mask = 0xff;

		this.blend_source = ONE;
		this.blend_destination = ZERO;
		this.blend_operation = ADD;
		this.alpha_blend_source = ONE;
		this.alpha_blend_destination = ZERO;
		this.alpha_blend_operation = ADD;

		@:bypassAccessor this.color_write_mask_red = new hl.NativeArray(8);
		for (i in 0...8)
			this.color_write_mask_red[i] = true;
		@:bypassAccessor this.color_write_mask_green = new hl.NativeArray(8);
		for (i in 0...8)
			this.color_write_mask_green[i] = true;
		@:bypassAccessor this.color_write_mask_blue = new hl.NativeArray(8);
		for (i in 0...8)
			this.color_write_mask_blue[i] = true;
		@:bypassAccessor this.color_write_mask_alpha = new hl.NativeArray(8);
		for (i in 0...8)
			this.color_write_mask_alpha[i] = true;

		this.color_attachment_count = 1;
		@:bypassAccessor this.color_attachment = new hl.NativeArray(8);
		for (i in 0...8)
			this.color_attachment[i] = Format32Bit;

		this.depth_attachment_bits = 0;
		this.stencil_attachment_bits = 0;

		this.conservative_rasterization = false;
	}

	// private function set_input_layout(a)
	// 	return a;
	// private function set_color_write_mask_red(a)
	// 	return a;
	// private function set_color_write_mask_green(a)
	// 	return a;
	// private function set_color_write_mask_blue(a)
	// 	return a;
	// private function set_color_write_mask_alpha(a)
	// 	return a;
	// private function set_color_attachment(a)
	// 	return a;

	public function compile():Void {
		compilePipeline(this);
	}

	public function destroy():Void {
		destroyPipeline(this._handle);
	}

	public function getConstantLocation(name:String):ConstantLocation
		return getPipelineConstantLocation(this._handle, name);

	public function getTextureUnit(name:String):TextureUnit
		return getPipelineTextureUnit(this._handle, name);

	@:hlNative("kinc", "hl_g4_pipeline_alloc") @:noCompletion static function allocNative():hl.Abstract<"g4_pipeline">
		return null;

	@:hlNative("kinc", "hl_g4_pipeline_compile") @:noCompletion static function compilePipeline(state:Dynamic):Void {}

	@:hlNative("kinc", "hl_g4_pipeline_get_texture_unit") @:noCompletion static function getPipelineTextureUnit(state:hl.Abstract<"g4_pipeline">,
			name:String):TextureUnit
		return null;

	@:hlNative("kinc", "hl_g4_pipeline_get_constant_location") @:noCompletion static function getPipelineConstantLocation(state:hl.Abstract<"g4_pipeline">,
			name:String):ConstantLocation
		return null;

	@:hlNative("kinc", "hl_g4_pipeline_destroy") @:noCompletion static function destroyPipeline(state:hl.Abstract<"g4_pipeline">):Void {}
}

enum abstract BlendingFactor(Int) from Int to Int {
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

enum abstract BlendingOperation(Int) {
	var ADD;
	var SUBSTRACT;
	var REVERSE_SUBSTRACT;
	var MIN;
	var MAX;
}

enum abstract CompareMode(Int) from Int to Int {
	var ALWAYS;
	var NEVER;
	var EQUAL;
	var NOT_EQUAL;
	var LESS;
	var LESS_EQUAL;
	var GREATER;
	var GREATER_EQUAL;
}

enum abstract CullMode(Int) from Int to Int {
	var CLOCKWISE;
	var COUNTER_CLOCKWISE;
	var NOTHING;
}

enum abstract StencilAction(Int) from Int to Int {
	var KEEP;
	var ZERO;
	var REPLACE;
	var INCREMENT;
	var INCREMENT_WRAP;
	var DECREMENT;
	var DECREMENT_WRAP;
	var INVERT;
}
