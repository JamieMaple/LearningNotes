# ReLearning - 6

1. 强制转换 

   将一个值从一个类型明确地转换到另一个类型通常称为“类型转换（type casting）”，当这个操作隐含地完成时称为“强制转换（coercion）”

   “类型转换（type casting/conversion）”发生在静态类型语言的编译时，而“类型强制转换（type coercion）”是动态类型语言的运行时转换

   **JavaScript 使用的是“隐含强制转换（implicit coercion）”与“明确强制转换（explicit coercion）”**

   ```javascript
   var a = 42;

   var b = a + "";			// 隐含强制转换

   var c = String( a );	// 明确强制转换
   ```

2. 抽象值操作

   ES5语言规范的第9部分用值的变形规则定义了几种“抽象操作”

   1. `ToString`

      当任何一个非`string`值被强制转换为一个`string`表现形式时，这个转换的过程是由语言规范的9.8部分的`ToString`抽象操作处理的。

      `toString()`可以明确地被调用，也可以通过在一个需要`string`的上下文环境中使用一个非`string`来自动地被调用。

   2. `JSON`字符串化

      使用`JSON.stringify(..)`工具将一个值序列化为一个JSON兼容的`string`值

      1. 对于最简单的值，JSON字符串化行为基本上和`toString()`转换是相同的，除了序列化的结果 *总是一个string*
      2. 任何可以用JSON表现形式合法表达的值都可以被`JSON.stringify(..)`字符串化
      3. `JSON.stringify(..)`工具在遇到`undefined`，`function`，和`symbol`时将会自动地忽略它们。
      4. 如果在一个`array`中遇到这样的值，它会被替换为`null`（这样数组的位置信息就不会改变）。
      5. 如果在一个`object`的属性中遇到这样的值，这个属性会被简单地剔除掉

      ```javascript
      JSON.stringify( undefined );					// undefined
      JSON.stringify( function(){} );					// undefined

      JSON.stringify( [1,undefined,function(){},4] );	// "[1,null,null,4]"
      JSON.stringify( { a:2, b:function(){} } );		// "{"a":2}"
      ```

      6. JSON字符串化有一个特殊行为，如果一个`object`值定义了一个`toJSON()`方法，这个方法将会被首先调用，以取得用于序列化的值

      7. `JSON.stringify(..)`的第二个参数值是可选的，它称为 *替换器（replacer）*。

         这个参数值既可以是一个`array`也可以是一个`function`。与`toJSON()`为序列化准备一个值的方式类似，它提供一种过滤机制，指出一个`object`的哪一个属性应该或不应该被包含在序列化形式中，来自定义这个`object`的递归序列化行为。

         ```javascript
         var a = {
         	b: 42,
         	c: "42",
         	d: [1,2,3]
         };

         JSON.stringify( a, ["b","c"] ); // "{"b":42,"c":"42"}"

         JSON.stringify( a, function(k,v){
         	if (k !== "c") return v;
         } );
         // "{"b":42,"d":[1,2,3]}"
         ```

      8. `JSON.stringify(..)`还可以接收第三个可选参数值，称为 *填充符（space）*。

         在对人类友好的输出中它被用做缩进。*填充符* 可以是一个正整数，用来指示每一级缩进中应当使用多少个空格字符。或者，*填充符* 可以是一个`string`，这时每一级缩进将会使用它的前十个字符。

   3. `ToNumber`

      如果任何非`number`值，以一种要求它是`number`的方式被使用，比如数学操作，就会发生ES5语言规范在9.3部分定义的`ToNumber`抽象操作。

      对`string`操作的有`parseInt(string)`和`Number(string)`。两者存在细微的差别。

   4. `ToBoolean`

      一个常见的误解是，值`1`和`0`与`true`/`false`是相同的。虽然这可能在其他语言中是成立的，但在JS中`number`就是`number`，而`boolean`就是`boolean`。你可以将`1`强制转换为`true`（或反之），或将`0`强制转换为`false`（或反之）。但它们不是相同的。

      1. `Falsy`值

         -  `undefined`
         -  `null`
         -  `false`
         -  `+0`, `-0`, and `NaN`
         -  `""`

         **任何没有明确地存在于falsy列表中的东西，都是truthy**。

      2. `Falsey`对象

         `document.all()`

      3. `|`和`~`

         `|`是按位或

         `~`是二进制取补操作

      4. 明确地：* --> Boolean

         虽然`Boolean(..)`是非常明确的，但是它并不常见也不为人所惯用

         对于 *明确的* 强制转换`Boolean(a)`和`!!a`是好得多的选项

      5. 隐含地：* --> Boolean

         1. 在一个`if (..)`语句中的测试表达式。

         2. 在一个`for ( .. ; .. ; .. )`头部的测试表达式（第二个子句）。

         3. 在`while (..)`和`do..while(..)`循环中的测试表达式。

         4. 在`? :`三元表达式中的测试表达式（第一个子句）。

         5. `||`（“逻辑或”）和`&&`（“逻辑与”）操作符左手边的操作数

            >  一个&&或||操作符产生的值不见得是Boolean类型。这个产生的值将总是两个操作数表达式其中之一的值。

            ```javascript
            var a = 42;
            var b = "abc";
            var c = null;

            a || b;		// 42
            a && b;		// "abc"

            c || b;		// "abc"
            c && b;		// null
            ```

         在这些上下文环境中使用的，任何还不是`boolean`的值，将通过本章早先讲解的`ToBoolean`抽象操作的规则，被 *隐含地* 强制转换为一个`boolean`。

      6. 隐含的强制转换

         -  隐含地：Strings <--> Numbers

            为了服务于`number`的相加和`string`的连接两个目的，`+`操作符被重载了

            如果`+`的两个操作数之一是一个`string`（或在上面的步骤中成为一个`string`），那么操作就会是`string`连接。否则，它总是数字加法。

   5. 明确解析数字字符串

      从一个字符串中解析出一个数字是 *容忍* 非数字字符的 —— 从左到右，如果遇到非数字字符就停止解析 —— 而强制转换是 *不容忍* 并且会失败而得出值`NaN`

      ```javascript
      var a = "42";
      var b = "42px";

      Number( a );	// 42
      parseInt( a );	// 42

      Number( b );	// NaN
      parseInt( b );	// 42
      ```

   6. 等价性的性能

      不要像许多人那样落入陷阱中，认为这会与性能有任何关系，虽然在这个问题上`==`好像要比`===`慢一些。强制转换确实要花费 *一点点* 处理时间，但也就是仅仅几微秒（是的，1微秒就是一秒的百万分之一！）

      如果你比较同类型的两个值，`==`和`===`使用的是相同的算法，所以除了在引擎实现上的一些微小的区别，它们做的应当是相同的工作。

   7. 抽象等价性

      在一般期望的结果中，有一些例外需要小心：

      -  `NaN`永远不等于它自己
      -  `+0`和`-0`是相等的

      条款11.9.3.1的最后一个规定是关于`object`（包括`function`和`array`）的`==`宽松相等性比较。这样的两个值仅在它们引用 *完全相同的值* 时 *相等*。这里没有强制转换发生。

      -  比较：string与number

         通过`ToNumber`抽象操作

      ```javascript
      var a = 42;
      var b = "42";

      a === b;	// false
      a == b;		// true  通过`ToNumber`抽象操作
      ```

      -  比较：任何东西与boolean

         ```javascript
         var a = "42";
         var b = true;

         a == b;	// false
         ```

         `Type(x)`确实是`Boolean`，所以它会实施`ToNumber(x)`，将`true`强制转换为`1`。现在，`1 == "42"`会被求值。

      -  比较：null与undefined

         当使用`==`宽松等价比较`null`和`undefined`，它们是互相等价

      -  比较：object与非object

         ```javascript
         var a = 42;
         var b = [ 42 ];

         a == b;	// true

         var a = "abc";
         var b = Object( a );	// 与`new String( a )`相同

         a === b;				// false
         a == b;					// true

         var a = null;
         var b = Object( a );	// 与`Object()`相同
         a == b;					// false

         var c = undefined;
         var d = Object( c );	// 与`Object()`相同
         c == d;					// false

         var e = NaN;
         var f = Object( e );	// 与`new Number( e )`相同
         e == f;					// false
         ```

3. 文法`grammar`

   1. 语句完成值

      `do { .. }`

   2. 表达式副作用

      -  ```javascript
         function foo() {
         	a = a + 1;
         }

         var a = 1;
         foo();		// 结果：`undefined`，副作用：改变 `a`
         ```

      -  ```javascript
         var a = 42;
         var b = a++;

         a;	// 43
         b;	// 42 
         ```

      -  `delete`操作符

         如果被请求的操作是合法/可允许的，`delete`操作符的结果值为`true`，否则结果为`false`。但是这个操作符的副作用是它移除了属性（或数组值槽）

   3. 上下文规则

      1. JSON-P

         实际上完全合法的JSON值`{"a":42}`本身将会抛出一个JS错误，因为它被翻译为一个带有非法标签的语句块儿。但是`foo({"a":42})`是一个合法的JS，因为在它里面，`{"a":42}`是一个被传入`foo(..)`的`object`字面量值。所以，更合适的说法是，**JSON-P使JSON成为合法的JS文法！**

      2. ```javascript
         [] + {}; // "[object Object]"
         {} + []; // 0
         ```

         在第一行中，`{}`出现在`+`操作符的表达式中，因此被翻译为一个实际的值（一个空`object`）。第四章解释过，`[]`被强制转换为`""`因此`{}`也会被强制转换为一个`string`：`"[object Object]"`。

         但在第二行中，`{}`被翻译为一个独立的`{}`空代码块儿（它什么也不做）。块儿不需要分号来终结它们，所以这里缺少分号不是一个问题。最终，`+ []`是一个将`[]`*明确强制转换* 为`number`的表达式，而它的值是`0`。

      3. 结构赋值

         ```javascript
         function getData() {
         	// ..
         	return {
         		a: 42,
         		b: "foo"
         	};
         }

         var { a, b } = getData();

         console.log( a, b ); // 42 "foo"
         ```

4. 一些错误补充

   1. 过早使用变量

      ES6定义了一个（坦白地说，让人困惑地命名的）新的概念，称为TDZ（“Temporal Dead Zone” —— 时间死区）

      TDZ指的是代码中还不能使用变量引用的地方，因为它还没有到完成它所必须的初始化。

      ```javascript
      {
      	a = 2;		// ReferenceError!
      	let a;
      }
      ```

   2. ```javascript
      {
      	typeof a;	// undefined
      	typeof b;	// ReferenceError! (TDZ)
      	let b;
      }
      {
      	typeof a;	// undefined
      	typeof b;	// ReferenceError! (TDZ)
      	let b;
      }
      ```

   3. 函数参数

      遵循一个简单的规则：**绝不同时引用一个被命名参数 和 它相应的arguments值槽**