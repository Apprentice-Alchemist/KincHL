package kinc.input;

@:hlNative("kinc")
extern class Sensor {
	static function setAccelerationCallback(cb:(x:hl.F32, y:hl.F32, z:hl.F32) -> Void):Void;
	static function setRotationCallback(cb:(x:hl.F32, y:hl.F32, z:hl.F32) -> Void):Void;
}
