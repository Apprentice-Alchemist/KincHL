const process = require("process");
const fs = require("fs");

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
        if (process.env["GITHUB_WORKSPACE"]) {
            // project.addLib(process.env["GITHUB_WORKSPACE"] + "/hashlink/libhl.dylib");
            // project.addIncludeDir(process.env["GITHUB_WORKSPACE"] + "/hashlink/src");
            project.addIncludeDir("/usr/local/include");
            project.addLib("/usr/local/lib/libhl.dylib");
        }else{
            project.addLib("libhl.dylib");
        }
        break;
    case Platform.Windows:
        if (process.env["GITHUB_WORKSPACE"]) {
            console.log(process.env["GITHUB_WORKSPACE"]);
            console.log(process.env["GITHUB_WORKSPACE"] + "/hashlink/x64/Release/libhl");
            let path = process.env["GITHUB_WORKSPACE"] + "/hashlink/x64/Release/libhl";
            try{
            console.log(fs.existsSync(path));
            console.log(fs.readdirSync(process.env["GITHUB_WORKSPACE"] + "/hashlink"));
            console.log(fs.readdirSync(process.env["GITHUB_WORKSPACE"] + "/hashlink/x64"));
            console.log(fs.readdirSync(process.env["GITHUB_WORKSPACE"] + "/hashlink/x64/Release"));
            }catch(e){}
            project.addLib(process.env["GITHUB_WORKSPACE"] + "/hashlink/x64/Release/libhl");
            project.addIncludeDir(process.env["GITHUB_WORKSPACE"] + "/hashlink/src");
        } else {
            project.addLib(process.env["HASHLINK"] + "/libhl");
            project.addIncludeDir(process.env["HASHLINK"] + "/include");
        }
        break;
}

resolve(project);
