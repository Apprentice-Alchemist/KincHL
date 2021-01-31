package kinc.g4;

import hl.Abstract;

@:build(kinc.Macros.build_struct("g4_vertex_buffer", true))
@:hlNative("kinc", "hl_g4_vertex_buffer_")
abstract VertexBuffer(hl.Abstract<"g4_vertex_buffer">) {
	public function new(count:Int, structure:VertexStructure, usage:Usage, data_step_rate:Int) {
		this = alloc();
		init(count, structure, usage, data_step_rate);
	}

	private function init(count:Int, structure:VertexStructure, usage:Int, data_step_rate:Int):Void;

	public function lock(start:Int, count:Int):hl.BytesAccess<hl.F32>;

	public function lockAll():hl.BytesAccess<hl.F32>;

	public function unlock(count:Int):Void;

	public function unlockAll():Void;

	public function count():Int;

	public function stride():Int;
}

enum abstract Usage(Int) to Int {
	var StaticUsage;
	var DynamicUsage;
	var ReadableUsage;
}
