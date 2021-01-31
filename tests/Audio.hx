// @:eager private typedef Float = hl.F32;
class Audio {
	static var mutex = new sys.thread.Mutex();

	static function getInt16(data:hl.Bytes, position:Int):Int {
		var n = data.getUI16(position);
		if (n >= 0x8000)
			return n - 0x10000;
		return n;
	}

	static function sampleLinear(data:hl.Bytes, position:Float):Float {
		var pos1:Int = Std.int(position);
		var pos2:Int = Std.int(position + 1);
		var sample1:Float = getInt16(data, pos1) / 32767.0;
		var sample2:Float = getInt16(data, pos2) / 32767.0;
		var a:Float = position - pos1;
		return sample1 * (1 - a) + sample2 * a;
	}

	static function main() {
		var path = Sys.getEnv("AGROUND") + "\\data\\core\\music\\title.ogg";
		trace(sys.FileSystem.exists(path));
		var s = kinc.audio1.Sound.create(path);
		kinc.audio2.Audio.init();
		var position:Float = 0.0;
		var volume:Float = 1.0;
		var pitch:Float = 1.0;
		kinc.audio2.Audio.setCallback(function(buf, samples) {
			for (i in 0...samples) {
				final left:Bool = (i % 2) == 0;
				var value:Float = 0.0;
				value += sampleLinear(left ? s.left : s.right, position) * volume * volume;
				if (!left)
					position += (pitch / s.sample_rate_pos);
				if (position + 1 > s.size)
					position = 0.0;
				value = Math.max(Math.min(value, 1.0), -1.0);
				// value = value > (1.0:Float) ? (1.0:Float) : value;
				// value = value < (-1.0:Float) ? (-1.0:Float) : value;
				buf.data.setF32(buf.write_location, value);
				buf.write_location += 4;
				if (buf.write_location > buf.data_size)
					buf.write_location = 0;
			}
		});
		trace("Start");
		while (true) {
			kinc.audio2.Audio.update();
			if (Sys.getChar(false) == "e".code)
				break;
		}
	}
}
