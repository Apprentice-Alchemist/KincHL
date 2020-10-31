package kinc.g4;

@:hlNative("kinc","hl_g4_")
extern class Graphics4 {
    static function begin(index:Int):Void;
    static function clear(f:Int,c:Int,d:hl.F32,s:hl.F32):Void;
    static function end(index:Int):Void;
    static function swapBuffers():Bool;
    static function setPipeline(state:Pipeline):Void;
    static function setVertexBuffer(buf:VertexBuffer):Void;
	static inline function setVertexBuffers(buffers:Array<hl.Abstract<"kinc_g4_vertex_buffer_t">>,count:Int):Void{
        __set_vertex_buffers(buffers,buffers.length);
    };
	@:hlNative("kinc","hl_g4_set_vertex_buffers") private static function __set_vertex_buffers(buffers:kinc.util.NativeArray<hl.Abstract<"kinc_g4_vertex_buffer_t">,"vertex_buffer">, count:Int):Void;
    static function setIndexBuffer(buf:IndexBuffer):Void;
    static function drawIndexedVertices():Void;
}