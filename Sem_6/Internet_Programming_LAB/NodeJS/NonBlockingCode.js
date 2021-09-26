var fs = require("fs");

fs.readFile('C:/Users/vallidevik/Desktop/NodeJS/input.txt', function (err, data) {
   if (err) return console.error(err);
   console.log(data.toString());
});

console.log("Program Ended");