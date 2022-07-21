package kinc.g5;

@:hlNative("kinc","hl_g5_")
extern class Graphics5 {
	static function fullscreen():Bool;
	static function begin(renderTarget:RenderTarget, window:Int):Void;
	/**
		probably does nothing
	**/
	static function flush():Void;
	static function end(window:Int):Void;
	static function swapBuffers():Void;
	static function maxBoundTextures():Int;
	static function nonPow2TexturesSupported():Bool;
	static function renderTargetsInvertedY():Bool;
	static function antialiasingSamples():Int;
	static function setAntialiasingSamples(samples:Int):Void;
}