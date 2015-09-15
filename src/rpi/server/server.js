var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var child = require('child_process');
var binRemote = "../RF24RaspberryCommunicator/remotish.sh"

var runProcess = function(temp) {
  var processOutput = function(err, stdout, stderr) {
    return(stdout);
  }
  return child.execFile(binRemote, ['-t', temp], processOutput);
}

app.set('port', 3005);

app.get('/', function(req, res){
  res.sendFile(__dirname + '/html/index.html');
});

app.get('/build/bundle.js', function(req, res){
  res.sendFile(__dirname + '/build/bundle.js');
});

io.on('connection', function(socket){
  socket.on('temp', function(msg) {
    console.log('temp message received');
    io.emit('chat message', runProcess(0));
  });
});

http.listen(app.get('port'), function(){
  console.log('listening on *:' + app.get('port'));
});
