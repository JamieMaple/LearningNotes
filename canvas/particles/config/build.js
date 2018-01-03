const webpack = require('webpack')
const NyanProgressPlugin = require('nyan-progress-webpack-plugin')
const config = require('./webpack.prod')

// production mode
// process.env.NODE_ENV = 'production'

config.plugins.push(new NyanProgressPlugin({
  debounceInterval: 60,
  nyanCatSays(progress, message) {
    if (progress === 1) {
      return '~maple~maple~~~done~'
    }
  }
}))

webpack(config, (err, stats) => {
  if (err) throw err
  process.stdout.write(stats.toString({
    colors: true,
    modules: false,
    children: false,
    chunks: false,
    chunkModules: false
  }) + '\n\n')
})
