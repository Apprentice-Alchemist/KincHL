import kinc.g4.Graphics4;
import kinc.System;

class Keyboard {
	static var space_pressed:Bool = false;

	public static function main() {
		System.init("Shader", 500, 500, null, null);
		System.setUpdateCallback(update);
		var ctrl_down = false;
		kinc.input.Keyboard.setKeyDownCallback(function(k) {
			if (k == KEY_SPACE)
				space_pressed = true;
			if (k == KEY_CONTROL)
				ctrl_down = true;
			trace("Key down", k);
		});
		kinc.input.Keyboard.setKeyUpCallback(function(k) {
			if (k == KEY_SPACE)
				space_pressed = false;
			if (k == KEY_CONTROL)
				ctrl_down = false;
			trace("Key up", k);
		});
		kinc.input.Keyboard.setKeyPressCallback(key -> if (!ctrl_down) trace(String.fromCharCode(key)));
		System.setCopyCallback(() -> "Hello World");
		System.setPasteCallback(function(s) {
			trace(Std.string(s));
		});
		System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(Color, space_pressed ? 0x00ff00 : 0xff0000, 0, 0);
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
