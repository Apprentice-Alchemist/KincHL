import kinc.g4.Graphics4;

class Keyboard {
    static var space_pressed:Bool = false;

	public static function main() {
		Kinc.init("Shader", 500, 500, null, null);
        Kinc.setUpdateCallback(update);
        kinc.input.Keyboard.setKeyDownCallback(function(k){
            if(k == KEY_SPACE) space_pressed = true;
        });
        kinc.input.Keyboard.setKeyUpCallback(function(k){
            if(k == KEY_SPACE) space_pressed = false;
		});
		Kinc.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(1, space_pressed ? 0x00ff00 : 0xff0000, 0, 0);
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}