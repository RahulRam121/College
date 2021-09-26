var express = require('express');
var fs = require("fs");
var router = express.Router();

router.get('/', function(req, res, next) {
    fs.readFile("D:\\output.txt", (err, data) => {
        if(err) {
            res.send('Error opening file');
        }
        else{
            res.send(data.toString());
        }
    });
});

module.exports = router;
