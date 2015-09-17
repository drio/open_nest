var app       = require('express')();
var http      = require('http').Server(app);
var io        = require('socket.io')(http);
var child     = require('child_process');
var binRemote = "../RF24RaspberryCommunicator/remotish.sh"

function runProcess(temp, cb) {
  child.execFile(
    binRemote, ['-t', temp],
    function(err, stdout, stderr) {
      cb(stdout);
    }
  );
}

app.set('port', 3005);

app.get('/', function(req, res){
  res.sendFile(__dirname + '/html/index.html');
});

app.get('/build/bundle.js', function(req, res){
  res.sendFile(__dirname + '/build/bundle.js');
});

app.get('/imgs/plus.svg', function(req, res){
  res.sendFile(__dirname + '/imgs/plus.svg');
});

app.get('/imgs/minus.svg', function(req, res){
  res.sendFile(__dirname + '/imgs/minus.svg');
});

app.get('/imgs/send.svg', function(req, res){
  res.sendFile(__dirname + '/imgs/send.svg');
});

io.on('connection', function(socket){
  socket.on('temp', function(desiredTemp) {
    runProcess(desiredTemp, function(stdout) {
      socket.emit('temp', stdout);
    });
  });
});

http.listen(app.get('port'), function(){
  console.log('listening on *:' + app.get('port'));
});
