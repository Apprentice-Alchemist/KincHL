const process = require("process");

let project = new Project("KincHL");

await project.addProject(process.env["KINC_PATH"] ?? "Kinc");

project.setDebugDir("");
project.addDefine("KORE_DEBUGDIR=\"\"");
project.addFile("src/kinchl.c");
project.addFile("tests/**"); // shaders
project.addIncludeDir("src/");
project.addExclude("src/g5/**");

if (process.env["KINCHL_VALIDATE_VULKAN"]) {
	project.addDefine("VALIDATE");
}

if (process.env["INCLUDE_KRAFIX"]) {
	await project.addProject(process.env["KRAFIX_PATH"] ?? "krafix");
	project.addDefine("INCLUDE_KRAFIX");
}

switch (platform) {
	case Platform.Linux:
		project.addLib("hl");
		break;
	case Platform.OSX:
		if (require("fs").existsSync("/usr/local/lib/libhl.dylib")) {
			project.addIncludeDir("/usr/local/include");
			project.addLib("/usr/local/lib/libhl.dylib");
		} else {
			project.addLib("libhl.dylib");
		}
		break;
	case Platform.Windows:
		let hl_inc = null;
		console.log(process.env);
		if (process.env["HASHLINK_SRC"]) {
			hl_inc = process.env["HASHLINK_SRC"]
		} else if (process.env["HASHLINK"] ?? process.env["HASHLINK_PATH"]) {
			hl_inc = (process.env["HASHLINK"] ?? process.env["HASHLINK_PATH"]) + "/include";
		}
		if (hl_inc == null) throw "could not find hashlink include path";

		let hl_bin = process.env["HASHLINK_BIN"] ?? process.env["HASHLINK"] ?? process.env["HASHLINK_PATH"] ?? null;
		if (hl_bin == null) throw "could not find hashlink binaries";
		project.addLib(hl_bin + "/libhl");
		project.addIncludeDir(hl_inc);
		break;
}

project.flatten();

resolve(project);