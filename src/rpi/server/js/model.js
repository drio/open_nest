var Model = require('ampersand-model');

var Temperature = Model.extend({
    props: {
      current: 'number',
      desired: 'number',
      humidity: 'number'
    }
});

module.exports = Temperature;
