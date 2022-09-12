package kinc.g4;

@:build(kinc.Macros.build_struct("g4_render_target"))
@:hlNative("kinc", "hl_g4_render_target_")
abstract RenderTarget(hl.Abstract<"g4_render_target">) {
	public var width(get, set):Int;
	public var height(get, set):Int;
	public var texWidth(get, set):Int;
	public var texHeight(get, set):Int;
	// public var contextId(get, set):Int;
	public var isCubeMap(get, set):Bool;
	public var isDepthAttachment(get, set):Bool;

	public static function create(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):RenderTarget {
		var ret = new RenderTarget();
		ret.init(width, height, format, depthBufferBits, stencilBufferBits);
		return ret;
	}

	public static function createWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
			samplesPerPixel:Int):RenderTarget {
		var ret = new RenderTarget();
		ret.initWithMultisampling(width, height, format, depthBufferBits, stencilBufferBits, samplesPerPixel);
		return ret;
	}

	public static function createCube(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):RenderTarget {
		var ret = new RenderTarget();
		ret.initCube(cubeMapSize, format, depthBufferBits, stencilBufferBits);
		return ret;
	}

	public static function createCubeWithMultisampling(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
			samplesPerPixel:Int):RenderTarget {
		var ret = new RenderTarget();
		ret.initCubeWithMultisampling(cubeMapSize, format, depthBufferBits, stencilBufferBits, samplesPerPixel);
		return ret;
	}

	private function init(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):Void;

	private function initWithMultisampling(width:Int, height:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
		samplesPerPixel:Int):Void;

	private function initCube(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int):Void;

	private function initCubeWithMultisampling(cubeMapSize:Int, format:RenderTargetFormat, depthBufferBits:Int, stencilBufferBits:Int,
		samplesPerPixel:Int):Void;

	public function useColorAsTexture(unit:TextureUnit):Void;

	public function useDepthAsTexture(unit:TextureUnit):Void;

	public function setDepthStencilFrom(source:RenderTarget):Void;

	public function getPixels(data:hl.Bytes):Void;

	public function generateMipmaps(levels:Int):Void;
}

enum abstract RenderTargetFormat(Int) from Int to Int {
	var Format32Bit;
	var Format64BitFloat;
	var Format32BitRedFloat;
	var Format128BitFloat;
	var Format16BitDepth;
	var Format8BitRed;
	var Format16BitRedFloat;
}
