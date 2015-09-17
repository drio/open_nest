require('../sass/styles.sass')

var Temperature = require('../js/model')
var TempView = require('../js/view')
var socket   = io();
var d3       = require('d3');

var model = new Temperature();
var view  = new TempView({model: model});
view.render();
document.querySelector('#container').appendChild(view.el);

model.on('change:desired', function() {
  socket.emit('temp', model.desired);
  if (model.fresh)
    model.fresh = false;
  else
    d3.select('.send').classed('hide', false);
});

socket.on('temp', function(statusString){
  var status = JSON.parse(statusString);

  ['current', 'desired', 'humidity'].forEach(function(k) {
    if (status[k] != model[k]) model[k] = status[k];
  });
});

socket.emit('temp', 0);
