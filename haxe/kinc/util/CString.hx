package kinc.util;

abstract CString(hl.Bytes) {
	@:to public function toString():String {
		return @:privateAccess String.fromUTF8(this);
	}

	@:from public static function fromString(s:String) {
		return cast @:privateAccess s.toUtf8();
	}
}
