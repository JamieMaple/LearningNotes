const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const CleanWebpackPlugin = require('clean-webpack-plugin')

module.exports = {
    entry: './src/app.js',
    module: {
      rules: [
        {
          test: /\.css/,
          use: ['style-loader', 'css-loader']
        },
        {
          test: /\.(png|svg|jpg|gif)/,
          use: ['file-loader']
        },
        {
          test: /\.(woff|woff2|ttf)/,
          use: ['file-loader']
        }
      ]
    },
    plugins: [
      new HtmlWebpackPlugin({
        title: 'Hello World'
      }),
      new CleanWebpackPlugin(['dist'])
    ],
    output: {
      path: path.resolve(__dirname, 'dist'),
      filename: '[name].bundle.js'
    }
}
