package kinc.g5;

import kinc.Image.ImageFormat;

@:build(kinc.Macros.build_struct("g5_texture", true))
@:hlNative("kinc", "hl_g5_texture_")
abstract Texture(hl.Abstract<"g5_texture">) {
	public var texWidth(get, set):Int;
	public var texHeight(get, set):Int;
	public var format(get, set):ImageFormat;

	public static function create(width:Int, height:Int, format:ImageFormat):Texture {
		var self:Texture = alloc();
		self.init(width, height, format);
		return self;
	}

	public static function create3d(width:Int, height:Int, depth:Int, format:ImageFormat):Texture {
		var self:Texture = alloc();
		self.init3d(width, height, depth, format);
		return self;
	}

	public static function createFromImage(image:Image):Texture {
		var self:Texture = alloc();
		self.initFromImage(image);
		return self;
	}

	public static function createNonSampledAccess(width:Int, height:Int, format:ImageFormat):Texture {
		var self:Texture = alloc();
		self.initNonSampledAccess(width, height, format);
		return self;
	}

	function init(width:Int, height:Int, format:ImageFormat):Void;

	function init3d(width:Int, height:Int, depth:Int, format:ImageFormat):Void;

	function initFromImage(image:Image):Void;

	function initNonSampledAccess(width:Int, height:Int, format:ImageFormat):Void;

	public function lock():hl.Bytes;

	public function unlock():Void;

	public function clear(x:Int, y:Int, z:Int, width:Int, height:Int, depth:Int, color:Int):Void;

	public function generateMipmaps(levels:Int):Void;

	public function setMipmap(mipmap:Image, level:Int):Void;

	public function stride():Int;
}
