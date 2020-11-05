package kinc.audio2;

@:hlNative("kinc","a2_")
extern class Audio {
    static function init():Void;
    @:hlNative("kinc","hl_a2_set_callback") static function setCallback(cb:(buffer:Buffer,samples:Int)->Void):Void;
    static function update():Void;
    static function shutdown():Void;
    static var samples_per_second(get,set):Int;
    private static function get_samples_per_second():Int;
    private static function set_samples_per_second(v:Int):Int;
}