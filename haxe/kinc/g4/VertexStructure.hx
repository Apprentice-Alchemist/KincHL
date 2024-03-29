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
	var KINC_G4_VERTEX_DATA_NONE = 0;
	var KINC_G4_VERTEX_DATA_F32_1X = 1;
	var KINC_G4_VERTEX_DATA_F32_2X = 2;
	var KINC_G4_VERTEX_DATA_F32_3X = 3;
	var KINC_G4_VERTEX_DATA_F32_4X = 4;
	var KINC_G4_VERTEX_DATA_F32_4X4 = 5;
	var KINC_G4_VERTEX_DATA_I8_1X = 6;
	var KINC_G4_VERTEX_DATA_U8_1X = 7;
	var KINC_G4_VERTEX_DATA_I8_1X_NORMALIZED = 8;
	var KINC_G4_VERTEX_DATA_U8_1X_NORMALIZED = 9;
	var KINC_G4_VERTEX_DATA_I8_2X = 10;
	var KINC_G4_VERTEX_DATA_U8_2X = 11;
	var KINC_G4_VERTEX_DATA_I8_2X_NORMALIZED = 12;
	var KINC_G4_VERTEX_DATA_U8_2X_NORMALIZED = 13;
	var KINC_G4_VERTEX_DATA_I8_4X = 14;
	var KINC_G4_VERTEX_DATA_U8_4X = 15;
	var KINC_G4_VERTEX_DATA_I8_4X_NORMALIZED = 16;
	var KINC_G4_VERTEX_DATA_U8_4X_NORMALIZED = 17;
	var KINC_G4_VERTEX_DATA_I16_1X = 18;
	var KINC_G4_VERTEX_DATA_U16_1X = 19;
	var KINC_G4_VERTEX_DATA_I16_1X_NORMALIZED = 20;
	var KINC_G4_VERTEX_DATA_U16_1X_NORMALIZED = 21;
	var KINC_G4_VERTEX_DATA_I16_2X = 22;
	var KINC_G4_VERTEX_DATA_U16_2X = 23;
	var KINC_G4_VERTEX_DATA_I16_2X_NORMALIZED = 24;
	var KINC_G4_VERTEX_DATA_U16_2X_NORMALIZED = 25;
	var KINC_G4_VERTEX_DATA_I16_4X = 26;
	var KINC_G4_VERTEX_DATA_U16_4X = 27;
	var KINC_G4_VERTEX_DATA_I16_4X_NORMALIZED = 28;
	var KINC_G4_VERTEX_DATA_U16_4X_NORMALIZED = 29;
	var KINC_G4_VERTEX_DATA_I32_1X = 30;
	var KINC_G4_VERTEX_DATA_U32_1X = 31;
	var KINC_G4_VERTEX_DATA_I32_2X = 32;
	var KINC_G4_VERTEX_DATA_U32_2X = 33;
	var KINC_G4_VERTEX_DATA_I32_3X = 34;
	var KINC_G4_VERTEX_DATA_U32_3X = 35;
	var KINC_G4_VERTEX_DATA_I32_4X = 36;
	var KINC_G4_VERTEX_DATA_U32_4X = 37;

	inline function size() {
		switch (cast this : VertexData) {
			case KINC_G4_VERTEX_DATA_NONE:
				return 0;
			case KINC_G4_VERTEX_DATA_F32_1X:
				return 1 * 4;
			case KINC_G4_VERTEX_DATA_F32_2X:
				return 2 * 4;
			case KINC_G4_VERTEX_DATA_F32_3X:
				return 3 * 4;
			case KINC_G4_VERTEX_DATA_F32_4X:
				return 4 * 4;
			case KINC_G4_VERTEX_DATA_F32_4X4:
				return 4 * 4 * 4;
			case KINC_G4_VERTEX_DATA_I8_1X, KINC_G4_VERTEX_DATA_U8_1X, KINC_G4_VERTEX_DATA_I8_1X_NORMALIZED, KINC_G4_VERTEX_DATA_U8_1X_NORMALIZED:
				return 1 * 1;
			case KINC_G4_VERTEX_DATA_I8_2X, KINC_G4_VERTEX_DATA_U8_2X, KINC_G4_VERTEX_DATA_I8_2X_NORMALIZED, KINC_G4_VERTEX_DATA_U8_2X_NORMALIZED:
				return 2 * 1;
			case KINC_G4_VERTEX_DATA_I8_4X, KINC_G4_VERTEX_DATA_U8_4X, KINC_G4_VERTEX_DATA_I8_4X_NORMALIZED, KINC_G4_VERTEX_DATA_U8_4X_NORMALIZED:
				return 4 * 1;
			case KINC_G4_VERTEX_DATA_I16_1X, KINC_G4_VERTEX_DATA_U16_1X, KINC_G4_VERTEX_DATA_I16_1X_NORMALIZED, KINC_G4_VERTEX_DATA_U16_1X_NORMALIZED:
				return 1 * 2;
			case KINC_G4_VERTEX_DATA_I16_2X, KINC_G4_VERTEX_DATA_U16_2X, KINC_G4_VERTEX_DATA_I16_2X_NORMALIZED, KINC_G4_VERTEX_DATA_U16_2X_NORMALIZED:
				return 2 * 2;
			case KINC_G4_VERTEX_DATA_I16_4X, KINC_G4_VERTEX_DATA_U16_4X, KINC_G4_VERTEX_DATA_I16_4X_NORMALIZED, KINC_G4_VERTEX_DATA_U16_4X_NORMALIZED:
				return 4 * 2;
			case KINC_G4_VERTEX_DATA_I32_1X, KINC_G4_VERTEX_DATA_U32_1X:
				return 1 * 4;
			case KINC_G4_VERTEX_DATA_I32_2X, KINC_G4_VERTEX_DATA_U32_2X:
				return 2 * 4;
			case KINC_G4_VERTEX_DATA_I32_3X, KINC_G4_VERTEX_DATA_U32_3X:
				return 3 * 4;
			case KINC_G4_VERTEX_DATA_I32_4X, KINC_G4_VERTEX_DATA_U32_4X:
				return 4 * 4;
		}
	}
}
