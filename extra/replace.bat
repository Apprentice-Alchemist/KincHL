@echo off
@node -e "const fs = require('fs'); fs.writeFileSync('%1',fs.readFileSync('%1').toString().replace('%2','%3'));"