package kinc.g4;

@:hlNative("kinc", "hl_g4_")
extern class Graphics4 {
	static function begin(index:Int):Void;
	static function clear(f:Int, c:Int, d:hl.F32, s:hl.F32):Void;
	static function end(index:Int):Void;
	static function flush():Void;
	static function swapBuffers():Bool;
	static function setPipeline(state:Pipeline):Void;
	static function setVertexBuffer(buf:VertexBuffer):Void;
	static inline function setVertexBuffers(buffers:Array<VertexBuffer>):Void {
		__set_vertex_buffers(buffers, buffers.length);
	};
	@:hlNative("kinc",
		"hl_g4_set_vertex_buffers") private static function __set_vertex_buffers(buffers:kinc.util.NativeArray<hl.Abstract<"kinc_g4_vertex_buffer_t">,
		"vertex_buffer">, count:Int):Void;
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
	static function setRenderTargets(arr:kinc.util.NativeArray<RenderTarget, "render_target">, count:Int):Void;
	static function setRenderTargetFace(target:RenderTarget, face:Int):Void;
	static function setTexture(unit:TextureUnit, tex:Texture):Void;
	static function setImageTexture(unit:TextureUnit, tex:Texture):Void;
	static function initOcclusionQuery(q:hl.Ref<Int>):Bool;
	static function deleteOcclusionQuery(q:Int):Void;
	static function startOcclusionQuery(q:Int):Void;
	static function endOcclusionQuery(q:Int):Void;
	static function areQueryResultsAvailable(q:Int):Bool;
	static function getQueryResults(q:Int, pixelCount:hl.Ref<Int>):Void;
	// static function setTextureArray(unit:TextureUnit, array:TextureArray):Void;
	static function antialiasingSamples():Int;
	static function setAntialiasingSamples(samles:Int):Void;

	static function setInt(location:ConstantLocation, i:Int):Void;
	static function setInt2(location:ConstantLocation, i:Int, i2:Int):Void;
	static function setInt3(location:ConstantLocation, i:Int, i2:Int, i3:Int):Void;
	static function setInt4(location:ConstantLocation, i:Int, i2:Int, i3:Int, i4:Int):Void;
	static function setInts(location:ConstantLocation, i:kinc.util.NativeArray<Int, "int">, count:Int):Void;
	static function setFloat(location:ConstantLocation, i:hl.F32):Void;
	static function setFloat2(location:ConstantLocation, i:hl.F32, i2:hl.F32):Void;
	static function setFloat3(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32):Void;
	static function setFloat4(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32, i4:hl.F32):Void;
	static function setFloats(location:ConstantLocation, i:kinc.util.NativeArray<hl.F32, "single">, count:Int):Void;
	static function setBool(location:ConstantLocation, b:Bool):Void;
	static function setMatrix3(location:ConstantLocation, m:hl.Abstract<"kinc_matrix3x3_t">):Void;
	static function setMatrix4(location:ConstantLocation, m:hl.Abstract<"kinc_matrix4x4_t">):Void;
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
