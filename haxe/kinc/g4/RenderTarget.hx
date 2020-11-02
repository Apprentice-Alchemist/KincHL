package kinc.g4;

@:build(kinc.Macros.build_struct("render_target"))
@:hlNative("kinc", "hl_g4_render_target_")
abstract RenderTarget(hl.Abstract<"kinc_g4_render_target_t">) to hl.Abstract<"kinc_g4_render_target_t"> {
	public var width(get, set):Int;
	public var height(get, set):Int;
	public var texWidth(get, set):Int;
	public var texHeight(get, set):Int;
	public var contextId(get, set):Int;
	public var isCubeMap(get, set):Bool;
	public var isDepthAttachment(get, set):Bool;

	public function init(width:Int, height:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int,
		contextId:Int):Void {}
	public function init_cube(cubeMapSize:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int, contextId:Int):Void {}
	public function useColorAsTexture(unit:TextureUnit):Void {}
	public function useDepthAsTexture(unit:TextureUnit):Void {}
	public function setDepthStencilFrom(source:RenderTarget):Void {}
	public function getPixels(data:hl.Bytes):Void {}
	public function generateMipmaps(levels:Int):Void {}
}

enum abstract RenderTargetFormat(Int) to Int {
	var FORMAT_32BIT;
	var FORMAT_64BIT_FLOAT;
	var FORMAT_32BIT_RED_FLOAT;
	var FORMAT_128BIT_FLOAT;
	var FORMAT_16BIT_DEPTH;
	var FORMAT_8BIT_RED;
	var FORMAT_16BIT_RED_FLOAT;
}
