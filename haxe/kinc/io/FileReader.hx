package kinc.io;

import kinc.util.CString;

enum abstract FileType(Int) {
    var AssetFile = 0;
    var SaveFile = 1;
}

@:build(kinc.Macros.build_struct("file_reader",false,false,true))
@:hlNative("kinc","hl_file_reader_")
abstract FileReader(hl.Abstract<"file_reader">) {
    public function open(path:CString,type:FileType):Bool;
    public function read(data:hl.Bytes,size:Int):Int;
    public function size():Int;
    public function pos():Int;
    public function seek(pos:Int):Void;
    public function close():Void;
}

