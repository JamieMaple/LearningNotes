const webpack = require('webpack')
const WebpackDevServer = require('webpack-dev-server')
const FriendlyErrorsPlugin = require('friendly-errors-webpack-plugin')
const OpenBrowser = require('open')
const path = require('path')
const config = require('./webpack.dev')

const { PORT } = require('./commonConfig')

// 此处记录一个坑。。。其实就是因为自己不是很懂 dev-server 内部机制

config.entry.app.unshift(
  `webpack-dev-server/client?http://localhost:${PORT}`, 
  'webpack/hot/only-dev-server'
)

config.plugins.push(new FriendlyErrorsPlugin({
  compilationSuccessInfo: {
    messages: [`You application is running here http://localhost:${PORT}`],
    notes: ['Some additionnal notes to be displayed unpon successful compilation']
  },
  clearConsole: true
}))

const compiler = webpack(config)

const server = new WebpackDevServer(compiler, {
  contentBase: path.resolve(__dirname, '..', 'dist'),
  publicPath: config.output.publicPath,
  compress: true,
  hot: true,
  overlay: true,
  noInfo: true,
  quiet: true, // for friendly-erros-plugin
  historyApiFallback: true, // for spa
  clientLogLevel: 'none'
})

server.listen(PORT, 'localhost',() => {
  console.log('> Starting server...')
  OpenBrowser(`http://localhost:${PORT}`)
})
