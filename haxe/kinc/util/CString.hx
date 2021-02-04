package kinc.util;

abstract CString(hl.Bytes) {
    @:to function toString():String {
        return @:privateAccess String.fromUTF8(this);
    }

    @:from static function fromString(s:String) {
        return cast @:privateAccess s.toUtf8();
    }
}