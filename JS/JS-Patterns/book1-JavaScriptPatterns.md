# JavaScript Patterns

>  懒惰是程序员的三大美德之一，好的模式才能 write less do more

### Introduction

1. Design Patterns

   exp:

   -  singleton
   -  factory
   -  decorator
   -  observer

2. Coding Patterns

3. Anti Patterns

### Essentials (基本要点)

##### maintainable code

-  fixed bugs are costly
-  waste time
-  sometime create bugs and fix them not one person
-  mostly, writting code spent less time than reading code
-  sometime code will be reviewed, revised for bugs , update or so on

1. what the maintainable code like:
   -  Is readable 
   -  Is consistent 
   -  Is predictable 
   -  Looks as if it was written by the same person 
   -  Is documented


2. Problems:

   -  Global variables

      1. `var a = b = 0` in function, varible `b` can be global (right-to-left evaluation)

         toReplace: `var a, b` and then `a = b = 0`

      2. Side effects

         There’s one slight difference between implied globals and explicitly defined ones — `delete`

      3. Access to global

         ```javascript
         const global = (function(){return this})
         // define global in the Global
         ```

         However, this is actually no longer the case in ECMAScript 5 in strict mode, so you have to adopt a different pattern when your code is in strict mode.

         // to fix

      4. Using single `var`

         use comma to delimit

         use initialized value

      5. Hoisting

   -  loop

      1. for loop (for 大撕逼)

         第一个，`length` 缓存的问题，之前有想到过

         两种观点:

         一种像 YDKJS 中的不推荐缓存等细小的优化之处而是推荐有 **big picture**，这个浏览器会二次处理写的代码，不要尝试和引擎比谁聪明；(https://github.com/getify/You-Dont-Know-JS/blob/master/async%20%26%20performance/ch6.md#microperformance)

         还有一种就是本文的观点，推荐缓存 `length`

         。。。两种观点我认为都有合理性

         -  此书中观点针对像 `HTML Collection Object` 这样的动态 `DOM ` 合集，每次循环都是要动态计算 `length` 的。。。当然 `v8` 可能特殊一点
         -  YDKSJ 针对的普通 `Array`，同时提到的是 `v8` 引擎，而他在那一章也提到了不是所有浏览器 **Not All Engines Are Alike**

         >  PS，动态 `HTML Collection Object` 和 静态 `Node list` 是不同的哦

         总结，我觉得还是那句老话 **过早优化是万恶之源**。就算优化应该有 `big picture` 不要老拘泥这些细微之处，毕竟现代前端工具如此多。。。当然如果真的要照顾 IE 8 以下的。。。那就老老实实缓存一下吧。。。

         ​

         第二个，关于`for loop`。。。文中谈到替换 `i++`甚至用减不用加 ，这个地方我觉得也很细小。。。不用纠结这个。。。真的太细小了。。。我不敢苟同。。。

      2. for-in loops (**enumeration**)

         for obj but not recommend for array

         the order is not guaranteed

         **Attention**: It’s important to use the method hasOwnProperty() when iterating due to prototype chain

         但是很多观点不是很认同，比如说为了防止某对象重写了 `hasOwnProperty()` 方法而访问不了`Object.prototype.hasOwnProperty()` 这个是肯定会尽量避免和原生方法重名的，所以这是代码编写的问题了。

      3. (Not) Augmenting Built-in Prototypes

         添加到内置原型的时候我觉得很少。。。就算用也可以先检测是否存在然后用 `Object.defineProperty()`添加

      4. Switch patterns

      5. Avoid implied typecasting

      6. Avoid eval()

         **eval() is evil.**

         `setTimeout()` 和 `setInterval()` 最好不要传 `String` 而传 `function` reference

         `new Function()` is similar to `eval()`

         In the following example, eval() can access and modify a variable in its outer scope, whereas Function cannot

         ```javascript
         (function () { 
           var local = 1
           eval("local = 3; console.log(local)") // logs 3 
           console.log(local); // logs 3 
         }());

         (function () { 
           var local = 1
           Function("console.log(typeof local);")() // logs undefined 
         }())
         ```

      7. `parseInt()`

         second parameter

         faster: `Number()`

         difference bettween them

      8. Code Conventions

         >  vue: vue style
         >
         >  airbnb: https://github.com/airbnb/javascript

         -  缩进：`tab` 与 `space` 的*宗教战争*
         -  花括号：总是有的
         -  左花括号位置 *换行* 与 *不换行* 的 *宗教战争*
         -  分号的 *加* 与 *不加* 的 *宗教战争*
         -  添加 `white space` 的辅助

      9. Naming conventions

         -  capitalizing Constructor
         -  camel case

      10. Writing comment

         -  describe the purpose
         -  what task
         -  keep up to date

      11. Writing API docs

          documentary tool will use the comments

          **doucumentary tool**

          >  http://code.google.com/p/jsdoc-toolkit/
          >
          >  http://yuilibrary.com/projects/yuidoc

          *改天可以造造这个文档工具的轮子，和markdown引擎一起来造*

          exp: 

          ```javascript
          /** 
           * Reverse a string
           * 
           * @param {String} input String to reverse 
           * @return {String} The reversed string 
          */ 
          var reverse = function (input) {
            // ... return output; 
          };
          ```

          notes:

          ```javascript
          @namespace

          The global reference that contains your object.

          @class A misnomer (no classes in JavaScript) that is used to mean either an object or a constructor function.

          @method

          Defines a method in an object and specifies the method name.

          @param 

          Lists the arguments that a function takes. The types of the parameters are in curly braces, followed by the parameter name and its description. 

          @return

          Like @param, only it describes the value returned by the method and has no name.
          ```

      12. Writing to be read
      
      13. Peer Reviews

      14. Minify

          ​









