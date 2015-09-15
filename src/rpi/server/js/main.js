require('../sass/styles.sass')
var Temperature = require('../js/model')
var TempView    = require('../js/view')
var socket      = io();

var aModel = new Temperature({current: 25, desired: 22, humidity: 60});
aModel.on('change:humidity', function () {
  console.log('Humidity changed!');
});

aView = new TempView({model: aModel});
aView.render();
document.querySelector('#container').appendChild(aView.el);
aModel.humidity = 44;
