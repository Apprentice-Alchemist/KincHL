let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");
project.addExclude("src/g5/**");
switch(platform){
    case Platform.Linux:
        project.addLib("hl");
        break;
    case Platform.OSX:
        if (require("process").env["GITHUB_WORKSPACE"]) {
            // project.addLib(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/libhl.dylib");
            // project.addIncludeDir(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/src");
            project.addIncludeDir("/usr/local/include");
            project.addLib("/usr/local/lib/libhl.dylib");
        }else{
            project.addLib("libhl.dylib");
        }
        break;
    case Platform.Windows:
        if (require("process").env["GITHUB_WORKSPACE"]) {
            project.addLib(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/x64/Release/libhl");
            project.addIncludeDir(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/src");
        } else {
            project.addLib(require("process").env["HASHLINK"] + "/libhl");
            project.addIncludeDir(require("process").env["HASHLINK"] + "/include");
        }
        break;
}

resolve(project);
