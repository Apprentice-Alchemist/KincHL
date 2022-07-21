package kinc.g5;

import kinc.g4.VertexStructure;

@:build(kinc.Macros.build_struct("g5_vertex_buffer", true))
@:hlNative("kinc", "hl_g5_vertex_buffer_")
abstract VertexBuffer(hl.Abstract<"g5_vertex_buffer">) {
	public function new(count:Int, structure:VertexStructure, gpuMemory:Bool, instanceDataStepRate:Int):Void {
		this = alloc();
		init(count, structure, gpuMemory, instanceDataStepRate);
	}

	function init(count:Int, structure:VertexStructure, gpuMemory:Bool, instanceDataStepRate:Int):Void;

	public function lockAll():hl.Bytes;

	public function unlockAll():Void;

	public function lock(start:Int, count:Int):hl.Bytes;

	public function unlock(count:Int):Void;

	public function count():Int;

	public function stride():Int;
}
