const merge = require('webpack-merge')
const common = require('./webpack.common')
const UglifyJS = require('uglifyjs-webpack-plugin')
const webpack = require('webpack')

module.exports = merge(common, {
  devtool: 'inline-source-map',
  devServer: {
    contentBase: './dist',
    hot: true
  },
  plugins: [
    new webpack.HotModuleReplacementPlugin()
  ]
})
