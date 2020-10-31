package kinc.g4;

@:build(kinc.Macros.build_struct("vertex_structure"))
abstract VertexStructure(hl.Abstract<"kinc_g4_vertex_structure_t">) to hl.Abstract<"kinc_g4_vertex_structure_t">{
	@:default_value(0)
	public var size(get,set):Int;
    @:hlNative("kinc","hl_g4_vertex_structure_add") public function add(name:String,d:VertexData):Void {}
}
enum abstract VertexData(Int) {
	var NONE;
	var FLOAT1;
	var FLOAT2;
	var FLOAT3;
	var FLOAT4;
	var FLOAT4X4;
	var SHORT2_NORM;
	var SHORT4_NORM;
	var COLOR;
}