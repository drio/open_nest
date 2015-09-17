var View   = require('ampersand-view');
var socket = io();

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
    'mousedown .more': 'tempUp',
    'mousedown .less': 'tempDown',
    'mousedown .send': 'send'
  },

  tempUp: function() { this.model.desired += 1; },

  tempDown: function() { this.model.desired -= 1; },

  send: function () {
    socket.emit('temp', this.model.desired);
  },

  render: function() {
    this.renderWithTemplate(this);
    return this;
  }
});

module.exports = TempView;
