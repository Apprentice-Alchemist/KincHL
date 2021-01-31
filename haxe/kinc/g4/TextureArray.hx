package kinc.g4;

@:build(kinc.Macros.build_struct("g4_texture_array", true))
@:hlNative("kinc", "hl_g4_texture_array_")
abstract TextureArray(hl.Abstract<"g4_texture_array">) {
	public function new(arr:Array<Image>) {
		this = alloc();
		var na = new hl.NativeArray(arr.length);
		for (i in 0...arr.length) {
			na[i] = arr[i];
		}
		init(na);
	}

	function init(arr:hl.NativeArray<Image>):Void;
}
