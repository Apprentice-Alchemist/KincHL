let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");

// Assume assume hl is appropriately installed via brew or with make install on linux and osx
switch(platform){
    case Platform.Linux:
        project.addLib("hl");
        break;
    case Platform.OSX:
        project.addLib("libhl.dylib");
        break;
    case Platform.Windows:
        if (require("process").env["GITHUB_WORKSPACE"]) {
            project.addLib(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/bin/libhl");
            project.addIncludeDir(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/bin/libhl");
        } else {
            project.addLib(require("process").env["HASHLINK"] + "/libhl");
            project.addIncludeDir(require("process").env["HASHLINK"] + "/include");
        }
        break;
}

resolve(project);
