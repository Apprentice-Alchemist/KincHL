package kinc.util;

import haxe.extern.EitherType;

abstract BytesArray<T:EitherType<Int, EitherType<Float, Single>>>(hl.BytesAccess<T>) {
	public inline function new(arr:Array<T>) {
		this = hl.Bytes.getArray(arr);
	}
}
