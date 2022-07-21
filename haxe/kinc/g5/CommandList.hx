package kinc.g5;

enum abstract ClearFlags(Int) {
	var Color = 1;
	var Depth = 2;
	var Stencil = 4;

	@:op(A | B) static function and(a:ClearFlags, b:ClearFlags):ClearFlags;
}

@:build(kinc.Macros.build_struct("g5_command_list", true))
@:hlNative("kinc", "hl_g5_command_list_")
abstract CommandList(hl.Abstract<"g5_command_list">) {
	public function new() {
		this = alloc();
		init();
	}

	function init():Void;

	public function begin():Void;

	public function end():Void;

	public function clear(target:RenderTarget, flags:ClearFlags, color:Int, depth:Single, stencil:Int):Void;

	public function renderTargetToFramebufferBarrier(target:RenderTarget):Void;

	public function framebufferToRenderTargetBarrier(target:RenderTarget):Void;

	public function textureToRenderTargetBarrier(target:RenderTarget):Void;

	public function renderTargetToTextureBarrier(target:RenderTarget):Void;

	public function drawIndexedVertices():Void;

	public function drawIndexedVerticesFromTo(start:Int, count:Int):Void;

	public function drawIndexedVerticesFromToFrom(start:Int, count:Int, vertex_offset:Int):Void;

	public function drawIndexedVerticesInstanced(instanceCount:Int):Void;

	public function drawIndexedVerticesInstancedFromTo(instanceCount:Int, start:Int, count:Int):Void;

	public function viewport(x:Int, y:Int, width:Int, height:Int):Void;

	public function scissor(x:Int, y:Int, width:Int, height:Int):Void;

	public function disableScissor():Void;

	public inline function setPipeline(pipeline:Pipeline):Void {
		__setPipeline(@:privateAccess pipeline._handle);
	}

	@:hlNative("kinc", "hl_g5_command_list_set_pipeline")
	private function __setPipeline(pipeline:hl.Abstract<"g5_pipeline">):Void;

	public function setVertexBuffers(buffers:hl.NativeArray<VertexBuffer>, offsets:hl.Bytes):Void;

	public function setIndexBuffer(buffer:IndexBuffer):Void;

	public function setRenderTargets(targets:hl.NativeArray<RenderTarget>):Void;

	public function uploadIndexBuffer(buffer:IndexBuffer):Void;

	public function uploadVertexBuffer(buffer:VertexBuffer):Void;

	public function uploadTexture(texture:Texture):Void;

	public function setVertexConstantBuffer(buffer:ConstantBuffer, offset:Int, size:Int):Void;

	public function setFragmentConstantBuffer(buffer:ConstantBuffer, offset:Int, size:Int):Void;

	public function setPipelineLayout():Void;

	public function execute():Void;

	public function executeAndWait():Void;

	// public function getRenderTargetPixels(target:RenderTarget, buffer:hl.Bytes):Void;

	// public function compute(x:Int, y:Int, z:Int):Void;

	// public function setTexture(unit:TextureUnit, texture:Texture):Void;

	// public function setRenderTargetFace(target:RenderTarget, face:Int):Void;

	// public function setTextureAddressing(unit:TextureUnit, addressing:TextureAddressing):Void;
}
