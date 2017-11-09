const merge = require('webpack-merge')
const webpack = require('webpack')
const FriendlyErrorsPlugin = require('friendly-errors-webpack-plugin')
const common = require('./webpack.base')

module.exports = merge(common, {
  entry: {
    app: ['webpack-hot-middleware/client'] // middleware express
  },
  devtool: 'cheap-module-eval-source-map',
  devServer: {
    contentBase: __dirname + '/dist',
    compress: true,
    quiet: true, // for friendly errors plugin
    historyApiFallback: true,
    port: '8080'
  },
  plugins: [
    new webpack.NamedModulesPlugin(),
    new webpack.DefinePlugin({
      'process.env': {
        'NODE_ENV': JSON.stringify('development')
      }
    }),
    new webpack.optimize.OccurrenceOrderPlugin(),
    new webpack.HotModuleReplacementPlugin(),
    new webpack.NoEmitOnErrorsPlugin(),
    new FriendlyErrorsPlugin({
      compilationSuccessInfo: {
        messages: ['You application is running here http://localhost:3000', 'open your browser'],
        notes: ['Some additionnal notes to be displayed unpon successful compilation'],
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
          },
          'postcss-loader'
        ]
      }
    ]
  }
})
