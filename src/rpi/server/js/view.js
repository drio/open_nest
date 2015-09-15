var View = require('ampersand-view');

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

module.exports = TempView;
