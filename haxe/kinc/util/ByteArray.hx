package kinc.util;

import haxe.extern.EitherType;

@:using(kinc.util.ByteArray)
class ByteArray {
	public var bytes(default, null):hl.Bytes;
	public var length(default, null):Int;

	public function new(length:Int, ?bytes:hl.Bytes) {
		this.length = length;
		this.bytes = bytes == null ? new hl.Bytes(length) : bytes;
	}

	@:hlNative("kinc", "bytearray_geti16") public static function getInt16(b:ByteArray,pos:Int):Int
		return 0;
}
