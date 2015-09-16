require('../sass/styles.sass')

var Temperature = require('../js/model')
var TempView    = require('../js/view')
var socket      = io();
var model       = new Temperature();
var view        = new TempView({model: model});

model.on('change:desired', function() {
  socket.emit('temp', model.desired);
});

socket.emit('temp', 0);

socket.on('temp', function(statusString){
  var status = JSON.parse(statusString);

  ['current', 'desired', 'humidity'].forEach(function(k) {
    model[k] = status[k];
  });

  view.render();
  document.querySelector('#container').appendChild(view.el);
});


