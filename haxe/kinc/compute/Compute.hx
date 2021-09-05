package kinc.compute;

import kinc.g4.RenderTarget;
import kinc.g4.Texture;
import kinc.g4.Graphics4;
import kinc.g4.Graphics4.TextureAdressing;
import kinc.g4.Graphics4.TextureDirection;

typedef ComputeConstantLocation = hl.Abstract<"compute_constant_location">;
typedef ComputeTextureUnit = hl.Abstract<"compute_texture_unit">;

enum abstract ComputeAccess(Int) {
	var READ;
	var WRITE;
	var READ_WRITE;
}

@:hlNative("kinc", "hl_compute_")
extern class Compute {
	static function setTexture(unit:ComputeTextureUnit, texture:Texture, access:ComputeAccess):Void;
	static function setRenderTarget(unit:ComputeTextureUnit, target:RenderTarget, access:ComputeAccess):Void;
	static function setSampledTexture(unit:ComputeTextureUnit, texture:Texture):Void;
	static function setSampledRenderTarget(unit:ComputeTextureUnit, target:RenderTarget):Void;
	static function setSampledDepthFromRenderTarget(unit:ComputeTextureUnit, target:RenderTarget):Void;

	static inline function setFloats(location:ComputeConstantLocation, arr:Array<hl.F32>):Void {
		__setFloats(location, hl.Bytes.getArray(arr), arr.length);
	}
	@:hlNative("kinc", "hl_compute_set_floats")
	private static function __setFloats(location:ComputeConstantLocation, i:hl.Bytes, count:Int):Void;
	static function setTextureAddressing(unit:ComputeTextureUnit, dir:TextureDirection, addressing:TextureAdressing):Void;
	static function setTexture3dAddressing(unit:ComputeTextureUnit, dir:TextureDirection, addressing:TextureAdressing):Void;
	static function setTextureMagnificationFilter(unit:ComputeTextureUnit, f:TextureFilter):Void;
	static function setTexture3dMagnificationFilter(unit:ComputeTextureUnit, f:TextureFilter):Void;
	static function setTextureMinificationFilter(unit:ComputeTextureUnit, f:TextureFilter):Void;
	static function setTexture3dMinificationFilter(unit:ComputeTextureUnit, f:TextureFilter):Void;
	static function setTextureMipmapFilter(unit:ComputeTextureUnit, f:MimapFilter):Void;
	static function setTexture3dMipmapFilter(unit:ComputeTextureUnit, f:MimapFilter):Void;
	static function setShader(shader:ComputeShader):Void;
	static function compute(x:Int, y:Int, z:Int):Void;
}
