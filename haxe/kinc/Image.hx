package kinc;

import hl.Bytes;

@:build(kinc.Macros.build_struct("image",true))
abstract Image(hl.Abstract<"kinc_image_t">) to hl.Abstract<"kinc_image_t">{
    public function new(){
		this = alloc();
	}
	public static function fromBytes(b:haxe.io.Bytes,width:Int,height:Int,format:ImageFormat):Image{
		var ret = new Image();
		ret.init(b.getData(),width,height,format);
		return ret;
	}
	public static function fromFile(name:String){
		var ret = new Image();
		ret._fromFile(name);
		return ret;
	}
	@:hlNative("kinc","hl_image_init") function init(mem:Bytes,width:Int,height:Int,format:ImageFormat):hl.I64 {return 0;}
	@:hlNative("kinc","hl_image_init_from_file") function _fromFile(name:String):hl.I64 return 0;
}

enum abstract ImageCompression(Int) {
	var COMPRESSION_NONE;
	var COMPRESSION_DXT5;
	var COMPRESSION_ASTC;
	var COMPRESSION_PVRTC;
}

enum abstract ImageFormat(Int){
	var FORMAT_RGBA32;
	var FORMAT_GREY8;
	var FORMAT_RGB24;
	var FORMAT_RGBA128;
	var FORMAT_RGBA64;
	var FORMAT_A32;
	var FORMAT_BGRA32;
	var FORMAT_A16;
}