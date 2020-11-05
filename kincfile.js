let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");

if(require("process").env["GITHUB_WORKSPACE"] != null){
    project.addIncludeDir(require("process").env["HASHLINK_INCLUDE"]);
    project.addLib(require("process").env["HASHLINK_BIN"] + "/libhl");
}else if(require("process").env["HASHLINK"]){
    const hashlink = require("process").env["HASHLINK"];
    project.addIncludeDir(hashlink + "/include");
    project.addLib(hashlink + "/libhl");
}else{
    console.log("%HASHLINK% not defined, exiting.");
    require("process").exit(1);
}

resolve(project);