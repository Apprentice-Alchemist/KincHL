package kinc.g5;

enum abstract RenderTargetFormat(Int) {
	var RenderTargetFormat32Bit = 0;
	var RenderTargetFormat64BitFloat;
	var RenderTargetFromat32BitRedFloat;
	var RenderTargetFroamt128BitFloat;
	var RenderTrgetFromat16BitDepth;
	var RenderTargetFormat8BitRed;
	var RenderTargetFormat16BitRedFloat;
}

@:build(kinc.Macros.build_struct("g5_render_target", true))
@:hlNative("kinc", "hl_g5_render_target_")
abstract RenderTarget(hl.Abstract<"g5_render_target">) {
	public var width(get, set):Int;
	public var height(get, set):Int;
	public var texWidth(get, set):Int;
	public var texHeight(get, set):Int;
	public var framebuffer_index(get, set):Int;
	public var isCubeMap(get, never):Bool;
	public var isDepthAttachment(get, never):Bool;

	public static function create(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.init(width, height, format, depthBufferBits, stencilBufferBits);
		return rt;
	}

	public static function createWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
			samplesPerPixel:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.initWithMultisampling(width, height, format, depthBufferBits, stencilBufferBits, samplesPerPixel);
		return rt;
	}

	public static function createFramebuffer(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.initFramebuffer(width, height, format, depthBufferBits, stencilBufferBits);
		return rt;
	}

	public static function createFramebufferWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
			samplesPerPixel:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.initFramebufferWithMultisampling(width, height, format, depthBufferBits, stencilBufferBits, samplesPerPixel);
		return rt;
	}

	public static function createCube(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.initCube(cubeMapSize, format, depthBufferBits, stencilBufferBits);
		return rt;
	}

	public static function createCubeWithMultisampling(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
			samplesPerPixel:Int):RenderTarget {
		final rt = new RenderTarget();
		rt.initCubeWithMultisampling(cubeMapSize, format, depthBufferBits, stencilBufferBits, samplesPerPixel);
		return rt;
	}

	private function new() {
		this = alloc();
	}

	function init(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):Void;

	function initWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int, samplesPerPixel:Int):Void;

	function initFramebuffer(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):Void;

	function initFramebufferWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
		samplesPerPixel:Int):Void;

	function initCube(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):Void;

	function initCubeWithMultisampling(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int, samplesPerPixel:Int):Void;

	public function useColorAsTexture(unit:TextureUnit):Void;

	public function useDepthAsTexture(unit:TextureUnit):Void;

	public function setDepthStencilFrom(source:RenderTarget):Void;
}
