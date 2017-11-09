const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')

// @test: if is development mode
// const isDev = process.env.NODE_ENV === 'development'
// console.log('isDev: ', isDev)

function resolve(pathname) {
  return path.resolve(__dirname, '..', pathname)
}

module.exports = {
  entry: {
    app: ['./src/index.js'],
    vendor: ['react', 'react-dom']
  },
  output: {
    path: resolve('dist'),
    filename: 'js/[name].js',
    publicPath: '/'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './index.html'
    })
  ],
  resolve: {
    extensions: ['.js', '.jsx', '.json']
  },
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        exclude: /(node_modules|bower_components)/,
        use: [
          'babel-loader', 
          'eslint-loader'
        ]
      },
      {
        test: /\.(jpe?g|png|gif|svg|ico)$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              limit: 10000,
              name: '[name].[ext]',
              outputPath: 'images/'
            }
          }
        ]
      },
      {
        test: /\.(eot|woff|ttf)$/,
        use: [{
          loader: 'url-loader',
          options: {
            name: '[name].[ext]',
            outputPath: 'fonts/'
          }
        }]
      }
    ]
  }
}
