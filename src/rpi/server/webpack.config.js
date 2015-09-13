var path = require('path');

config = {
    entry: "./js/main.js",

    output: {
        filename: "build/bundle.js"
    },

    module: {
        loaders: [
            { loader: 'style!css!autoprefixer!sass?indentedSyntax=sass', test: /\.sass$/ },
            //{ loader: 'coffee', test: /\.coffee$/ },
            { loader: 'url', test: /\.(gif|jpg|png|svg)$/ },
        ]
    },

    resolve: {
      //extensions: ['', '.coffee', '.js']
      extensions: ['', '.js']
    },

    node: {
      fs: "empty"
    },

    devServer: {
      port: 8181,
      //contentBase: "./html",
      //noInfo: true, //  --no-info option
      //hot: true,
      //inline: true
    }
};

module.exports = config;
