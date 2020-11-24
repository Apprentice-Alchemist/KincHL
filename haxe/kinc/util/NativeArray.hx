package kinc.util;

@:forward
abstract NativeArray<T>(hl.NativeArray<T>) from hl.NativeArray<T> to hl.NativeArray<T> {
	@:from public static function fromArray<T>(arr:Array<T>):NativeArray<T> {
		var ret = new hl.NativeArray<T>(arr.length);
		for (i in 0...arr.length)
			ret[i] = arr[i];
		return ret;
	}

	@:arrayAccess inline function arrGet(index:Int)
		return this[index];

	@:arrayAccess inline function arrSet(index:Int, val:T)
		return this[index] = val;
}
