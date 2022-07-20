package kinc.g5;

enum abstract RenderTargetFormat(Int) {
	var RenderTargetFormat32Bit;
	var RenderTargetFormat64BitFloat;
	var RenderTargetFromat32BitRedFloat;
	var RenderTargetFroamt128BitFloat;
	var RenderTrgetFromat16BitDepth;
	var RenderTargetFormat8BitRed;
	var RenderTargetFormat16BitRedFloat;
}

@:build(kinc.Macros.build_struct("g5_render_target", true))
@:hlNative("kinc", "hl_g5_render_target")
abstract RenderTarget(hl.Abstract<"g5_render_target">) {
	public static function create(width:Int, height:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int,
			contextId:Int):RenderTarget {
		final rt:RenderTarget = alloc();
		rt.init(width, height, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
		return rt;
	}

	public static function createCube(cubeMapSize:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int,
			contextId:Int):RenderTarget {
		final rt:RenderTarget = alloc();
		rt.initCube(cubeMapSize, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
		return rt;
	}

	function init(width:Int, height:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int, contextId:Int):Void;

	function initCube(cubeMapSize:Int, depthBufferBits:Int, antialiasing:Bool, format:RenderTargetFormat, stencilBufferBits:Int, contextId:Int):Void;

	public function useColorAsTexture(unit:TextureUnit):Void;
	public function useDepthAsTexture(unit:TextureUnit):Void;
	public function setDepthStencilFrom(source:RenderTarget):Void;
}
