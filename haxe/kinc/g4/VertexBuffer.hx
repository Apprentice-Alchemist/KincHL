package kinc.g4;

import hl.Abstract;

@:build(kinc.Macros.build_struct("vertex_buffer"))
abstract VertexBuffer(hl.Abstract<"kinc_g4_vertex_buffer_t">) to hl.Abstract<"kinc_g4_vertex_buffer_t"> {
    public static function make(count:Int,structure:VertexStructure,usage:Usage,data_step_rate:Int){
        var ret = new VertexBuffer();
        init(ret,count,structure,usage,data_step_rate);
        return ret;
    }
    @:hlNative("kinc","hl_g4_vertex_buffer_init") static function init(buf:hl.Abstract<"kinc_g4_vertex_buffer_t">,count:Int,structure:hl.Abstract<"kinc_g4_vertex_structure_t">,usage:Int,data_step_rate:Int):Void {}
    @:hlNative("kinc","hl_g4_vertex_buffer_lock_all") public function lock_all():kinc.util.NativeArray<hl.F32,"single"> {return null;} 
    @:hlNative("kinc","hl_g4_vertex_buffer_unlock_all") public function unlock_all():Void {}
    @:hlNative("kinc","hl_g4_vertex_buffer_count") public function count():Int return 0;
    @:hlNative("kinc","hl_g4_vertex_buffer_stride") public function stride():Int return 0;
}

enum abstract Usage(Int) to Int{
	var STATIC;
	var DYNAMIC;
	var READABLE;
}
