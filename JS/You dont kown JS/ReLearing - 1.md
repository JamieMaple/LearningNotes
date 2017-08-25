# js笔记 

>  https://github.com/getify/You-Dont-Know-JS/
>

### 1. Welcome

1. 基本运算符等

2. Values & Type

   -  number
   -  string
   -  Boolean

   类型转换存在隐式转换，implicit coercion

3. constant— const

   `const a = 1`

4. blocks

5. conditionals

6. loop

### 2. Values & Types

1. `string`

2. `number`

3. `boolean`

4. `null` and `undefined`

5. `object`

6. `symbol` (new to ES6)

   -  JavaScript provides a `typeof` operator that can examine a value and tell you what type it is.
   -  Notice how in this snippet the `a` variable holds every different type of value, and that despite appearances, `typeof a` is not asking for the "type of `a`", but rather for the "type of the value currently in `a`." Only values have types in JavaScript; variables are just simple containers for those values.
   -  `typeof null` is an interesting case, because it errantly returns `"object"`, when you'd expect it to return `"null"`.

   ##### (1)Object

   -  The `object` type refers to a compound value where you can set properties (named locations) that each hold their own values of any type.

   ##### (2)Array

   -  An array is an `object` that holds values (of any type) not particularly in named properties/keys, but rather in numerically indexed positions.

   ##### (3)Function

   -  The other object subtype you'll use all over your JS programs is a function
   -  Again, functions are a subtype of `objects` -- `typeof` returns `"function"`, which implies that a `function` is a main type

   ##### (4)Built-In Type Methods

   -  Briefly, there is a `String` (capital `S`) object wrapper form, typically called a "native," that pairs with the primitive `string` type; it's this object wrapper that defines the `toUpperCase()` method on its prototype.
   -  A `string` value can be wrapped by a `String` object, a `number` can be wrapped by a `Number` object, and a `boolean`can be wrapped by a `Boolean` object. For the most part, you don't need to worry about or directly use these object wrapper forms of the values -- prefer the primitive value forms in practically all cases and JavaScript will take care of the rest for you.

   ##### (5)Comparing Values

   -  There are two main types of value comparison that you will need to make in your JS programs: *equality* and *inequality*. The result of any comparison is a strictly `boolean` value (`true` or `false`), regardless of what value types are compared.

   ##### (6)Truthy & Falsy

   -  The specific list of "falsy" values in JavaScript is as follows:
      -  `""` (empty string)
      -  `0`, `-0`, `NaN` (invalid `number`)
      -  `null`, `undefined`
      -  `false`
   -  Any value that's not on this "falsy" list is "truthy." Here are some examples of those:
      -  `"hello"`
      -  `42`
      -  `true`
      -  `[ ]`, `[ 1, "2", 3 ]` (arrays)
      -  `{ }`, `{ a: 42 }` (objects)
      -  `function foo() { .. }` (functions)
   -  It's important to remember that a non-boolean value only follows this "truthy"/"falsy" coercion if it's actually coerced to a boolean. It's not all that difficult to confuse yourself with a situation that seems like it's coercing a value to a boolean when it's not.

   ##### (7)Equality

   -  For example, `array`s are by default coerced to `string`s by simply joining all the values with commas (`,`) in between. You might think that two `array`s with the same contents would be `==` equal, but they're not

   ##### (8)Functions As Values

   -  Immediately Invoked Function Expressions (IIFEs)

      ```javascript
      (function IIFE(){
      	console.log( "Hello!" );
      })();
      // "Hello!"
      ```

   - **Closure**

      *You can think of closure as a way to "remember" and continue to access a function's scope (its variables) even once the function has finished running.*

   - **`this`**

      It's important to realize that `this` *does not* refer to the function itself, as is the most common misconception.

   - Prototypes

      When you reference a property on an object, if that property doesn't exist, JavaScript will automatically use that object's internal prototype reference to find another object to look for the property on. You could think of this almost as a fallback if the property is missing.

   - polyfilling and transpiling

      Essentially, your source code is authored in the new syntax form, but what you deploy to the browser is the transpiled code in old syntax form. You typically insert the transpiler into your build process, similar to your code linter or your minifier.

      >  -  Babel ([https://babeljs.io](https://babeljs.io/)) (formerly 6to5): Transpiles ES6+ into ES5
      >  -  Traceur ([https://github.com/google/traceur-compiler](https://github.com/google/traceur-compiler)): Transpiles ES6, ES7, and beyond into ES5

   - NON-JavaScript

      A good chunk of the stuff that you write in your code is, strictly speaking, not directly controlled by JavaScript

      like

      -   DOM API`: `var el = document.getElementById( "foo" );

         >  The `document` variable exists as a global variable when your code is running in a browser. It's not provided by the JS engine, nor is it particularly controlled by the JavaScript specification. It takes the form of something that looks an awful lot like a normal JS `object`, but it's not really exactly that. It's a special `object,` often called a "host object."

      - Another example is with input/output (I/O)

         >  Everyone's favorite `alert(..)` pops up a message box in the user's browser window. `alert(..)` is provided to your JS program by the browser, not by the JS engine itself. The call you make sends the message to the browser internals and it handles drawing and displaying the message box.

         >  The same goes with `console.log(..)`; your browser provides such mechanisms and hooks them up to the developer tools.\

### 3. scope & closure

(1)重新理解js中的函数和作用域

-  存在变量和函数两个声明提升问题(hoisting)


-  两种声明函数方式

-   不存在类似C语言那样的块作用域(block), 存在函数作用域这样特殊的scope,不包括es6的let新增语法

   ```javascript
   function test(){  
     for(var i=0;i<3;i++){     
     }  
     alert(i);  
   }  
   test(); // 3
   ```

   -  块作用域就是{ }包裹的范围，块作用域一般包含了if、while(for)以及switch
   -  特殊的就在js的函数作用域(链)

-  IIFE(Immediately Invoked Function Expressions)

   立即执行函数

-  with

   >  While it is a frowned upon construct, it *is* an example of (a form of) block scope

   它不仅是一个难于理解的结构，同时 也是 块作用域的一 个例子

-  try/catch

   >  It's a *very* little known fact that JavaScript in ES3 specified the variable declaration in the `catch` clause of a `try/catch` to be block-scoped to the `catch` block.

   ES3 规范中规定 try / catch 的 catch 分句会创建一个块作 用域，其中声明的变量仅在 catch 内部有效

-  let

   >  The `let` keyword attaches the variable declaration to the scope of whatever block (commonly a `{ .. }` pair) it's contained in. In other words, `let` implicitly hijacks any block's scope for its variable declaration.

-  const

   >  ES6 introduces `const`, which also creates a block-scoped variable, but whose value is fixed (constant).


(2)hoisting(变量提升)

-  exp1:

   ```javascript
   a = 2;

   var a;

   console.log( a ); // 2
   ```

   act:

   ```javascript
   var a;
   a = 2;
   console.log( a );
   ```

   >  We can be tempted to look at `var a = 2;` as one statement, but the JavaScript *Engine* does not see it that way. It sees `var a` and `a = 2` as two separate statements, the first one a compiler-phase task, and the second one an execution-phase task.

-  exp2:

   ```javascript
   console.log( a );

   var a = 2; // undefined
   ```

   act:

   ```javascript
   var a;
   console.log( a );
   a = 2;
   ```

- 原理

   -  compilers，engine
   -  Lexical Scope

   >   So, one way of thinking, sort of metaphorically, about this process, is that variable and function declarations are "moved" from where they appear in the flow of the code to the top of the code. This gives rise to the name "Hoisting".

   -  notes: Only the declarations themselves are hoisted, while any assignments or other executable logic are left *in place*. If hoisting were to re-arrange the executable logic of our code, that could wreak havoc.

   -  变量提升包含以下

      variable and function declarations(即变量声明和函数声明)

      It's also important to note that hoisting is **per-scope**.另外值得注意的是， 每个作用域 都会进行提升操作

      -  但是不包括声明后面的变量赋值`var a = 3`以及函数表达式`var a = function(){}`

      -  另外一个比较有趣的现象

         ```javascript
         foo(); // not ReferenceError, but TypeError!

         var foo = function bar() {
         	// ...
         };
         ```

         reasons: 我觉得是虽然`var foo`提升，但是左侧函数表达式没有提升，此时foo仅仅是一个普通变量，不是函数，因此`foo()`就报了TypeError的错.

         >  The variable identifier `foo` is hoisted and attached to the enclosing scope (global) of this program, so `foo()` doesn't fail as a `ReferenceError`. But `foo` has no value yet (as it would if it had been a true function declaration instead of expression). So, `foo()` is attempting to invoke the `undefined` value, which is a `TypeError` illegal operation.

-  函数优先原则

   -  exp：

      ```javascript
      foo(); // 1

      var foo;

      function foo() {
      	console.log( 1 );
      }

      foo = function() {
      	console.log( 2 );
      };
      ```

      act:

      ```javascript
      function foo() {
      	console.log( 1 );
      }

      foo(); // 1

      foo = function() {
      	console.log( 2 );
      };
      ```

      >   While multiple/duplicate `var` declarations are effectively ignored, subsequent function declarations *do* override previous ones.
      >
      >   尽管重复的 var 声明会被忽略掉，但出现在后面的函数声明
      >
      >   还是可以覆盖前面的。
      >

      >  Notice that `var foo` was the duplicate (and thus ignored) declaration, even though it came before the `function foo()...` declaration, because function declarations are hoisted before normal variables.
      >
      >  var foo 尽管出现在 function foo()... 的声明之前，但它是重复的声明（因此被忽 略了），因为函数声明会被提升到普通变量之前。

   -  js不存在函数重载

   -  Function declarations that appear inside of normal blocks typically hoist to the enclosing scope, rather than being conditional as this code implies:

      ```
      foo(); // "b"

      var a = true;
      if (a) {
         function foo() { console.log( "a" ); }
      }
      else {
         function foo() { console.log( "b" ); }
      }
      ```

      一个普通块内部的函数声明通常会被提升到所在作用域的顶部，这个过程不会像下面的代 码暗示的那样可以被条件判断所控制

**(3)Scope Closure作用域闭包**

**(4)Dynamic Scope**

```javascript
function foo() {
	console.log( a ); // 2
}

function bar() {
	var a = 3;
	foo();
}

var a = 2;

bar();
```

-  if JavaScript had dynamic scope, when `foo()` is executed, **theoretically** the code below would instead result in `3` as the output.
-  To be clear, JavaScript **does not, in fact, have dynamic scope**. It has lexical scope. Plain and simple. But the `this`mechanism is kind of like dynamic scope.
-  The key contrast: **lexical scope is write-time, whereas dynamic scope (and this!) are runtime**. Lexical scope cares *where a function was declared*, but dynamic scope cares where a function was *called from*.