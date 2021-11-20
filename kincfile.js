const process = require("process");

let project = new Project("KincHL");
project.setDebugDir("");
project.addDefine("KORE_DEBUGDIR=\"\"");
project.addFile("src/kinchl.c");
project.addFile("tests/**"); // shaders
project.addIncludeDir("src/");
project.addExclude("src/g5/**");

if(process.env["INCLUDE_KRAFIX"]) {
    project.addProject("../krafix");
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
        let hl_inc = "";
        if (process.env["HASHLINK_SRC"]) hl_inc = process.env["HASHLINK_SRC"];
        else if (process.env["HASHLINK"]) hl_inc = process.env["HASHLINK"] + "/include";
        else if (process.env["HASHLINKPATH"]) hl_inc = process.env["HASHLINKPATH"] + "/include";
        else throw "could not find hashlink include path";
        let hl_bin = "";
        if (process.env["HASHLINK_BIN"]) hl_bin = process.env["HASHLINK_BIN"];
        else if (process.env["HASHLINK"]) hl_bin = process.env["HASHLINK"];
        else if (process.env["HASHLINKPATH"]) hl_bin = process.env["HASHLINKPATH"];
        else throw "could not find hashlink binaries";
        project.addLib(hl_bin + "/libhl");
        project.addIncludeDir(hl_inc);
        break;
}

resolve(project);
