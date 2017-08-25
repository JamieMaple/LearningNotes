# ReLearing - 2

### 4.this & Object Prototypes

-  **two misconceptions**

   1. Itself

      ```javascript
      function foo(num) {
      	console.log( "foo: " + num );

      	// keep track of how many times `foo` is called
      	foo.count++;
      }

      foo.count = 0;

      var i;

      for (i=0; i<10; i++) {
      	if (i > 5) {
      		foo( i );
      	}
      }
      // foo: 6
      // foo: 7
      // foo: 8
      // foo: 9

      // how many times was `foo` called?
      console.log( foo.count ); // 4
      ```

   2. Its Scope

      ```javascript
      function foo() {
      	var a = 2;
      	this.bar();
      }

      function bar() {
      	console.log( this.a );
      }

      foo(); //undefined
      ```

-  call-site

   1. we have to understand the call-site: the location in code where a function is called (**not where it's declared**).
   2. What's important is to think about the **call-stack** (the stack of functions that have been called to get us to the current moment in execution). The call-site we care about is *in* the invocation *before* the currently executing function.

-  four rules and precedence 绑定规则

   1. Default Binding : standalone function invocation 默认绑定

      exp:

      ```javascript
      function foo() {
      	console.log( this.a );
      }

      var a = 2;

      foo(); // 2
      ```

      -  the *default binding* for `this` applies to the function call, and so points `this` at the global object.

      -  If `strict mode` is in effect, the global object is not eligible for the *default binding*, so the `this` is instead set to `undefined`.

      -  >  A subtle but important detail is: even though the overall `this` binding rules are entirely based on the call-site, the global object is **only** eligible for the *default binding* if the **contents** of `foo()` are **not** running in `strict mode`; the `strict mode` state of the call-site of `foo()` is irrelevant.

         这里有一个微妙但是非常重要的细节，虽然 this 的绑定规则完全取决于调用位置，但是只 有 foo() 运行在非 strict mode 下时，默认绑定才能绑定到全局对象；严格模式下与 foo() 的调用位置无关：

   2. Implicit Binding 隐式绑定

      >  Another rule to consider is: does the call-site have a context object, also referred to as an owning or containing object, though *these* alternate terms could be slightly misleading.

      exp:

      -  Regardless of whether `foo()` is initially declared *on* `obj`, or is added as a reference later (as this snippet shows), in neither case is the **function** really "owned" or "contained" by the `obj` object.
      -  However, the call-site *uses* the `obj` context to **reference** the function, so you *could* say that the `obj` object "owns" or "contains" the **function reference** at the time the function is called.

      ```javascript
      function foo() {
      	console.log( this.a );
      }

      var obj = {
      	a: 2,
      	foo: foo
      };

      obj.foo(); // 2
      ```

      -  Only the top/last level of an object property reference chain matters to the call-site. For instance:

      ```
      function foo() {
      	console.log( this.a );
      }

      var obj2 = {
      	a: 42,
      	foo: foo
      };

      var obj1 = {
      	a: 2,
      	obj2: obj2
      };

      obj1.obj2.foo(); // 42
      ```

      -  Implicitly Lost 隐式丢失

      >  One of the most common frustrations that `this` binding creates is when an *implicitly bound* function loses that binding, which usually means it falls back to the *default binding*, of either the global object or `undefined`, depending on `strict mode`.

      exp:

      ```javascript
      function foo() {
      	console.log( this.a );
      }

      var obj = {
      	a: 2,
      	foo: foo
      };

      var bar = obj.foo; // function reference/alias!

      var a = "oops, global"; // `a` also property on global object

      bar(); // "oops, global"
      ```

      >  Even though `bar` appears to be a reference to `obj.foo`, in fact, it's really just another reference to `foo` itself. 

      虽然 bar 是 obj.foo 的一个引用， 但是实际上， 它引用的是 foo 函数本身， 因此此时的

      bar() 其实是一个不带任何修饰的函数调用，因此应用了默认绑定。

      ```javascript
      function foo() {
      	console.log( this.a );
      }

      function doFoo(fn) {
      	// `fn` is just another reference to `foo`

      	fn(); // <-- call-site!
      }

      var obj = {
      	a: 2,
      	foo: foo
      };

      var a = "oops, global"; // `a` also property on global object

      doFoo( obj.foo ); // "oops, global"
      ```

      >  Parameter passing is just an implicit assignment, and since we're passing a function, it's an implicit reference assignment, so the end result is the same as the previous snippet.

   3. Explicit Binding 显式绑定

      >  With *implicit binding* as we just saw, we had to mutate the object in question to include a reference on itself to the function, and use this property function reference to indirectly (implicitly) bind `this` to the object.

      >  "All" functions in the language have some utilities available to them (via their `[[Prototype]]` -- more on that later) which can be useful for this task. Specifically, functions have `call(..)` and `apply(..)` methods. Technically, JavaScript host environments sometimes provide functions which are special enough (a kind way of putting it!) that they do not have such functionality. But those are few. The vast majority of functions provided, and certainly all functions you will create, do have access to `call(..)` and `apply(..)`.

      JavaScript 中的“所有”函数都有一些有用的特性（这和它们的 [[ 原型 ]] 有关——之后我 们会详细介绍原型）， 可以用来解决这个问题。 具体点说， 可以使用函数的 call(..) 和 apply(..) 方法。严格来说， JavaScript 的宿主环境有时会提供一些非常特殊的函数，它们 并没有这两个方法。 但是这样的函数非常罕见， JavaScript 提供的绝大多数函数以及你自 己创建的所有函数都可以使用 call(..) 和 apply(..) 方法。

      exp:

      ```javascript
      function foo() {

      console.log( this.a ); }

      var obj = {

      a:2 };

      foo.call( obj ); // 2
      ```

      -  Hard Binding 硬绑定

      作为显式绑定的一个变种，硬绑定可以解决丢失绑定问题。

      ```javascript
      function foo() {
      	console.log( this.a );
      }

      var obj = {
      	a: 2
      };

      var bar = function() {
      	foo.call( obj );
      };

      bar(); // 2
      setTimeout( bar, 100 ); // 2

      // `bar` hard binds `foo`'s `this` to `obj`
      // so that it cannot be overriden
      bar.call( window ); // 2
      ```

      >  stack overflow
      >
      >  Use `.bind()` when you want that function to later be called with a certain context, useful in events. Use `.call()` or `.apply()` when you want to invoke the function immediately, and modify the context.

      >  `bind(..)` returns a new function that is hard-coded to call the original function with the `this` context set as you specified. 

      bind(..) 会返回一个硬编码的新函数，它会把参数设置为 this 的上下文并调用原始函数。

      >  **注意：** 在ES6中，`bind(..)`生成的硬绑定函数有一个名为`.name`的属性，它源自于原始的 *目标函数（target function）*。举例来说：`bar = foo.bind(..)`应该会有一个`bar.name`属性，它的值为`"bound foo"`，这个值应当会显示在调用栈轨迹的函数调用名称中。

      fake bind():

      ```javascript
      function bind(f, obj){
          return function(){
              f.apply(obj, arguments)
          }
      }
      ```

      ​

      -  API Call "cntexts" API调用的“上下文”

      exp :

      ```javascript
      function foo(el) {
      	console.log( el, this.id );
      }

      var obj = {
      	id: "awesome"
      };

      // 使用`obj`作为`this`来调用`foo(..)`
      [1, 2, 3].forEach( foo, obj ); // 1 awesome  2 awesome  3 awesome
      ```

   4. **`new`Binding  `new`关键字绑定**

      >  In traditional class-oriented languages, "constructors" are special methods attached to classes, that when the class is instantiated with a `new` operator, the constructor of that class is called. 

      JavaScript拥有`new`操作符，而且它使用的代码模式看起来基本和我们在面向类语言中看到的一样；大多数开发者猜测JavaScript机制是某种相似的东西。但是，实际上JavaScript的机制和`new`在JS中的用法所暗示的面向类的功能 *没有任何联系*。

      **constructor**

      >  In JS, constructors are **just functions** that happen to be called with the `new` operator in front of them. They are not attached to classes, nor are they instantiating a class. They are not even special types of functions. They're just regular functions that are, in essence, hijacked by the use of `new` in their invocation.

      ```
      当 Number 在 new 表达式中被调用时， 
      它是一个构造函数：它会初始化新创建的对象。
      ```

      >  JavaScript has a `new` operator, and the code pattern to use it looks basically identical to what we see in those class-oriented languages; most developers assume that JavaScript's mechanism is doing something similar. However, there really is *no connection* to class-oriented functionality implied by `new` usage in JS.

      所以， 包括内置对象函数（比如 Number(..) ， 详情请查看第 3 章）在内的所有函数都可

      以用 new 来调用，这种函数调用被称为构造函数调用。这里有一个重要但是非常细微的区 别：实际上并不存在所谓的“构造函数”，只有对于函数的“构造调用”。

      When a function is invoked with `new` in front of it, otherwise known as a constructor call, the following things are done automatically:

      1. a brand new object is created (aka, constructed) out of thin air
      2. *the newly constructed object is [[Prototype]]-linked*
      3. the newly constructed object is set as the `this` binding for that function call
      4. unless the function returns its own alternate **object**, the `new`-invoked function call will *automatically* return the newly constructed object.

      **translation**

      1. 创建（或者说构造）一个全新的对象。
      2. 这个新对象会被执行[[原型]]连接。
      3. 这个新对象会绑定到函数调用的 this 。
      4. 如果函数没有返回其他对象，那么 new 表达式中的函数调用会自动返回这个新对象。

   **`this` precedence**

   -  precedence : `new` / explict binding > implict binding > default binding

   -  `new` 和 `call/apply` 不能同时使用

   -  `new` 会替换覆盖硬绑定

      >  The primary reason for this behavior is to create a function (that can be used with `new` for constructing objects) that essentially ignores the `this` *hard binding* but which presets some or all of the function's arguments. One of the capabilities of `bind(..)` is that any arguments passed after the first `this` binding argument are defaulted as standard arguments to the underlying function (technically called "partial application", which is a subset of "currying").

      之所以要在 new 中使用硬绑定函数， 主要目的是预先设置函数的一些参数， 这样在使用 new 进行初始化时就可以只传入其余的参数。 bind(..) 的功能之一就是可以把除了第一个 参数（第一个参数用于绑定 this ）之外的其他参数都传给下层的函数（这种技术称为“部 分应用”，是“柯里化”的一种）。

      >  柯里化(currying)相关链接 ：https://zh.wikipedia.org/wiki/%E6%9F%AF%E9%87%8C%E5%8C%96

   -  <u>determining</u> `this`

      1. Is the function called with `new` (**new binding**)? If so, `this` is the newly constructed object.

         `var bar = new foo()`

      2. Is the function called with `call` or `apply` (**explicit binding**), even hidden inside a `bind` *hard binding*? If so, `this` is the explicitly specified object.

         `var bar = foo.call( obj2 )`

      3. Is the function called with a context (**implicit binding**), otherwise known as an owning or containing object? If so, `this` is *that* context object.

         `var bar = obj1.foo()`

      4. Otherwise, default the `this` (**default binding**). If in `strict mode`, pick `undefined`, otherwise pick the `global`object.

         `var bar = foo()`

-  Binding Exceptions

   -  Ignored `this`

      1. If you pass `null` or `undefined` as a `this` binding parameter to `call`, `apply`, or `bind`, those values are effectively ignored, and instead the *default binding* rule applies to the invocation.

         ```javascript
         function foo() {
         	console.log( this.a );
         }

         var a = 2;

         foo.call( null ); // 2
         ```

      2. 学会善用null binding this

      3. safer 空对象ø

         we can create a "DMZ" (de-militarized zone) object -- nothing more special than a completely empty, non-delegated (see Chapters 5 and 6) object.

         创建: `Object.create(null)`

         >  Whatever you call it, the easiest way to set it up as **totally empty** is `Object.create(null)` (see Chapter 5). `Object.create(null)` is similar to `{ }`, but without the delegation to `Object.prototype`, so it's "more empty" than just `{ }`.

      4. indirection

         >  Another thing to be aware of is you can (intentionally or not!) create "indirect references" to functions, and in those cases, when that function reference is invoked, the *default binding* rule also applies.

         exp: 

         ```javascript
         function foo() {
         	console.log( this.a );
         }

         var a = 2;
         var o = { a: 3, foo: foo };
         var p = { a: 4 };

         o.foo(); // 3
         (p.foo = o.foo)(); // 2
         ```

         The *result value* of the assignment expression `p.foo = o.foo` is a reference to just the underlying function object. As such, the effective call-site is just `foo()`, not `p.foo()` or `o.foo()` as you might expect. Per the rules above, the *default binding* rule applies.

         赋值表达式 p.foo = o.foo 的 返回值 是目标函数的引用， 因此调用位置是 foo() 而不是 p.foo() 或者 o.foo() 。根据我们之前说过的，这里会应用默认绑定。

      5. Softening Binding --软绑定--**不是很懂的地方**

         ```javascript
         if (!Function.prototype.softBind) {
         	Function.prototype.softBind = function(obj) {
         		var fn = this,
         			curried = [].slice.call( arguments, 1 ),
         			bound = function bound() {
         				return fn.apply(
         					(!this ||
         						(typeof window !== "undefined" &&
         							this === window) ||
         						(typeof global !== "undefined" &&
         							this === global)
         					) ? obj : this,
         					curried.concat.apply( curried, arguments )
         				);
         			};
         		bound.prototype = Object.create( fn.prototype );
         		return bound;
         	};
         }
         ```

         The `softBind(..)` utility provided here works similarly to the built-in ES5 `bind(..)` utility, except with our *soft binding* behavior. It wraps the specified function in logic that checks the `this` at call-time and if it's `global` or `undefined`, uses a pre-specified alternate *default* (`obj`). Otherwise the `this` is left untouched. It also provides optional currying (see the `bind(..)` discussion earlier).

         除了软绑定之外， softBind(..) 的其他原理和 ES5 内置的 bind(..) 类似。它会对指定的函数进行封装，首先检查调用时的 this ，如果 this 绑定到全局对象或者 undefined ，那就把指定的默认对象 obj 绑定到 this ，否则不会修改 this 。此外，这段代码还支持可选的柯里 化（详情请查看之前和 bind(..) 相关的介绍）。

      6. Lexical `this `    词法`this`

      7. ​

         **this is for `arrow-function`**

         exp1:

         ```javascript
         function foo() {
         	// return an arrow function
         	return (a) => {
         		// `this` here is lexically adopted from `foo()`
         		console.log( this.a );
         	};
         }

         var obj1 = {
         	a: 2
         };

         var obj2 = {
         	a: 3
         };

         var bar = foo.call( obj1 );
         bar.call( obj2 ); // 2, not 3!
         ```

         The arrow-function created in `foo()` lexically captures whatever `foo()`'s `this` is at its call-time.

          Since `foo()` was `this`-bound to `obj1`, `bar` (a reference to the returned arrow-function) will also be `this`-bound to `obj1`. 
         The lexical binding of an arrow-function cannot be overridden (even with `new`!).

         在`foo()`中创建的箭头函数在词法上捕获`foo()`调用时的`this`，不管它是什么。因为`foo()`被`this`绑定到`obj1`，`bar`（被返回的箭头函数的一个引用）也将会被`this`绑定到`obj1`。一个箭头函数的词法绑定是不能被覆盖的（就连`new`也不行！）

         The most common use-case will likely be in the use of callbacks, such as event handlers or timers:

         exp2:

         ```javascript
         function foo() {
         	setTimeout(() => {
         		// `this` here is lexically adopted from `foo()`
         		console.log( this.a );
         	},100);
         }

         var obj = {
         	a: 2
         };

         foo.call( obj ); // 2
         ```

         While arrow-functions provide an alternative to using `bind(..)` on a function to ensure its `this`, which can seem attractive, it's important to note that they essentially are disabling the traditional `this` mechanism in favor of more widely-understood lexical scoping. Pre-ES6, we already have a fairly common pattern for doing so, which is basically almost indistinguishable from the spirit of ES6 arrow-functions:

         箭头函数可以像 bind(..) 一样确保函数的 this 被绑定到指定对象，此外，其重要性还体 现在它用更常见的词法作用域取代了传统的 this 机制。实际上，在 ES6 之前我们就已经 在使用一种几乎和箭头函数完全一样的模式。

         ```
         function foo() {
         	var self = this; // lexical capture of `this`
         	setTimeout( function(){
         		console.log( self.a );
         	}, 100 );
         }

         var obj = {
         	a: 2
         };

         foo.call( obj ); // 2
         ```

         If you find yourself writing `this`-style code, but most or all the time, you defeat the `this` mechanism with lexical `self = this` or arrow-function "tricks", perhaps you should either:

         1. Use only lexical scope and forget the false pretense of `this`-style code.仅使用词法作用域并忘掉虚伪的`this`风格代码
         2. Embrace `this`-style mechanisms completely, including using `bind(..)` where necessary, and try to avoid `self = this` and arrow-function "lexical this" tricks.完全接受`this`风格机制，包括在必要的时候使用`bind(..)`，并尝试避开`self = this`和箭头函数的“词法this”技巧。

         **A program can effectively use both styles of code (lexical and `this`), but inside of the same function, and indeed for the same sorts of look-ups, mixing the two mechanisms is usually asking for harder-to-maintain code, and probably working too hard to be clever.**

      8. review

         **four rules and precedence**

         1. Called with `new`? Use the newly constructed object.
         2. Called with `call` or `apply` (or `bind`)? Use the specified object.
         3. Called with a context object owning the call? Use that context object.
         4. Default: `undefined` in `strict mode`, global object otherwise.

         **DMZ object**

         a "DMZ" object like `ø = Object.create(null)` is a good placeholder value that protects the `global`object from unintended side-effects.

         **Lexical this**

         They are essentially a syntactic replacement of `self = this` in pre-ES6 coding


###5.Objects

1. Syntax

   Objects come in two forms: the declarative (literal) form(声明（字面）形式), and the constructed form(构造形式).

   ```javascript
   var myObj = {
   	key: value
   	// ...
   };
   ```

   ```javascript
   var myObj = new Object();
   myObj.key = value;
   ```

   differ:

   >  The constructed form and the literal form result in exactly the same sort of object. The only difference really is that you can add one or more key/value pairs to the literal declaration, whereas with constructed-form objects, you must add the properties one-by-one.

2. *simple primitives* (`string`, `number`, `boolean`, `null`, and `undefined`) are **not** themselves `objects`. 

   引申: 

   主要类型(primary type)

   基本类型（simple primitive）和引用类型（reference ）。

   引用类型主要指Object,可以进行细分到各种`Built-in Object`

   **基本数据类型的值是按值访问的。**

   **引用类型的值是按引用访问的。**

   Notes:

   >  Note that the *simple primitives* (`string`, `number`, `boolean`, `null`, and `undefined`) are **not** themselves `objects`. `null` is sometimes referred to as an object type, but this misconception stems from a bug in the language which causes `typeof null` to return the string `"object"` incorrectly (and confusingly). In fact, `null` is its own primitive type.

   **It's a common mis-statement that "everything in JavaScript is an object". This is clearly not true.**

   *complex primitives*:

   `function`: It is a sub-type of object (technically, a "callable object"). Functions in JS are said to be "first class" in that they are basically just normal objects (with callable behavior semantics bolted on), and so they can be handled like any other plain object.

   `Array `: Arrays are also a form of objects, with extra behavior. The organization of contents in arrays is slightly more structured than for general objects.

3. Built-in Objects

   kinds:

   -  `String`
   -  `Number`
   -  `Boolean`
   -  `Object`
   -  `Function`
   -  `Array`
   -  `Date`
   -  `RegExp`
   -  `Error`

   These built-ins have the appearance of being actual types, even classes, if you rely on the similarity to other languages such as Java's `String` class.

   But in JS, these are actually just built-in functions. Each of these built-in functions can be used as a constructor (that is, a function call with the `new` operator -- see Chapter 2), with the result being a newly *constructed* object of the sub-type in question. 

   exp1:

   ```javascript
   var strPrimitive = "I am a string";
   typeof strPrimitive;							// "string"
   strPrimitive instanceof String;					// false

   var strObject = new String( "I am a string" );
   typeof strObject; 								// "object"
   strObject instanceof String;					// true

   // inspect the object sub-type
   Object.prototype.toString.call( strObject );	// [object String]
   ```

   >  The primitive value `"I am a string"` is not an object, it's a primitive literal and immutable value. To perform operations on it, such as checking its length, accessing its individual character contents, etc, a `String` object is required.

   >  Luckily, the language automatically coerces a `"string"` primitive to a `String` object when necessary, which means you almost never need to explicitly create the Object form. It is **strongly preferred** by the majority of the JS community to use the literal form for a value, where possible, rather than the constructed object form.

   >  In both cases, we call a property or method on a string primitive, and the engine automatically coerces it to a `String`object, so that the property/method access works.

   Number, Boolean (The same sort of coercion happens too)

   >  `null` and `undefined` have no object wrapper form, only their primitive values. By contrast, `Date` values can *only* be created with their constructed object form, as they have no literal form counter-part.

   >  `Object`s, `Array`s, `Function`s, and `RegExp`s (regular expressions) are all objects regardless of whether the literal or constructed form is used. The constructed form does offer, in some cases, more options in creation than the literal form counterpart. Since objects are created either way, the simpler literal form is almost universally preferred.

   **Only use the constructed form if you need the extra options.**

4. contents

   notes:

   >  It's important to note that while we say "contents" which implies that these values are *actually* stored inside the object, that's merely an appearance. The engine stores values in implementation-dependent ways, and may very well not store them *in* some object container. What *is* stored in the container are these property names, which act as pointers (technically, *references*) to where the values are stored.

   exp:

   ```javascript
   var myObject = {
   	a: 2
   };

   myObject.a;		// 2

   myObject["a"];	// 2
   ```

   diff:

   >  The main difference between the two syntaxes is that the `.` operator requires an `Identifier` compatible property name after it, whereas the `[".."]` syntax can take basically any UTF-8/unicode compatible string as the name for the property. 
   >
   >  To reference a property of the name "Super-Fun!", for instance, you would have to use the `["Super-Fun!"]` access syntax, as `Super-Fun!` is not a valid `Identifier` property name.
   >
   >  Also, since the `[".."]` syntax uses a string's **value** to specify the location, this means the program can programmatically build up the value of the string, such as:

   ```javascript
   var wantA = true;
   var myObject = {
   	a: 2
   };

   var idx;

   if (wantA) {
   	idx = "a";
   }

   // later

   console.log( myObject[idx] ); // 2
   ```

   notes:

   >  In objects, property names are **always** strings. If you use any other value besides a `string` (primitive) as the property, it will first be converted to a string. 
   >
   >  This even includes numbers, which are commonly used as array indexes, so be careful not to confuse the use of numbers between objects and arrays.

   ```javascript
   var myObject = { };

   myObject[true] = "foo";
   myObject[3] = "bar";
   myObject[myObject] = "baz";

   myObject["true"];				// "foo"
   myObject["3"];					// "bar"
   myObject["[object Object]"];	// "baz"
   ```

5. Computed Property Names (计算型属性名)

   exp:

   -  ES6 adds *computed property names*, where you can specify an expression, surrounded by a `[ ]` pair, in the key-name position of an object-literal declaration

   ```javascript
   var prefix = "foo";

   var myObject = {
   	[prefix + "bar"]: "hello",
   	[prefix + "baz"]: "world"
   };

   myObject["foobar"]; // hello
   myObject["foobaz"]; // world
   ```

   The most common usage of *computed property names* will probably be for ES6 `Symbol`s, which we will not be covering in detail in this book. In short, they're a new primitive data type which has an opaque unguessable value (technically a `string` value). You will be strongly discouraged from working with the *actual value* of a `Symbol` (which can theoretically be different between different JS engines), so the name of the `Symbol`, like `Symbol.Something` (just a made up name!), will be what you use:

   ```javascript
   var myObject = {
   	[Symbol.Something]: "hello world"
   };
   ```

6. Property vs. Method

   >The safest conclusion is probably that "function" and "method" are interchangeable in JavaScript.

7. Arrays

   >  Arrays also use the `[ ]` access form, but as mentioned above, they have slightly more structured organization for how and where values are stored (though still no restriction on what *type* of values are stored). Arrays assume *numeric indexing*, which means that values are stored in locations, usually called *indices*, at non-negative integers, such as `0` and `42`.

   数组也是对象，所以即便每个索引都是正整数，你还可以在数组上添加属性:

   ```javascript
   var myArray = [ "foo", 42, "bar" ];

   myArray.baz = "baz";

   myArray.length;	// 3

   myArray.baz;	// "baz"
   ```

   Notice that adding named properties (regardless of `.` or `[ ]` operator syntax) does not change the reported `length` of the array.

   **Be careful:** If you try to add a property to an array, but the property name *looks* like a number, it will end up instead as a numeric index (thus modifying the array contents):

   ```javascript
   var myArray = [ "foo", 42, "bar" ];

   myArray["3"] = "baz";

   myArray.length;	// 4

   myArray[3];		// "baz"
   ```

8. Duplicating Objects

   >  What exactly should be the representation of a *copy* of `myObject`?

   Firstly, we should answer if it should be a *shallow* or *deep* copy.

   **Shallow** & **Deep**:

   -  A *shallow copy* would end up with `a` on the new object as a copy of the value `2`, but `b`, `c`, and `d` properties as just references to the same places as the references in the original object. 
   -  A *deep copy* would duplicate not only `myObject`, but `anotherObject` and `anotherArray`.

   ```javascript
   function anotherFunction() { /*..*/ }

   var anotherObject = {
   	c: true
   };

   var anotherArray = [];

   var myObject = {
   	a: 2,
   	b: anotherObject,	// reference, not a copy!
   	c: anotherArray,	// another reference!
   	d: anotherFunction
   };

   anotherArray.push( anotherObject, myObject );
   ```

   >   Should we detect a circular reference and just break the circular traversal (leaving the deep element not fully duplicated)? Should we error out completely? Something in between?
   >
   >  Moreover, it's not really clear what "duplicating" a function would mean? 

   1. One subset solution is that objects which are JSON-safe (that is, can be serialized to a JSON string and then re-parsed to an object with the same structure and values) can easily be *duplicated* with:

      `var new Obj = JSON.parse(JSON.stringify(someObj))`

      Of course, that requires you to ensure your object is JSON safe. For some situations, that's trivial. For others, it's insufficient.

   2. `Object.assign({}, obj1)` in ES 6

      `Object.assign(..)` takes a *target* object as its first parameter, and one or more *source* objects as its subsequent parameters.

      The duplication that occurs for `Object.assign(..)` however is purely `=` style assignment, so any special characteristics of a property (like `writable`) on a source object **are not preserved** on the target object.

9. Property Descriptors  属性描述符

   >  Prior to ES5, the JavaScript language gave no direct way for your code to inspect or draw any distinction between the characteristics of properties, such as whether the property was read-only or not.

   After ES5:

   ```javascript
   var myObject = {
   	a: 2
   };

   Object.getOwnPropertyDescriptor( myObject, "a" );
   // {
   //    value: 2,
   //    writable: true,
   //    enumerable: true,
   //    configurable: true
   // }
   ```

   While we can see what the default values for the property descriptor characteristics are when we create a normal property, we can use `Object.defineProperty(..)` to add a new property, or modify an existing one (if it's `configurable`!), with the desired characteristics.

   ```javascript
   var myObject = {};

   Object.defineProperty( myObject, "a", {
   	value: 2,
   	writable: true,
   	configurable: true,
   	enumerable: true
   } );

   myObject.a; // 2
   ```

   Using `defineProperty(..)`, we added the plain, normal `a` property to `myObject` in a manually explicit way. **However, you generally wouldn't use this manual approach unless you wanted to modify one of the descriptor characteristics from its normal behavior.**

   -  Writable

      >  The ability for you to change the value of a property is controlled by `writable`.

      ```javascript
      "use strict";

      var myObject = {};

      Object.defineProperty( myObject, "a", {
      	value: 2,
      	writable: false, // not writable!
      	configurable: true,
      	enumerable: true
      } );

      myObject.a = 3; // TypeError
      ```

      `writable:false` means a value cannot be changed, which is somewhat equivalent to if you defined a no-op setter. Actually, your no-op setter would need to throw a `TypeError` when called, to be truly conformant to `writable:false`.

   -  Configurable

      >  As long as this property is currently configurable, we can modify its descriptor definition, using the same `defineProperty(..)` utility

      ```javascript
      var myObject = {
      	a: 2
      };

      myObject.a = 3;
      myObject.a;					// 3

      Object.defineProperty( myObject, "a", {
      	value: 4,
      	writable: true,
      	configurable: false,	// not configurable!
      	enumerable: true
      } );

      myObject.a;					// 4
      myObject.a = 5;
      myObject.a;					// 5

      Object.defineProperty( myObject, "a", {
      	value: 6,
      	writable: true,
      	configurable: true,
      	enumerable: true
      } ); // TypeError
      ```

      Be careful: as you can see, changing `configurable` to `false` is a **one-way action, and cannot be undone!**

      **Note:** There's a nuanced exception to be aware of: even if the property is already `configurable:false`, `writable`can always be changed from `true` to `false` without error, but not back to `true` if already `false`.

      -  **Another thing `configurable:false` prevents is the ability to use the `delete` operator to remove an existing property.**

      ```javascript
      var myObject = {
      	a: 2
      };

      myObject.a;				// 2
      delete myObject.a;
      myObject.a;				// undefined

      Object.defineProperty( myObject, "a", {
      	value: 2,
      	writable: true,
      	configurable: false,
      	enumerable: true
      } );

      myObject.a;				// 2
      delete myObject.a;
      myObject.a;				// 2
      ```

      -  But, it is **not** proper to think of `delete` as a tool to free up allocated memory as it does in other languages (like C/C++). `delete` is just an object property removal operation -- nothing more.

   -  Enumerable

      >  The name probably makes it obvious, but this characteristic controls if a property will show up in certain object-property enumerations, such as the `for..in` loop. Set to `false` to keep it from showing up in such enumerations, even though it's still completely accessible. Set to `true` to keep it present.

10. Immutability 不可变性

   >  It's important to note that **all** of these approaches create **shallow **immutability. That is, they affect only the object and its direct property characteristics. If an object has a reference to another object (array, object, function, etc), the *contents* of that object are not affected, and remain mutable.

   others:

   ```javascript
   var myObject = {
   	a: 2
   };

   Object.preventExtensions( myObject );

   myObject.b = 3;
   myObject.b; // undefined
   // In non-strict mode, the creation of b fails silently. In strict mode, it throws a TypeError.
   ```

   -  Object Constant		By combining `writable:false` and `configurable:false`

   -  Prevent Extensions     call `Object.preventExtensions(..)`

   -  `Object.seal(..)` creates a "sealed" object, which means it takes an existing object and essentially calls `Object.preventExtensions(..)` on it, but also marks all its existing properties as `configurable:false`.

      So, not only can you not add any more properties, but you also cannot reconfigure or delete any existing properties (thoughyou can still **modify their values)**.

   -  `Object.freeze(..)` creates a frozen object, which means it takes an existing object and essentially calls `Object.seal(..)` on it, but it also marks all "data accessor" properties as `writable:false`, so that their values cannot be changed.

11. [[Get]]

    ```javascript
    var myObject = {
    	a: 2
    };

    myObject.a; // 2
    ```

    According to the spec, the code above actually performs a `[[Get]]` operation (kinda like a function call: `[[Get]]()`) on the `myObject`. The default built-in `[[Get]]` operation for an object *first* inspects the object for a property of the requested name, and if it finds it, it will return the value accordingly.

    if it cannot through any means come up with a value for the requested property, it instead returns the value `undefined`.

12. [[Put]]

    If the property is present, the `[[Put]]` algorithm will roughly check:

    1. Is the property an accessor descriptor (see "Getters & Setters" section below)? **If so, call the setter, if any.**
    2. Is the property a data descriptor with `writable` of `false`? **If so, silently fail in non-strict mode, or throw TypeError in strict mode.**
    3. Otherwise, set the value to the existing property as normal.

13. Getters & Setters

    The default `[[Put]]` and `[[Get]]` operations for objects completely control how values are set to existing or new properties, or retrieved from existing properties, respectively.

    >  当你将一个属性定义为拥有getter或setter或两者兼备，那么它的定义就成为了“访问器描述符”（与“数据描述符”相对）。对于访问器描述符，它的`value`和`writable`性质没有意义而被忽略，取而代之的是JS将会考虑属性的`set`和`get`性质（还有`configurable`和`enumerable`）。

    ```javascript
    var myObject = {
    	// define a getter for `a`
    	get a() {
    		return 2;
    	}
    };

    Object.defineProperty(
    	myObject,	// target
    	"b",		// property name
    	{			// descriptor
    		// define a getter for `b`
    		get: function(){ return this.a * 2 },

    		// make sure `b` shows up as an object property
    		enumerable: true
    	}
    );

    myObject.a; // 2

    myObject.b; // 4
    ```

    >  不管是通过在字面对象语法中使用`get a() { .. }`，还是通过使用`defineProperty(..)`明确定义，我们都在对象上创建了一个没有实际持有值的属性，访问它们将会自动地对getter函数进行隐藏的函数调用，其返回的任何值就是属性访问的结果。
    >
    >  access automatically results in a hidden function call to the getter function, with whatever value it returns being the result of the property access.

    >  You will almost certainly want to always declare both getter and setter (having only one or the other often leads to unexpected/surprising behavior)s

    ```javascript
    var myObject = {
    	// 为`a`定义getter
    	get a() {
    		return this._a_;
    	},

    	// 为`a`定义setter
    	set a(val) {
    		this._a_ = val * 2;
    	}
    };

    myObject.a = 2;

    myObject.a; // 4
    ```

14. Existence    存在性

    引论: We showed earlier that a property access like `myObject.a` may result in an `undefined` value if either the explicit `undefined` is stored there or the `a` property doesn't exist at all.

    >  我们可以查询一个对象是否拥有特定的属性，而不必取得那个属性的值
    >
    >  ```javascript
    >  var myObject = {
    >  	a: 2
    >  };
    >
    >  ("a" in myObject);				// true
    >  ("b" in myObject);				// false
    >
    >  myObject.hasOwnProperty( "a" );	// true
    >  myObject.hasOwnProperty( "b" );	// false
    >  ```

    The `in` operator will check to see if the property is *in* the object, or if it exists at any higher level of the `[[Prototype]]` chain object traversal.

    By contrast, `hasOwnProperty(..)` checks to see if *only*`myObject` has the property or not, and will *not* consult the `[[Prototype]]` chain. 

    **注意：** `in`操作符看起来像是要检查一个值在容器中的存在性，但是它实际上检查的是属性名的存在性。在使用数组时注意这个区别十分重要，因为我们会有很强的冲动来进行`4 in [2, 4, 6]`这样的检查，但是这总是不像我们想象的那样工作。

15. 枚举（Enumeration）

    ```javascript
    var myObject = { };

    Object.defineProperty(
    	myObject,
    	"a",
    	// 使`a`可枚举，如一般情况
    	{ enumerable: true, value: 2 }
    );

    Object.defineProperty(
    	myObject,
    	"b",
    	// 使`b`不可枚举
    	{ enumerable: false, value: 3 }
    );

    myObject.b; // 3
    ("b" in myObject); // true
    myObject.hasOwnProperty( "b" ); // true

    // .......

    for (var k in myObject) {
    	console.log( k, myObject[k] );
    }
    // "a" 2
    ```

    That's because "enumerable" basically means "will be included if the object's properties are iterated through".

    ​