package kinc.math;

@:hlNative("kinc","hl_matrix3x3_")
abstract Matrix3(hl.Abstract<"kinc_matrix3x3_t">) to hl.Abstract<"kinc_matrix3x3_t"> {
    public static function alloc():Matrix3 {return null;};
    public function get(x:Int,y:Int):hl.F32 return 0;
    public function set(x:Int,y:Int,v:hl.F32):Void {}
    public static function rotation_z(alpha:hl.F32):Matrix3 {return null;};
}