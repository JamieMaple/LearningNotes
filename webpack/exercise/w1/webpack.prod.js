var merge = require('webpack-merge')
var UglifyjsWebpackPlugin = require('uglifyjs-webpack-plugin')
var common = require('./webpack.common')

module.exports = merge(common, {
  plugins: [
    new UglifyjsWebpackPlugin()
  ]
})
