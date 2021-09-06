package kinc.io;

import kinc.util.CString;

@:build(kinc.Macros.build_struct("file_writer", false, false, true))
@:hlNative("kinc", "hl_file_writer_")
abstract FileWriter(hl.Abstract<"file_writer">) {
	/**
	 * Writes files in the platform dependent save directory.
	 * @param path 
	 * @return Bool
	 */
	public function open(path:CString):Bool;

	public function write(data:hl.Bytes, size:Int):Void;

	public function close():Void;
}
