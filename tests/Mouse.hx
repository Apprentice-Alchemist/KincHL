import kinc.g4.Graphics4;
import kinc.Callbacks;

class Mouse {
	static var delta:Int = 0;

	public static function main() {
		Kinc.init("Shader", 500, 500, null, null);
		Callbacks.set_update_callback(update);
		kinc.input.Mouse.setScrollCallback((window, d) -> {
            delta += (d * 10);
            trace(delta);
        });
        kinc.input.Mouse.setPressCallback((window, button, x, y) -> {
            trace(button);
        });
		Kinc.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(1, delta,0, 0);
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}