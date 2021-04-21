package kinc.g4;

@:build(kinc.Macros.build_struct("g4_vertex_structure", true))
abstract VertexStructure(hl.Abstract<"g4_vertex_structure">) {
	public inline function new() {
		this = alloc();
	}

	public var size(get, set):Int;
	public var instanced(get, set):Bool;

	@:hlNative("kinc", "hl_g4_vertex_structure_add") public function add(name:String, d:VertexData):Void;
}

enum abstract VertexData(Int) from Int to Int {
	var None;
	var Float1;
	var Float2;
	var Float3;
	var Float4;
	var Float4X4;
	var Short2_Norm;
	var Short4_Norm;
	var Color;
}
