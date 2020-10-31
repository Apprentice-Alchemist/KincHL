package kinc;

@:hlNative("kinc","hl_")
extern class Callbacks {
    public static function set_update_callback(cb:Void->Void):Void;
    public static function set_drop_file_callback(cb:String->Void):Void;
    public static function set_cut_callback(cb:Void->String):Void;
    public static function set_paste_callback(cb:String->Void):Void;
}