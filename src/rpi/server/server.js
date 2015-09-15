var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

app.set('port', 3005);

app.get('/', function(req, res){
  res.sendFile(__dirname + '/html/index.html');
});

app.get('/build/bundle.js', function(req, res){
  res.sendFile(__dirname + '/build/bundle.js');
});

io.on('connection', function(socket){
  console.log('a user connected');
});

http.listen(app.get('port'), function(){
  console.log('listening on *:' + app.get('port'));
});
