const webpack = require('webpack')
const merge = require('webpack-merge')
const ExtractTextPlugin = require('extract-text-webpack-plugin')
const BundleAnalyzer = require('webpack-bundle-analyzer').BundleAnalyzerPlugin
const NyanProgressPlugin = require('nyan-progress-webpack-plugin')
const common = require('./webpack.base')

module.exports = merge(common, {
  devtool: 'source-map',
  plugins: [
    new webpack.optimize.CommonsChunkPlugin({
      name: 'vendor'
    }),
    new webpack.optimize.UglifyJsPlugin({
      warnings: false,
      sourceMap: true,
      output: {
        comments: false
      }
    }),
    new webpack.DefinePlugin({
      'process.env': {
        'NODE_ENV': JSON.stringify('production')
      }
    }),
    new ExtractTextPlugin('css/[name]-[hash].css'),
    new BundleAnalyzer({
      analyzerMode: 'static',
      reportFilename: 'report.html',
      openAnalyzer: true,
      generateStatsFile: true
    }),
    new NyanProgressPlugin({
      debounceInterval: 60,
      nyanCatSays(progress, message) {
        if (progress === 1) {
          return 'Maple~~done~~'
        }
      }
    })
  ],
  module: {
    rules: [
      {
        test: /\.(css|scss)$/,
        use: ExtractTextPlugin.extract({
          fallback: 'style-loader',
          use: [
            {
              loader: 'css-loader',
              options: {
                minimize: true,
                importLoaders: 1
              }
            },
            'postcss-loader'
          ]
        })
      }
    ]
  }
})