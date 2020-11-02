package kinc.g4;

import hl.Abstract;

@:build(kinc.Macros.build_struct("vertex_buffer",true))
@:hlNative("kinc","hl_g4_vertex_buffer_")
abstract VertexBuffer(hl.Abstract<"kinc_g4_vertex_buffer_t">) to hl.Abstract<"kinc_g4_vertex_buffer_t"> {
    public function new(count:Int,structure:VertexStructure,usage:Usage,data_step_rate:Int){
        this = alloc();
        init(count,structure,usage,data_step_rate);
    }
    private function init(count:Int,structure:hl.Abstract<"kinc_g4_vertex_structure_t">,usage:Int,data_step_rate:Int):Void {}
    public function lock(start:Int,count:Int):kinc.util.NativeArray<hl.F32,"single"> return null;
    public function lockAll():kinc.util.NativeArray<hl.F32,"single"> return null;
    public function unlock(start:Int,count:Int):Void {}
    public function unlockAll():Void {}
    public function count():Int return 0;
    public function stride():Int return 0;
}

enum abstract Usage(Int) to Int{
	var STATIC;
	var DYNAMIC;
	var READABLE;
}
