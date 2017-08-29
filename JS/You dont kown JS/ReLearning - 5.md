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

   -  你可能会遇到这样的情况，如果你想要传入一个像`2`这样的基本标量值的引用，你可以将这个值包装在它的`Number`对象包装器中。这个`Number`对象的引用的拷贝 *将* 会被传递给函数是事实，但不幸的是，和你可能期望的不同，拥有一个共享独享的引用不会给你修改这个共享的**基本值**的能力：

      ```javascript
      function foo(x) {
      	x = x + 1;
      	x; // 3
      }

      var a = 2;
      var b = new Number( a ); // 或等价的 `Object(a)`

      foo( b );
      console.log( b ); // 2, 不是 3
      ```

      这里的问题是，底层的基本标量值是 *不可变的*（`String`和`Boolean`也一样）。如果一个`Number`对象持有一个基本标量值`2`，那么这个`Number`对象就永远不能再持有另一个值；你只能用一个不同的值创建一个全新的`Number`对象。

   -  Review:

      简单基本标量（`string`，`number`等）通过值拷贝进行赋值/传递。

      而复合值（`object`等）通过引用拷贝进行赋值/传递。引用与其他语言中的引用/指针不同 —— 它们从不指向其他的变量/引用，而仅指向底层的值。

6. 原生类型   内置对象    Natives

   常用：

   -  `String()`
   -  `Number()`
   -  `Boolean()`
   -  `Array()`
   -  `Object()`
   -  `Function()`
   -  `RegExp()`
   -  `Date()`
   -  `Error()`
   -  `Symbol()` -- added in ES6!

   内部[[class]]

   `typeof`的结果为`"object"`的值（比如数组）被额外地打上了一个内部的标签属性`[[Class]]`（请把它考虑为一个内部的分类方法，而非与传统的面向对象编码的类有关）。这个属性不能直接地被访问，但通常可以间接地通过在这个值上借用默认的`Object.prototype.toString(..)`方法调用来展示

   ```javascript
   Object.prototype.toString.call( [1,2,3] );			// "[object Array]"

   Object.prototype.toString.call( /regex-literal/i );	// "[object RegExp]"

   Object.prototype.toString.call( "abc" );	// "[object String]"
   Object.prototype.toString.call( 42 );		// "[object Number]"
   Object.prototype.toString.call( true );		// "[object Boolean]"
   ```

   你会注意到，不存在`Null()`和`Undefined()`原生类型构造器，但不管怎样`"Null"`和`"Undefined"`是被暴露出来的内部`[[Class]]`值

   但是对于像`string`，`number`，和`boolean`这样的简单基本类型，实际上会启动另一种行为，通常称为“封箱（boxing）”

7. 封箱包装器

   这些对象包装器服务于一个非常重要的目的。基本类型值没有属性或方法，所以为了访问`.length`或`.toString()`你需要这个值的对象包装器。JS将会自动地 *封箱*（也就是包装）基本类型值来满足这样的访问。

   存在的坑：

   ```javascript
   var a = new Boolean( false );

   if (!a) {
   	console.log( "Oops" ); // 永远不会运行
   }
   ```

   这里的问题是，虽然你为值`false`创建了一个对象包装器，但是对象本身是“truthy”，所以使用对象的效果是与使用底层的值`false`本身相反的，这与通常的期望十分不同

8. 开箱

   -  `valueof()`方法

   -  强制类型转换

      ```javascript
      var a = new String( "abc" );
      var b = a + ""; // `b` 拥有开箱后的基本类型值"abc"

      typeof a; // "object"
      typeof b; // "string"
      ```

9. 原生类型作为构造器

   -  对于`array`，`object`，`function`，和正则表达式值来说，使用字面形式来创建它们的值几乎总是更好的选择，而且字面形式与构造器形式所创建的值是同一种对象

   -  一般来说应当避免使用它们作为构造器

   -  Array(...)

      `Array(..)`构造器不要求在它前面使用`new`关键字。如果你省略它，它也会像你已经使用了一样动作

      不要再用`new Array(n)`设定数组长度，非常诡异

      底线：你 **在任何情况下，永远不**，也不应该有意地创建并使用诡异的空值槽数组。就别这么干。它们是怪胎。

   -  `Object(..)`，`Function(..)`，和`RegExp(..)`

      1. `Object(..)`/`Function(..)`/`RegExp(..)`构造器一般来说也是可选的（因此除非是特别的目的，**应当避免使用**

      2. `Function`构造器仅在最最罕见的情况下有用，也就是你需要动态地定义一个函数的参数和/或它的函数体。

         **不要将Function(..)仅仅作为另一种形式的eval(..)**。

      3. 用字面量形式（`/^a*b+/g`）定义正则表达式是被大力采用的，不仅因为语法简单，而且还有性能的原因——JS引擎会在代码执行前预编译并缓存它们

         `RegExp(..)`有一些合理的用途：用来动态定义一个正则表达式的范例。

         这样的场景在JS程序中一次又一次地合法出现，所以你有需要使用`new RegExp("pattern","flags")`形式。

         ```javascript
         var name = "Kyle";
         var namePattern = new RegExp( "\\b(?:" + name + ")+\\b", "ig" );

         var matches = someText.match( namePattern );
         ```

      -  `Date(..)`和`Error(..)`

         `Date(..)`和`Error(..)`原生类型构造器要比其他种类的原生类型有用得多，因为它们没有字面量形式

         -  要创建一个日期对象值，你必须使用`new Date()`。`Date(..)`构造器接收可选参数值来指定要使用的日期/时间，但是如果省略的话，就会使用当前的日期/时间。
         -  如果你不带`new`调用`Date()`，你将会得到一个那个时刻的日期/时间的字符串表达
         -  `Error(..)`构造器在有`new`与没有`new`时的行为是相同的
         -  术上讲，除了一般的`Error(..)`原生类型以外，还有几种特定错误的原生类型：`EvalError(..)`，`RangeError(..)`，`ReferenceError(..)`，`SyntaxError(..)`， `TypeError(..)`，和`URIError(..)`。但是手动使用这些特定错误原生类型十分少见。如果你的程序确实遭受了一个真实的异常，它们是会自动地被使用的

      -  `Symbol(...)`

         -  在ES6中有几种预定义的Symbol，做为`Symbol`函数对象的静态属性访问，比如`Symbol.create`，`Symbol.iterator`等等。
         -  要定义你自己的Symbol，使用`Symbol(..)`原生类型。`Symbol(..)`原生类型“构造器”很独特，因为它不允许你将`new`与它一起使用，这么做会抛出一个错误
         -  虽然Symbol实际上不是私有的（在对象上使用`Object.getOwnPropertySymbols(..)`反射，揭示了Symbol其实是相当公开的），但是它们的主要用途可能是私有属性，或者类似的特殊属性。
         -  在属性名上加入`_`下划线前缀，这在经常在惯例上表示：“这是一个私有的/特殊的/内部的属性，别碰！”

      -  原生类型原型

         每一个内建的原生构造器都拥有它自己的`.prototype`对象。对于它们特定的对象子类型，这些对象含有独特的行为。

         -  做为文档惯例，`String.prototype.XYZ`会被缩写为`String#XYZ`，对于其它所有`.prototype`的属性都是如此。

         -  所有这些函数都可以访问`apply(..)`，`call(..)`，和`bind(..)`，因为`Function.prototype`定义了它们。

         -  一些原生类型的原型不 *仅仅* 是单纯的对象

            ```javascript
            typeof Function.prototype;			// "function"
            Function.prototype();				// 它是一个空函数！

            RegExp.prototype.toString();		// "/(?:)/" —— 空的正则表达式
            "abc".match( RegExp.prototype );	// [""]

            Array.isArray( Array.prototype );	// true
            Array.prototype.push( 1, 2, 3 );	// 3
            Array.prototype;					// [1,2,3]

            // 别这么留着它，要不就等着怪事发生吧！
            // 将`Array.prototype`重置为空
            Array.prototype.length = 0;
            ```

            `Function.prototype`是一个函数，`RegExp.prototype`是一个正则表达式，而`Array.prototype`是一个数组

            你甚至可以修改这些原生类型的原型（不仅仅是你可能熟悉的添加属性

         -  原型作为默认值

            `Function.prototype`是一个空函数，`RegExp.prototype`是一个“空”正则表达式（也就是不匹配任何东西），而`Array.prototype`是一个空数组，这使它们成了可以赋值给变量的，很好的“默认”值——如果这些类型的变量还没有值

      -  Review

         -  JavaScript为基本类型提供了对象包装器，被称为原生类型（`String`，`Number`，`Boolean`，等等）。这些对象包装器使这些值可以访问每种对象子类型的恰当行为（`String#trim()`和`Array#concat(..)`）
         -  如果你有一个像`"abc"`这样的简答基本类型标量，而且你想要访问它的`length`属性或某些`String.prototype`方法，JS会自动地“封箱”这个值
