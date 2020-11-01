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

	public static function setInt(location:ConstantLocation, i:Int):Void;
	public static function setInt2(location:ConstantLocation, i:Int, i2:Int):Void;
	public static function setInt3(location:ConstantLocation, i:Int, i2:Int, i3:Int):Void;
	public static function setInt4(location:ConstantLocation, i:Int, i2:Int, i3:Int, i4:Int):Void;
	public static function setInts(location:ConstantLocation, i:kinc.util.NativeArray<Int, "int">):Void;
	public static function setFloat(location:ConstantLocation, i:hl.F32):Void;
	public static function setFloat2(location:ConstantLocation, i:hl.F32, i2:hl.F32):Void;
	public static function setFloat3(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32):Void;
	public static function setFloat4(location:ConstantLocation, i:hl.F32, i2:hl.F32, i3:hl.F32, i4:hl.F32):Void;
	public static function setFloats(location:ConstantLocation, i:kinc.util.NativeArray<hl.F32, "single">):Void;
	public static function setBool(location:ConstantLocation, b:Bool):Void;
	public static function setMatrix3(location:ConstantLocation, m:hl.Abstract<"kinc_matrix3x3_t">):Void;
	public static function setMatrix4(location:ConstantLocation, m:hl.Abstract<"kinc_matrix4x4_t">):Void;
	public static function setTextureMagnificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	public static function setTexture3dMagnificationFilter(unit:TextureUnit, f:TextureFilter):Void;
	public static function setTextureMinifcationFilter(unit:TextureUnit, f:TextureFilter):Void;
	public static function setTexture3dMinificationFilter(f:TextureFilter):Void;
	public static function setTextureMipmapFilter(unit:TextureUnit, f:MimapFilter):Void;
	public static function setTexture3dMipmapFilter(unit:TextureUnit, f:MimapFilter):Void;
	public static function setTextureCompareMode(unit:TextureUnit, b:Bool):Void;
	public static function setCubemapCompareMode(unit:TextureUnit, b:Bool):Void;
}

enum abstract TextureAdressing(Int) {
	var REPEAT;
	var MIRROR;
	var CLAMP;
	var BORDER;
}

enum abstract TextureDirection(Int) {
	var U;
	var V;
	var W;
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
