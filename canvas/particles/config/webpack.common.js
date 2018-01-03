const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const ExtractTextPlugin = require('extract-text-webpack-plugin')

const isDev = process.env.NODE_ENV === 'development'

// console.log('isDev: ', isDev)

function resolve(dir) {
  return path.resolve(__dirname, '..', dir)
}

module.exports = {
  entry: {
    // vendor write here
    app: ['./src/index']
  },
  output: {
    path: resolve('dist'),
    publicPath: '/',
    filename: 'js/[name].js',
  },
  resolve: {
    extensions: ['.js', '.jsx','.json']
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'public/index.html',
      minify: {
        removeAttributeQuotes: true,
        collapseWhitespace: true,
        html5: true,
        minifyCSS: true,
        removeComments: true,
        removeEmptyAttributes: true
      },
      inject: true
    })
  ],
  module: {
    rules: [
      {
        test: /\.(ts|tsx)$/,
        loader: 'ts-loader'
      },
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        use: ['babel-loader', 'eslint-loader']
      },
      {
        test: /\.(css|scss)$/,
        use: isDev
        ? [
          'style-loader',
          {
            loader: 'css-loader',
            options: {
              importLoaders: 1,
              module: true,
              localIdentName: '[name]__[local]__[hash:base64:5]'
            }
          },
          'postcss-loader'
        ]
        : ExtractTextPlugin.extract({
          fallback: 'style-loader',
          use: [
            {
              loader: 'css-loader',
              options: {
                importLoaders: 1,
                minimize: true,
                module: true
              }
            },
            'postcss-loader'
          ]
        })
      },
      {
        test: /\.(jpe?g|png|gif|svg|ico)$/,
        use: [
          {
            loader: 'url-loader',
            options: {
              name: '[name]-[hash:base64:5].[ext]',
              limit: 10000,
              outputPath: 'images/'
            }
          }
        ]
      },
      {
        test: /\.(ttf|eot|woff|woff2|otf)/,
        use: [
          {
            loader: 'url-loader',
            options: {
              name: '[name]-[hash:base64:5].[ext]',
              limit: 10000,
              outputPath: 'fonts/'
            }
          }
        ]
      }
    ]
  }
}

if (!isDev) {
  module.exports.plugins.push(new ExtractTextPlugin('css/[name].css'))
}
