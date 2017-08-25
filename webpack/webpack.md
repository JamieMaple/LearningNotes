# webpack_learing

1. 新建项目`mikdir dir && cd dir`
2. 初始化`npm init`
3. 安装webpack到本地`npm install webpack --save-dev`

### 项目结构

webpack-demo结构

```
|- /dist
|- /src
|- /node_modules
|- index.html
|- package.json
|- webpack.config.js
```

### 配置选项

1. context

   >  The base directory (absolute path!) for resolving the `entry` option

2. entry

   type: Object

   参数:字符串、数组或者对象以及组合

3. output

   type: Object

   -  filename

      -  当多入口文件时，output组好结合hash、name以及chunkname
      -  可以写类似`js/[name]-[hash]bundle.js`,生成的文件位于dist/js中

   - path

      >  The output directory as an **absolute path** (required)
      >
      >  `[hash]` is replaced by the hash of the compilation

      一般结合`__dirname`,比如`path: __dirname+'/dist'`

      PS: `__dirname`是指你的项目根目录

   - publicPath — 占位符

      可以替换上线地址

4. loaders处理

   写法参考

   ```javascript
   module: {								   ①
     rules: [								   ②
         {
           test: /\.js$/,
           loader: 'babel-loader',
           exclude: path.resolve(__dirname, 'node_modules'),
           include: path.resolve(__dirname, 'src'),
           options: {
             presets: ['env']
           }
         },
         {
           test: /\.css$/,
           loader: 'style-loader!css-loader'  ③
         }
       ]
   }
   ```

   注意点:

   -  **module**不是复数

   - modul.loaders移除，更换为**module.rules**

   - loader处理顺序为**从右往左**，同时loader写法可以替换为use()，即

      ```javascript
      use: [
          'style-loader',
          { loader: 'css-loader', options: { importLoaders: 1 } },
          { loader: 'postcss-loader', options: { parser: 'sugarss', exec: true } }
        ]
      ```

   - es2015/es6

      -  install: `npm i babel-loader babel-core babel-preset-env --save-dev`


    -  loader:` babel-loader`
    -  其他参数

-  其他参数

等等其他loader, 要注意的事webpack只能识别**js**,而且不能原生支持es2015语法

​		- install: `npm i css-loader style-loader postcss-loader autoprefixer --save-dev`

​		- loader: `css-loader `、`style-loader`、`postcss-loader `、`autoprefixer

5. 插件配置Plugin

   type: Array

   1. html-webpak-plugin自动生成HTML文件的插件

      **参数**

      -  filename   —  生成文件名和路径
      -  template   —  生成模板选取
      -  inject          — 生成的引用文件插入哪个地方，header或body
      -  <options> 模板引擎引入template中  — 可以对template文件进行传参，html中利用<%= htmlWebpackPlugin.options.props %>传参

      `可以遍历一遍属性，json字符串化输出`

      -  其他参数

         >  https://www.npmjs.com/package/html-webpack-plugin#configuration

         包括压缩等实用参数

6. 模块热更新

   ​

7. JavaScript模板引擎

   -  jade
   -  mustache

   ### 多页面应用

   1. 多个 entry 入口文件
   2. 多次实例化 newWebpackPlugin({})插件

   ​