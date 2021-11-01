import kinc.g4.Graphics4;

class Mouse {
	static var delta:Int = 0;

	public static function main() {
		kinc.System.init("Shader", 500, 500, null, null);
		kinc.System.setUpdateCallback(update);
		kinc.input.Mouse.setScrollCallback((window, d) -> {
			delta += (d * 10);
			trace(delta);
		});
		kinc.input.Mouse.setPressCallback((window, button, x, y) -> {
			trace(button);
		});
		kinc.System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(Color, delta, 0, 0);
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
