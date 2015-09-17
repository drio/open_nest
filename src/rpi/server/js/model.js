var Model  = require('ampersand-model');

var Temperature = Model.extend({
  props: {
    fresh: ['boolean', 'true', 'true'],
    current: ['number'],
    desired: ['number'],
    humidity: ['number'],
  },


});

module.exports = Temperature;
