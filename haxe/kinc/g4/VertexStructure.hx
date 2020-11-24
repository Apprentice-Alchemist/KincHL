package kinc.g4;

@:build(kinc.Macros.build_struct("vertex_structure", true))
abstract VertexStructure(hl.Abstract<"kinc_g4_vertex_structure_t">) to hl.Abstract<"kinc_g4_vertex_structure_t"> {
	public function new() {
		this = alloc();
		init();
	}

	@:default_value(0)
	public var size(get, set):Int;
	@:hlNative("kinc", "hl_g4_vertex_structure_add") public function add(name:String, d:VertexData):Void {}
	@:hlNative("kinc", "vertex_structure_hl_init") function init():Void {}
}

enum abstract VertexData(Int) {
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
