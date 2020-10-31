package kinc.g4;

@:build(kinc.Macros.build_struct("shader"))
abstract Shader(hl.Abstract<"kinc_g4_shader_t">) from hl.Abstract<"kinc_g4_shader_t"> to hl.Abstract<"kinc_g4_shader_t"> {
    public static function fromFile(file:String,type:ShaderType):Shader{
        var ret = new Shader();
        ret.initFromFile(file,type);
        return ret;
    }
    public static function create(b:haxe.io.Bytes,type:ShaderType){
        var ret = new Shader();
        ret.init(b.toString(),type);
        return ret;
    }
    public function init(b:String,type:ShaderType){
		_init(@:privateAccess b.toUtf8(), type);
    }
        

    public function initFromString(s:String, type:ShaderType)
        init_from_source(@:privateAccess s.toUtf8(), type);
    
    @:hlNative("kinc", "hl_g4_shader_init_from_source") function init_from_source(b:hl.Bytes, type:Int):Void {};
    @:hlNative("kinc","hl_g4_shader_init") function _init(b:hl.Bytes,type:ShaderType):Void {}
    @:hlNative("kinc","hl_g4_shader_init_from_file") public function initFromFile(file:String,type:ShaderType):Void{};
}

enum abstract ShaderType(Int) to Int {
	var FRAGMENT;
	var VERTEX;
	var GEOMETRY;
	var TESSELLATION_CONTROL;
	var TESSELATION_EVALUATION;
}
