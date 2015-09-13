require('../sass/styles.sass')
var Model = require('ampersand-model');
var View = require('ampersand-view');

var Temperature = Model.extend({
    props: {
      current: 'number',
      desired: 'number',
      humidity: 'number'
    }
});

var TempView = View.extend({
  template: function() {
    return document.querySelector('#template').innerHTML;
  },

  bindings: {
    'model.current': '[data-hook=current]',
    'model.desired': '[data-hook=desired]',
    'model.humidity': '[data-hook=humidity]',
  },

  events: {
    'mousedown .button': 'clicked'
  },

  clicked: function(e) {
    console.log("Clicked!!!");
  },

  render: function() {
    this.renderWithTemplate(this);
    return this;
  }
});


// Main
var aModel = new Temperature({current: 25, desired: 22, humidity: 60});
aModel.on('change:humidity', function () {
  console.log('Humidity changed!');
});

aView = new TempView({model: aModel});
aView.render();
document.querySelector('#container').appendChild(aView.el);
aModel.humidity = 44;
