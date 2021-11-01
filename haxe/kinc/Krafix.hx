package kinc;

import kinc.System.GraphicsApi;
import kinc.util.CString;

@:transitive
enum abstract KrafixTarget(String) from String to String {
	var GLSL = "glsl";
	var ESSL = "essl";
	var SpirV = "spirv";
	var MSL = "metal";
	var HLSL = "d3d11";
	var HLSL_D3D9 = "d3d9";

	@:from static function fromGraphicsApi(api:GraphicsApi):KrafixTarget {
		return switch api {
			case GraphicsApi.D3D9: HLSL_D3D9;
			case GraphicsApi.D3D11: HLSL;
			case GraphicsApi.D3D12: HLSL;
			case GraphicsApi.OpenGL:
				switch Sys.systemName() {
					case "Windows", "BSD", "Mac", "GNU/kFreeBSD", "Linux": GLSL;
					case "iOS", "tvOS", "Android": ESSL;
					default: throw "What's this, a console?";
				};
				"glsl";
			case GraphicsApi.Metal: MSL;
			case GraphicsApi.Vulkan: SpirV;
			case GraphicsApi.Other: throw "Unkown graphics api.";
		}
	}
}

@:transitive
enum abstract KrafixShaderType(String) from String to String {
	var Vert = "vert";
	var Frag = "frag";
	var Comp = "comp";
}

@:transitive enum abstract KrafixPlatform(String) from String to String {
	var Windows = 'windows';
	var WindowsApp = 'windowsapp';
	var iOS = 'ios';
	var OSX = 'osx';
	var Android = 'android';
	var Linux = 'linux';
	var HTML5 = 'html5';
	var Tizen = 'tizen';
	var Pi = 'pi';
	var tvOS = 'tvos';
	var PS4 = 'ps4';
	var XboxOne = 'xboxone';
	var Switch = 'switch';
	var XboxScarlett = 'xboxscarlett';
	var PS5 = 'ps5';
	var FreeBSD = 'freebsd';

	public static function fromSystemName(s:String):KrafixPlatform {
		return switch Sys.systemName() {
			case "Windows": Windows;
			case "BSD", "GNU/kFreeBSD": FreeBSD;
			case "Mac": OSX;
			case "Linux": Linux;
			case "iOS": iOS;
			case "tvOS": tvOS;
			case "Android": Android;
			default: throw "What's this, a console?";
		};
	}
}

class Krafix {
	@:hlNative("kinc", "krafix_compile") static function __compile(source:hl.Bytes, output:hl.Bytes, len:hl.Ref<Int>, targetlang:CString, system:CString,
		shadertype:CString):Void {};

	public static function compile(source:haxe.io.Bytes, target:KrafixTarget, system:KrafixPlatform, type:KrafixShaderType):haxe.io.Bytes {
		var length = 1024;
		final output = new hl.Bytes(length);
		__compile(source, output, length, target, system, type);
		return output.toBytes(length);
	}
}
