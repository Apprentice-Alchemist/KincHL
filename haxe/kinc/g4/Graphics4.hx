package kinc.g4;

import kinc.math.Matrix4;
import kinc.math.Matrix3;

enum abstract ClearMode(Int) {
	var Color = 1;
	var Depth = 2;
	var Stencil = 4;

	@:op(A | B) static function and(a:ClearMode, b:ClearMode):ClearMode;
}

@:hlNative("kinc", "hl_g4_")
extern class Graphics4 {
	static function begin(index:Int):Void;
	static function clear(flags:ClearMode, color:Int, depth:hl.F32, stencil:Int):Void;
	static function end(index:Int):Void;
	static function flush():Void;
	static function swapBuffers():Bool;
	static inline function setPipeline(state:Pipeline):Void
		__setPipeline(@:privateAccess state._handle);
	@:hlNative("kinc", "hl_g4_set_pipeline") private static function __setPipeline(state:hl.Abstract<"g4_pipeline">):Void;
	static function setVertexBuffer(buf:VertexBuffer):Void;
	static function setVertexBuffers(buffers:hl.NativeArray<VertexBuffer>):Void;
	static function setIndexBuffer(buf:IndexBuffer):Void;
	static function drawIndexedVertices():Void;
	static function viewport(x:Int, y:Int, w:Int, h:Int):Void;
	static function scissor(x:Int, y:Int, w:Int, h:Int):Void;
	static function disableScissor():Void;
	static function drawIndexedVerticesFromTo(start:Int, count:Int):Void;
	static function drawIndexedVerticesFromToFrom(start:Int, count:Int, vertex_offset:Int):Void;
	static function drawIndexedVerticesInstanced(instanceCount:Int):Void;
	static function drawIndexedVerticesInstancedFromTo(instanceCount:Int, start:Int, count:Int):Void;
	static function setTextureAddressing(unit:TextureUnit, dir:TextureDirection, addressing:TextureAdressing):Void;
	static function setTexture3dAddressing(unit:TextureUnit, dir:TextureDirection, addressing:TextureAdressing):Void;
	static function renderTargetsInvertedY():Bool;
	static function nonPow2TexturesSupported():Bool;
	static function restoreRenderTarget():Void;
	static function setRenderTargets(arr:hl.NativeArray<RenderTarget>):Void;
	static function setRenderTargetFace(target:RenderTarget, face:Int):Void;
	static function setTexture(unit:TextureUnit, tex:Texture):Void;
	static function setImageTexture(unit:TextureUnit, tex:Texture):Void;

	static function setTextureArray(unit:TextureUnit, array:TextureArray):Void;
	static function antialiasingSamples():Int;
	static function setAntialiasingSamples(samles:Int):Void;

	static function setInt(location:ConstantLocation, i:Int):Void;
	static function setInt2(location:ConstantLocation, i:Int, i2:Int):Void;
	static function setInt3(location:ConstantLocation, i:Int, i2:Int, i3:Int):Void;
	static function setInt4(location:ConstantLocation, i:Int, i2:Int, i3:Int, i4:Int):Void;
	public static inline function setInts(location:ConstantLocation, arr:Array<Int>):Void {
		__setInts(location, hl.Bytes.getArray(arr), arr.length);
	}
	@:hlNative("kinc", "hl_g4_set_ints") private static function __setInts(location:ConstantLocation, i:hl.Bytes, count:Int):Void;
	static function setFloat(location:ConstantLocation, i:hl.F32):Void;
	static function setFloat2(location:ConstantLocation, i:hl.F32, i2:hl.F32):Void;
	static function setFloat3(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32):Void;
	static function setFloat4(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32, i4:hl.F32):Void;
	public static inline function setFloats(location:ConstantLocation, arr:Array<hl.F32>):Void {
		__setFloats(location, hl.Bytes.getArray(arr), arr.length);
	}
	@:hlNative("kinc", "hl_g4_set_floats") private static function __setFloats(location:ConstantLocation, i:hl.Bytes, count:Int):Void;
	static function setBool(location:ConstantLocation, b:Bool):Void;
	static function setMatrix3(location:ConstantLocation, m:Matrix3):Void;
	static function setMatrix4(location:ConstantLocation, m:Matrix4):Void;
	static function setTextureMagnificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	static function setTexture3dMagnificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	static function setTextureMinificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	static function setTexture3dMinificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	static function setTextureMipmapFilter(unit:TextureUnit, f:MimapFilter):Void;
	static function setTexture3dMipmapFilter(unit:TextureUnit, f:MimapFilter):Void;
	static function setTextureCompareMode(unit:TextureUnit, b:Bool):Void;
	static function setCubemapCompareMode(unit:TextureUnit, b:Bool):Void;
}

enum abstract TextureAdressing(Int) {
	var REPEAT;
	var MIRROR;
	var CLAMP;
	var BORDER;
}

enum abstract TextureDirection(Int) {
	var DirectionU;
	var DirectionV;
	var DirectionW;
}

enum abstract TextureOperation(Int) {
	var MODULATE;
	var SELECT_FIRST;
	var SELECT_SECOND;
}

enum abstract TextureArgument(Int) {
	var CURRENT_COLOR;
	var TEXTURE_COLOR;
}

enum abstract TextureFilter(Int) {
	var POINT;
	var LINEAR;
	var ANISOTROPIC;
}

enum abstract MimapFilter(Int) {
	var NONE;
	var POINT;
	var LINEAR;
}
