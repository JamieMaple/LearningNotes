const express = require('express')
const webpack = require('webpack')
const open = require('open')
const WebpackDevMiddleware = require('webpack-dev-middleware')
const WebpackHotMiddleware = require('webpack-hot-middleware')

const app = express()
const config = require('./webpack.dev')
const compiler = webpack(config)

app.use(WebpackDevMiddleware(compiler, {
  publicPath: config.output.publicPath,
  quiet: true
}))

app.use(WebpackHotMiddleware(compiler, {
  log: false
}))

app.listen(8080, () => {
  console.log('> Starting Server\n')
  open('http://localhost:8080')
})
