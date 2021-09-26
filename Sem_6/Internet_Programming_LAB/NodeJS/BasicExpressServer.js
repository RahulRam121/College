var express = require('express')
var app = express()
const port = 3000;
app.get('/', function(req, res) {
res.send('Welcome to Node Twitter')
})
app.listen(3000,()=>
{
console.log(`Example app listening on ${port}!`)
});	

/*var express = require('express'),
    app = express.createServer(),
	 port = 1337;
app.listen(port);
    app.get('/', function(req, res){
res.send('Welcome to Node Twitter');
});
;

console.log('start express server\n');
*/
/*const express = require('express')
const app = express();
const port = 3000;

app.get('/', (req, res) => {
  res.send('Hello World!')
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}!`)
});*/

/*
const express = require('express')
const app = express()
 
app.get('/', function (req, res) {
  res.send('Hello World')
})
 
app.listen(3000)
*/