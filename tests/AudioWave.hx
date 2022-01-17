import kinc.audio2.Buffer;

final REAL_TIME_FREQUENCY = 440;
final ANGULAR_FREQUENCY = REAL_TIME_FREQUENCY * 2 * Math.PI;


function main() {
    var sample = 0;
	kinc.audio2.Audio.init();
	kinc.audio2.Audio.setCallback((buffer, samples) -> {
		for (i in 0...samples) {
			var left = (i % 2) == 0;
			var v = 0;
			function generateSample(buffer:Buffer, sampleNumber) {
				final sampleTime = sampleNumber / 44100; //buffer.format.samples_per_second;
				final sampleAngle = sampleTime * ANGULAR_FREQUENCY;
				return Math.sin(sampleAngle) * Math.sin(sampleNumber / 5000);
			}

			buffer.data.setF32(buffer.write_location, generateSample(buffer,sample++));
			buffer.write_location += 4;
			if (buffer.write_location >= buffer.data_size)
				buffer.write_location = 0;
		}
	});

	while (true) {
		if (Sys.stdin().readByte() == "e".code)
			break;
		kinc.audio2.Audio.update();
	}
	kinc.audio2.Audio.shutdown();
}
