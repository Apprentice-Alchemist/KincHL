let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");

if(require("process").env["GITHUB_WORKSPACE"]){
    project.addIncludeDir(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/src");
    const platform = require("process").platform;
    switch(platform){
        case "linux": 
            project.addLib("hl");
            break;
        case "darwin":
            project.addLib(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/libhl.dylib");
            break;
        case "win32":
            project.addLib(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/bin/libhl");
            break;
    }
}else if(require("process").env["HASHLINK"]){
    const hashlink = require("process").env["HASHLINK"];
    project.addIncludeDir(hashlink + "/include");
    project.addLib((require("process").platform === "linux" || require("process").platform === "darwin") ? "hl" : "libhl");
}else{
    console.log("%HASHLINK% not defined, exiting.");
    require("process").exit(1);
}

resolve(project);
