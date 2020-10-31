let project = new Project("KincHL");
project.setDebugDir("Deployment");
project.addFile("src/**");
project.addIncludeDir("src/");
project.addIncludeDir(require("process").env["HASHLINK"] + "/include");
project.addLib(require("process").env["HASHLINK"] + "/libhl");
resolve(project);