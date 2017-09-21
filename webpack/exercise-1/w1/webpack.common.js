const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const CleanWebpackPlugin = require('clean-webpack-plugin')

module.exports = {
  entry: './src/app',
  module: {
    rules: [
      {
        test: /\.(js|jsx)$/,
        use: [
          'babel-loader'
        ]
      },
      {
        test: /\.css$/,
        use: [
          'style-loader',
          'css-loader'
        ]
      },
      {
        test: /\.(png|svg|jpg|gif)$/,
        use: ['file-loader']
      },
      {
        test: /\.(woff|woff2|eof|ttf|otf)$/,
        use: ['file-loader']
      }
    ]
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'Jamie Maple'
    }),
    new CleanWebpackPlugin(['dist'])
  ],
  output: {
    filename: '[name].bundle.js',
    chunkFilename: '[name].bundle.js',
    path: path.resolve(__dirname, 'dist')
  }
}
