package kinc;

import hl.I64;
import kinc.Window;

@:hlNative("kinc", "hl_")
extern class System {
	static function init(name:String, width:Int, height:Int, win:WindowOptions = null, fb:FramebufferOptions = null):Int;
	static function start():Void;
	static function stop():Void;
	static function log(level:LogLevel, msg:String):Void;
	static function applicationName():String;
	static function setApplicationName(name:String):Void;
	static function width():Int;
	static function height():Int;
	static function loadUrl(url:String):Void;
	static function systemId():String;
	static function videoFormats():hl.NativeArray<String>;
	static function language():String;
	static function vibrate(milliseconds:Int):Void;
	static function safeZone():hl.F32;
	static function setSafeZone(value:hl.F32):Void;
	static function frequency():Float;
	static function timestamp():hl.I64;
	static function time():Float;
	static function login():Void;
	static function waitingForLogin():Bool;
	static function unlockAchievement(id:Int):Void;
	static function allowUserChange():Void;
	static function disallowUserChange():Void;
	static function setKeepScreenOn(on:Bool):Void;

	static function setUpdateCallback(cb:Void->Void):Void;
	static function setForegroundCallback(cb:Void->Void):Void;
	static function setResumeCallback(cb:Void->Void):Void;
	static function setPauseCallback(cb:Void->Void):Void;
	static function setBackgroundCallback(cb:Void->Void):Void;
	static function setShutdownCallback(cb:Void->Void):Void;
	static function setDropFilesCallback(cb:String->Void):Void;
	static function setCutCallback(cb:Void->String):Void;
	static function setCopyCallback(cb:Void->String):Void;
	static function setPasteCallback(cb:String->Void):Void;
	static function setLoginCallback(cb:Void->Void):Void;
	static function setLogoutCallback(cb:Void->Void):Void;

	static function getGraphicsApi():GraphicsApi;
}

enum abstract LogLevel(Int) from Int {
	var LOG_LEVEL_INFO;
	var LOG_LEVEL_WARNING;
	var LOG_LEVEL_ERROR;
}

enum abstract GraphicsApi(Int) {
	var D3D9;
	var D3D11;
	var D3D12;
	var OpenGL;
	var Metal;
	var Vulkan;
}
