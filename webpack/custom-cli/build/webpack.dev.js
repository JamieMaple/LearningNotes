const merge = require('webpack-merge')
const webpack = require('webpack')
const common = require('./webpack.base')

module.exports = merge(common, {
  devtool: 'cheap-module-eval-source-map',
  devServer: {
    contentBase: __dirname + '/dist',
    compress: true,
    historyApiFallback: true,
    port: '8080'
  },
  plugins: [
    new webpack.HotModuleReplacementPlugin(),
    new webpack.DefinePlugin({
      'process.env': {
        'NODE_ENV': JSON.stringify('development')
      }
    })
  ],
  module: {
    rules: [
      {
        test: /\.(css|scss)$/,
        use: [
          'style-loader', 
          {
            loader: 'css-loader'
          }
          , 
          'postcss-loader'
        ]
      }
    ]
  }
})
