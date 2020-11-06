import kinc.audio1.Channel;
import kinc.audio1.Sound;

class Audio {
	static var sound:Sound;
	static var channel:Channel;

	static function main() {
		kinc.audio2.Audio.init();
		// kinc.audio2.Audio.setCallback(function(buf,samples){});
		// kinc.audio1.Audio.init();
		// sound = kinc.audio1.Audio.createSound("Deployment/sound.ogg");
		// channel = kinc.audio1.Audio.playSound(sound, true, 1, false);
		while (true) {
			if (Sys.getChar(true) == "e".code)
				break;
		}
	}
}
