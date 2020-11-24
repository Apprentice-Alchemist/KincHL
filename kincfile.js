let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");

if(require("process").env["GITHUB_WORKSPACE"]){
    project.addIncludeDir(require("process").env["GITHUB_WORKSPACE"] + "/hashlink/src");
    project.addLib("libhl");
}else if(require("process").env["HASHLINK"]){
    const hashlink = require("process").env["HASHLINK"];
    project.addIncludeDir(hashlink + "/include");
    project.addLib("libhl");
}else{
    console.log("%HASHLINK% not defined, exiting.");
    require("process").exit(1);
}

resolve(project);