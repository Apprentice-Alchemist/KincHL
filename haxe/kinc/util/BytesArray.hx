package kinc.util;

abstract BytesArray<T>(hl.BytesAccess<T>) {
	public inline function new(arr:Array<T>) {
		this = hl.Bytes.getArray(arr);
	}
}
