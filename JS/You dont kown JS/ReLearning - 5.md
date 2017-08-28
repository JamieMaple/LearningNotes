# ReLearning - 5

补充学习

1. 内建类型

   -  检测是否为 null

      ```javascript
      var a = null;

      (!a && typeof a === "object"); // true
      ```

      `null`是唯一一个“falsy”（也叫类false；见第四章），但是在`typeof`检查中返回`"object"`的基本类型。

2. 值作为类型

   -  在 JavaScript 中， 变量没有类型 — — **值才有类型**
   -  JS 不存在 “类型强制”，也就是引擎不坚持认为一个 *变量* 总是持有与它开始存在时相同的 *初始类型* 的值。
   -  如果你对一个变量使用`typeof`，它会询问“在这个变量里的值的类型是什么？”
   -  `typeof`操作符总是返回字符串

3. `undefined` vs "ndeclared"

   一个“undefined”变量是在可访问的作用域中已经被声明过的，但是在 *这个时刻* 它里面没有任何值。相比之下，一个“undeclared”变量是在可访问的作用域中还没有被正式声明的

   但是呢

   ```javascript
   var a;

   typeof a; // "undefined"

   typeof b; // "undefined"
   ```

   ​

   typeof declared

   1. ```javascript
      var helper =
      			(typeof FeatureXYZ !== "undefined") ?
      			FeatureXYZ :
      			function() { /*.. 默认的特性 ..*/ };
      ```

   2. window.something

   3. ```javascript
      var helper = FeatureXYZ ||
      		function() { /*.. 默认的特性 ..*/ };
      ```

4. `array`，`string`，和`number`

   -  `Array`

      1. 和其他强制类型的语言相比，JavaScript的`array`只是值的容器，而这些值可以是任何类型：`string`或者`number`或者`object`，甚至是另一个`array`
      2. `array`是被数字索引的（正如你认为的那样），但微妙的是它们也是对象，可以在它们上面添加`string`键/属性（但是这些属性不会计算在`array`的`length`中）
      3. 如果一个可以被强制转换为10进制`number`的`string`值被用作键的话，它会认为你想使用`number`索引而不是一个`string`键

   -  类`Array`

      -  类型有 DOM 元素的列表，`arguments` 对象

      -  转化成对象

         `Array.prototype.slice()`

   -  String

      -  一个很常见的想法是，`string`实质上只是字符的`array`。虽然内部的实现可能是也可能不是`array`，但重要的是要理解JavaScript的`string`与字符的`array`确实不一样。它们的相似性几乎只是表面上的

      -  JavaScript的`string`是不可变的，而`array`是相当可变的。另外，在JavaScript中用位置访问字符的`a[1]`形式不总是广泛合法的。老版本的IE就不允许这种语法（但是它们现在允许了）。相反，*正确的* 方式是`a.charAt(1)`

         ```javascript
         a[1] = "O";
         b[1] = "O";

         a; // "foo"
         b; // ["f","O","o"]
         ```

      -  `string` 不能原地修改，而是要创建并返回一个新的`string`，类似的有`c = a.toUpper('string')`

      -  `array`没有像数组那样的 reverse 反转方法

         可以先转化成数组然后反转再转化成字符串

         但是这种方法对 Unicode 字符转是没有作用的

   -  Number

      -  JS没有真正的整数

      -  `toFixed` 输出的是`number`的`string`表现形式。如果你指定的位数多于值持有的小数位数时，会在右侧补`0`。

      -  二进制`0b101`，八进制写法`0o363` 或者`0O363`，十六进制写法`0Xf3`

      -  小数值有个坑

         ```javascript
         0.1 + 0.2 === 0.3; // false
         ```

         简单地说，`0.1`和`0.2`的二进制表示形式是不精确的，所以它们相加时，结果不是精确地`0.3`。而是 **非常** 接近的值：`0.30000000000000004`

      -  “错误舍入”

         在ES6中，使用这个容差值预定义了`Number.EPSILON`

         对于JavaScript来说这种`number`通常为`2^-52`

         这个很小的值经常被称为“机械极小值（machine epsilon）”

         其实就是 `Number.EPSILON = Math.pow(2,-52)`

      -  整数最大是`2^53 - 1`

   -  特殊值

      -  `undefined`是一个标识符，但不应该被覆盖；

         `null`是一个特殊的关键字

      -  `void`操作符会躲开所有值

      -  `NaN`是一种“哨兵值”（一个被赋予了特殊意义的普通的值。判断要用`isNaN()`

         ```javascript
         var a = 2 / "foo";
         var b = "foo";

         a; // NaN
         b; // "foo"

         window.isNaN( a ); // true
         window.isNaN( b ); // true -- 噢!
         ```

         一个缺陷：`"foo"`根本 *不是一个number*，但它也绝不是一个`NaN`值

         在ES6中，终于提供了一个替代它的工具：`Number.isNaN(..)`

      -  `Infinity` `-Infinity`

      -  存在 `-0`和`+0`之分，符号的存在很大程度上适应了开发者对一些诸如方向等信息的需要

      -  ES6中，有一个新工具可以用于测试两个值的绝对等价性，而没有任何这些例外`Object.is(..)`

         但是`==`和`===`效率更高、性能更好

5. 值和引用

   -  简单值（也叫基本标量） *总是* 通过值拷贝来赋予/传递：`null`，`undefined`，`string`，`number`， `boolean`，以及ES6的`symbol`。

   -  复合值——`object`（包括`array`，和所有的对象包装器）和`function`——*总是* 在赋值或传递时创建一个引用的拷贝。

   -  通过拷贝给函数传数组参`foo( arr.slice() );`

      ​