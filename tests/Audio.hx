// import kinc.util.Floaty;
// import hl.Bytes;
// import kinc.util.ByteArray;
// import hl.BytesAccess;
// import sys.thread.Mutex;

// typedef Floaty = Float;

// class Audio {
// 	static var mutex:sys.thread.Mutex = new Mutex();

// 	// @:hlNative("kinc", "sampleLinear") static function sampleLinear(data:hl.Bytes, posistion:hl.F32):hl.F32
// 	// 	return 0.0;
// 	@:hlNative("kinc", "sound_init_vorbis") static function initVorbis(data:hl.Bytes,length:Int):hl.Bytes return null;
// 	@:hlNative("kinc", "sound_next_vorbis_samples") static function nextVorbisSamples(vorbis:hl.Bytes,samples:hl.Bytes,length:Int,loop:Bool,atend:Bool):Bool return false;
// 	static function main() {
// 		// var sound = kinc.audio1.Sound.create('C:/Program Files (x86)/Steam/steamapps/common/Aground/data/core/music/magic1.ogg');
// 		var bytes = sys.io.File.getBytes("C:/Program Files (x86)/Steam/steamapps/common/Aground/data/core/music/magic1.ogg");
// 		var vorbis = initVorbis(bytes.getData(),bytes.length);
// 		// function sampleLinear(data:ByteArray, position:Floaty):Floaty {
// 		// 	var pos1:Int = cast(position, Int);
// 		// 	var pos2:Int = cast(position + 1, Int);
// 		// 	var sample1:Floaty = data.getInt16(pos1) / 32767.0;
// 		// 	var sample2:Floaty = data.getInt16(pos2) / 32767.0;
// 		// 	var a:Floaty = position - pos1;
// 		// 	return sample1 * (1 - a) + sample2 * a;
// 		// }
// 		// var left_d = new ByteArray(sound.size, sound.left);
// 		// var right_d = new ByteArray(sound.size, sound.right);
// 		var pos:Floaty = 0.0;
// 		var volume:Floaty = 1.0;
// 		var pitch:Floaty = 1.0;
// 		kinc.audio2.Audio.init();
// 		#if kinc_audio
// 		kinc.audio1.Audio.init();
// 		kinc.audio1.Audio.playSound(sound, true, 1.0, false).volume = 0.5;
// 		#else
// 		inline function max(a:Floaty, b:Floaty)
// 			return a > b ? a : b;
// 		inline function min(a:Floaty, b:Floaty)
// 			return a < b ? a : b;

// 		kinc.audio2.Audio.setCallback(function(buf, samples) {
// 			var b = new hl.Bytes(samples);
// 			nextVorbisSamples(vorbis,b,2,true,false);
// 			for (i in 0...samples) {
// 				// mutex.acquire();
// 				// // var left = (i % 2) == 0;
// 				// // var value:Floaty = 0.5;
// 				// // if (left)
// 				// // 	value += sampleLinear(left_d, pos) * volume * volume;
// 				// // else
// 				// // 	value += sampleLinear(right_d, pos) * volume * volume;
// 				// // value = max(min(value, 1.0), -1.0);
// 				// // if (!left)
// 				// // 	pos += pitch / sound.sample_rate_pos;
// 				// // if (pos + 1 > sound.size)
// 				// // 	pos = 0;
				
// 				// nextVorbisSamples()
// 				// mutex.release();
// 				buf.data.setF32(buf.write_location, b.getF32(0));
// 				buf.write_location += 4;
// 				if (buf.write_location > buf.data_size)
// 					buf.write_location = 0;
// 			}
// 		});
// 		trace("Start");
// 		#end
// 		while (true) {
// 			kinc.audio2.Audio.update();
// 			if (Sys.getChar(false) == "e".code)
// 				break;
// 		}
// 	}
// }
