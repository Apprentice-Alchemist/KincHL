import kinc.g4.Graphics4;
import kinc.audio1.Sound;
import kinc.audio2.Buffer;
import kinc.audio1.Audio as Audio1;
import kinc.audio2.Audio as Audio2;

class Audio {
	static inline function g(i:hl.UI16):Int
		return i & 0x8000 != 0 ? i - 0x10000 : i;

	static inline function sampleLinear(data:hl.BytesAccess<hl.UI16>, position:Float):Float {
		var pos1:Int = Math.floor(position);
		var pos2:Int = Math.floor(position + 1);
		var sample1:Float = g(data[pos1]) / 32767.0;
		var sample2:Float = g(data[pos2]) / 32767.0;
		var a:Float = position - pos1;
		return sample1 * (1 - a) + sample2 * a;
	}

	static var sound:Sound;
	static var position:Float = 0.0;
	static var volume:Float = 1.0;
	static var pitch:Float = 1.0;

	static function on_audio(buffer:Buffer, samples:Int) {
		for (i in 0...samples) {
			var left = (i % 2) == 0;
			var v = sampleLinear(left ? sound.left : sound.right, position);
			if (!left)
				position += pitch / sound.sample_rate_pos;
			if (position + 1 >= sound.size)
				position = 0;
			buffer.data.setF32(buffer.write_location, v);
			buffer.write_location += 4;
			if (buffer.write_location >= buffer.data_size)
				buffer.write_location = 0;
		}
	}

	static function main() {
		var f = Sys.args()[0];
		if (f == null) {
			Sys.println("Usage : hl out.hl file");
			Sys.exit(0);
		}
		// kinc.System.init("Audio", 500, 500);
		Audio2.init();
		sound = Audio1.createSound(f);
		Audio2.setCallback(on_audio);
		while(true) {}
		// kinc.System.setUpdateCallback(() -> {
		// 	Graphics4.begin(0);
		// 	Audio2.update();
		// 	Graphics4.end(0);
		// 	Graphics4.swapBuffers();
		// });
		// kinc.System.start();
		Audio2.shutdown();
	}
}
