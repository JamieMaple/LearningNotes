const merge = require('webpack-merge')
const common = require('./webpack.common')
const UglifyJS = require('uglifyjs-webpack-plugin')

module.exports = {
  plugins: [
    new UglifyJS()
  ]
}
