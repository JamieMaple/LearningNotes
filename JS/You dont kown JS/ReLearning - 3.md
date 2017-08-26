# ReLearning - 3

### Mixing (Up) "Class" Objects

### 类理论

>  "Class/Inheritance" describes a certain form of code organization and architecture -- a way of modeling real world problem domains in our software.

OO或者面向类的编程强调数据和操作它的行为之间有固有的联系（当然，依数据的类型和性质不同而不同！），所以合理的设计是将数据和行为打包在一起（也称为封装）。这有时在正式的计算机科学中称为“数据结构”。

任何给定的字符串都是这个类的一个实例，这个类是一个整齐的集合包装：字符数据和我们可以对它进行的操作功能。

类理论强烈建议父类和子类对相同的行为共享同样的方法名，以便于子类（差异化地）覆盖父类。我们即将看到，**在你的JavaScript代码中这么做会导致种种困难和脆弱的代码。**

-  “过程式编程（procedural programming）”：一种不用任何高级抽象，仅仅由过程（也就是函数）调用其他函数来构成的描述代码的方式。

-  “函数式编程（functional programming）”

-  ###JS实际上 没有类

   语法糖和（极其广泛被使用的）JS“Class”库废了很大力气来把这些真实情况对你隐藏起来，但你迟早会面对现实：你在其他语言中遇到的 *类* 和你在JS中模拟的“类”不同。

### Class Mechanics  类机制

**This object is a copyof all the characteristics described by the class.**

**对象是所有在类中被描述的特性的 拷贝**

### Constructor   构造器

>  Instances of classes are constructed by a special method of the class, usually of the same name as the class, called a *constructor*. This method's explicit job is to initialize any information (state) the instance will need.

###Class Inheritance   类继承 

>  In class-oriented languages, not only can you define a class which can be instantiated itself, but you can define another class that **inherits** from the first class.
>
>  The second class is often said to be a "child class" whereas the first is the "parent class". 

### Polymorphism   多态

>  If the child "overrides" a method it inherits, both the original and overridden versions of the method are actually maintained, so that they are both accessible. 
>
>  **Class inheritance implies copies.**

### Multiple Inheritance   多重继承

存在各种各样的问题

相比之下， JavaScript 要简单得多：它本身并不提供“多重继承”功能。

 ### 混合（Mixin）

在继承或者实例化时， JavaScript 的对象机制并不会 自动 执行复制行为。一个对象并不会被复制到其他对 象，它们会被 关联起来。

1. 显式混入（Explicit Mixins）

   ```javascript
   // 大幅简化的`mixin(..)`示例：
   function mixin( sourceObj, targetObj ) {
   	for (var key in sourceObj) {
   		// 仅拷贝非既存内容
   		if (!(key in targetObj)) {
   			targetObj[key] = sourceObj[key];
   		}
   	}

   	return targetObj;
   }

   var Vehicle = {
   	engines: 1,

   	ignition: function() {
   		console.log( "Turning on my engine." );
   	},

   	drive: function() {
   		this.ignition();
   		console.log( "Steering and moving forward!" );
   	}
   };

   var Car = mixin( Vehicle, {
   	wheels: 4,

   	drive: function() {
   		Vehicle.drive.call( this );
   		console.log( "Rolling on all " + this.wheels + " wheels!" );
   	}
   } );
   ```

   -  重温多态

      `Vehicle.drive.call( this )`。我将之称为“显式假想多态（explicit pseudo-polymorphism）”。回想我们前一段假想代码的这一行是我们称之为“相对多态（relative polymorphism）”的`inherited:drive()`

      使用伪多态通常会导致代码变得更加复杂、难以阅读 并且 难以维护，因此应当**尽量避免使用显式伪多态**，因为这样做往往得不偿失。

   -  混合拷贝（Mixing Copies）

      ```javascript
      // 另一种mixin，对覆盖不太“安全”
        function mixin( sourceObj, targetObj ) {
        	for (var key in sourceObj) {
        		targetObj[key] = sourceObj[key];
        	}

        	return targetObj;
        }

        var Vehicle = {
        	// ...
        };

        // 首先，创建一个空对象
        // 将Vehicle的内容拷贝进去
        var Car = mixin( Vehicle, { } );

        // 现在拷贝Car的具体内容
        mixin( {
        	wheels: 4,

        	drive: function() {
        		// ...
        	}
        }, Car );
      ```

      由于两个对象还共享它们的共通函数的引用，这意味着 **即便手动将函数从一个对象拷贝（也就是混入）到另一个对象中，也不能 实际上模拟 发生在面向类的语言中的从类到实例的真正的复制**。

      JavaScript函数不能真正意义上地被复制，所以你最终得到的是同一个共享的函数对象的 **被复制的引用**


   -  寄生继承（Parasitic Inheritance）

      明确的mixin模式的一个变种，在某种意义上是明确的而在某种意义上是隐含的，称为“寄生继承（Parasitic Inheritance）”，它主要是由Douglas Crockford推广的

      ```javascript
      // “传统的JS类” `Vehicle`
      function Vehicle() {
      	this.engines = 1;
      }
      Vehicle.prototype.ignition = function() {
      	console.log( "Turning on my engine." );
      };
      Vehicle.prototype.drive = function() {
      	this.ignition();
      	console.log( "Steering and moving forward!" );
      };

      // “寄生类” `Car`
      function Car() {
      	// 首先, `car`是一个`Vehicle`
      	var car = new Vehicle();

      	// 现在, 我们修改`car`使它特化
      	car.wheels = 4;

      	// 保存一个`Vehicle::drive()`的引用
      	var vehDrive = car.drive;

      	// 覆盖 `Vehicle::drive()`
      	car.drive = function() {
      		vehDrive.call( this );
      		console.log( "Rolling on all " + this.wheels + " wheels!" );
      	};

      	return car;
      }

      var myCar = new Car();

      myCar.drive();
      // Turning on my engine.
      // Steering and moving forward!
      // Rolling on all 4 wheels!

      // 如你所见，我们一开始从“父类”（对象）Vehicle制造了一个定义的拷贝，之后将我们的“子类”（对象）定义混入其中（按照需要保留父类的引用），最后将组合好的对象car作为子类实例传递出去。
      ```

      当我们调用`new Car()`时，一个新对象被创建并被`Car`的`this`所引用（见第二章）。但是由于我们没有使用这个对象，而是返回我们自己的`car`对象，所以这个初始化创建的对象就被丢弃了。所以，`Car()`可以不用`new`关键字调用，就可以实现和上面代码相同的功能，而且还可以节省对象的创建和回收。

2. 隐含的 Mixin（Implicit Mixins）

   ```javascript
   var Something = {
   	cool: function() {
   		this.greeting = "Hello World";
   		this.count = this.count ? this.count + 1 : 1;
   	}
   };

   Something.cool();
   Something.greeting; // "Hello World"
   Something.count; // 1

   var Another = {
   	cool: function() {
   		// 隐式地将`Something`混入`Another`
   		Something.cool.call( this );
   	}
   };

   Another.cool();
   Another.greeting; // "Hello World"
   Another.count; // 1 (不会和`Something`共享状态)
   ```

   `Something.cool.call( this )`既可以在“构造器”调用中使用（最常见的情况），也可以在方法调用中使用（如这里所示），我们实质上“借用”了`Something.cool()`函数并在`Another`环境下，而非`Something`环境下调用它（通过`this`绑定，见第二章）。结果是，`Something.cool()`中进行的赋值被实施到了`Another`对象而非`Something`对象。

   那么，这就是说我们将`Something`的行为“混入”了`Another`。

   一般来说，**尽量避免使用这种结构** 来保持代码干净而且容易维护。

### Review

1. 类是一种设计模式。许多语言提供语法来启用自然而然的面向类的软件设计。JS也有相似的语法，但是它的行为和你在其他语言中熟悉的工作原理 **有很大的不同**。

   **类意味着拷贝。**

2. 当一个传统的类被实例化时，就发生了类的行为向实例中拷贝。当类被继承时，也发生父类的行为向子类的拷贝。

3. 多态（在继承链的不同层级上拥有同名的不同函数）也许看起来意味着一个从子类回到父类的相对引用链接，但是它仍然只是拷贝行的结果。

   JavaScript **不会自动地** （像类那样）在对象间创建拷贝。

4. mixin模式常用于在 *某种程度上* 模拟**类的拷贝行为**，但是这通常导致像显式假想多态那样(`OtherObj.methodName.call(this, ...)`)难看而且脆弱的语法，这样的语法又常导致更难懂和更难维护的代码。

5. 明确的mixin和类 *拷贝* 又不完全相同，因为对象（和函数！）仅仅是共享的引用被复制，不是对象/函数自身被复制。不注意这样的微小之处通常是各种陷阱的根源。

一般来讲，在JS中模拟类通常会比解决当前 *真正* 的问题埋下更多的坑。

### 原型（Prototype）

1. [[Prototype]]

   JavaScript中的对象有一个内部属性，在语言规范中称为`[[Prototype]]`，它只是一个其他对象的引用。几乎所有的对象在被创建时，它的这个属性都被赋予了一个非`null`值

   ```javascript
   var anotherObject = {
   	a: 2
   };

   // 创建一个链接到`anotherObject`的对象
   var myObject = Object.create( anotherObject );

   myObject.a; // 2
   ```

   1. 它创建了一个对象，这个对象带有一个链到指定的对象的`[[Prototype]]`链接
   2. `myObject``[[Prototype]]`链到了`anotherObject`。虽然很明显`myObject.a`实际上不存在，但是无论如何属性访问成功了（在`anotherObject`中找到了），而且确实找到了值`2`
   3. 但是，如果在`anotherObject`上也没有找到`a`，而且如果它的`[[Prototype]]`链不为空，就沿着它继续查找
   4. 这个处理持续进行，直到找到名称匹配的属性，或者`[[Prototype]]`链终结。如果在链条的末尾都没有找到匹配的属性，那么`[[Get]]`操作的返回结果为`undefined`
   5. 如果你使用`for..in`循环迭代一个对象，所有在它的链条上可以到达的属性都会被枚举。如果你使用`in`操作符来测试一个属性在一个对象上的存在性，`in`将会检查对象的整个链条（不管 *可枚举性*）。

2. Object.prototype

   -  每个 *普通* 的`[[Prototype]]`链的最顶端，是内建的`Object.prototype`。这个对象包含各种在整个JS中被使用的共通工具，因为JavaScript中所有普通（内建，而非被宿主环境扩展的）的对象都“衍生自”（也就是，使它们的`[[Prototype]]`顶端为）`Object.prototype`对象

3. 设置与遮蔽属性

   -  如果属性名`foo`同时存在于`myObject`本身和从`myObject`开始的`[[Prototype]]`链的更高层，这样的情况称为 *遮蔽*

   -  `myObject.foo = "bar"`赋值的三种场景当`foo` **不直接存在** 于`myObject`，但 **存在** 于`myObject`的`[[Prototype]]`链的更高层:

      1. 如果一个普通的名为`foo`的数据访问属性在`[[Prototype]]`链的高层某处被找到，**而且没有被标记为只读（writable:false）**，那么一个名为`foo`的新属性就**直接添加到`myObject`上，形成一个 遮蔽属性**。
      2. 如果一个`foo`在`[[Prototype]]`链的高层某处被找到，但是它被标记为 **只读（writable:false）** ，那么设置既存属性和在`myObject`上创建遮蔽属性都是 **不允许** 的。如果代码运行在`strict mode`下，一个错误会被抛出。否则，这个设置属性值的操作会被无声地忽略。不论怎样，**没有发生遮蔽**。
      3. 如果一个`foo`在`[[Prototype]]`链的高层某处被找到，而且它是一个setter（见第三章），那么这个setter总是被调用。没有`foo`会被添加到（也就是遮蔽在）`myObject`上，这个`foo`setter也不会被重定义。

      如果你想在第二和第三种情况中遮蔽`foo`，那你就不能使用`=`赋值，而必须使用`Object.defineProperty(..)`将`foo`添加到`myObject`。

      如果你需要在方法间进行委托，**方法** 的遮蔽会导致难看的 *显式假想多态*（见第四章）。一般来说，遮蔽与它带来的好处相比太过复杂和微妙了，**所以你应当尽量避免它**。

      ```javascript
      var anotherObject = {
      	a: 2
      };

      var myObject = Object.create( anotherObject );

      anotherObject.a; // 2
      myObject.a; // 2

      anotherObject.hasOwnProperty( "a" ); // true
      myObject.hasOwnProperty( "a" ); // false

      myObject.a++; // 噢，隐式遮蔽！

      anotherObject.a; // 2
      myObject.a; // 3

      myObject.hasOwnProperty( "a" ); // true
      ```

      虽然看起来`myObject.a++`应当（通过委托）查询并 *原地* 递增`anotherObject.a`属性，但是`++`操作符相当于`myObject.a = myObject.a + 1`。结果就是在`[[Prototype]]`上进行`a`的`[[Get]]`查询，从`anotherObject.a`得到当前的值`2`，将这个值递增1，然后将值`3`用`[[Put]]`赋值到`myObject`上的新遮蔽属性`a`上

4. JavaScript "Class"

   在JavaScript中，对于对象来说没有抽象模式/蓝图，即没有面向类的语言中那样的称为类的东西。JavaScript **只有** 对象。

   -  '类' 函数

      “某种程度的类”这种奇特的行为取决于函数的一个奇怪的性质：所有的函数默认都会得到一个公有的，不可枚举的属性，称为`prototype`，它可以指向任意的对象

      ```javascript
      function Foo() {
      	// ...
      }

      Foo.prototype; // { }
      // “以前被认为是Foo的原型的对象”
      // 一个被随意标记为‘Foo点儿原型’的对象
      ```

      1. 每个由调用`new Foo()`（见第二章）而创建的对象将最终（有些随意地）被`[[Prototype]]`链接到这个“Foo点儿原型”对象

      2. 在JavaScript中，没有这样的拷贝处理发生。你不会创建类的多个实例。你可以创建多个对象，它们的`[[Prototype]]`连接至一个共通对象。

         但默认地，没有拷贝发生，如此这些对象彼此间最终不会完全分离和切断关系，而是 **链接在一起**

      3. **结果我们得到两个对象，彼此链接**

         事实上，这个使大多数JS开发者无法理解的秘密，是因为`new Foo()`函数调用实际上几乎和建立链接的处理没有任何 *直接*关系。**它是某种偶然的副作用。**`new Foo()`是一个间接的，迂回的方法来得到我们想要的：**一个被链接到另一个对象的对象。**

      4. 更直接得到的方法 Object.create(..)

      在JavaScript中，我们不从一个对象（“类”）向另一个对象（“实例”） *拷贝*。我们在对象之间制造 *链接*。这种机制常被称为“原型继承（prototypal inheritance）”。

      “继承”意味着 *拷贝* 操作，而JavaScript不拷贝对象属性（原生上，默认地）。相反，JS在两个对象间建立链接，一个对象实质上可以将对属性/函数的访问 *委托* 到另一个对象上。对于描述JavaScript对象链接机制来说，“委托”是一个准确得多的术语。

      还有个偶尔会用到的 JavaScript 术语 差异继承 。基本原则是在描述对象行为时，使用其不同于 普遍描述的特质。举例来说，描述汽车时你会说汽车是有四个轮子的一种交通工具， 但是你不会重复描述交通工具具备的通用特性（比如引擎）。

      默认情况下，对象并不会像差异继承暗示的那样通过复制生成。因此，差异继承也不适合 用来描述 JavaScript 的 [[Prototype]] 机制。

   -  "构造器"（Constructors）

      ```javascript
      function Foo() {
      	// ...
      }

      Foo.prototype.constructor === Foo; // true

      var a = new Foo();
      a.constructor === Foo; // true
      ```

      这实际上不是真的。`a`上没有`.constructor`属性，而`a.constructor`确实解析成了`Foo`函数，“constructor”并不像它看起来的那样实际意味着“被XX创建”。

      函数自身**不是**构造器。但是，当你在普通函数调用前面放一个`new`关键字时，这就将函数调用变成了“构造器调用”。事实上，`new`在某种意义上劫持了普通函数并将它以另一种方式调用：构建一个对象，**外加这个函数要做的其他任何事**。

      ```javascript
      function NothingSpecial() {
      	console.log( "Don't mind me!" );
      }

      var a = new NothingSpecial();
      // "Don't mind me!"

      a; // {}
      ```

      `NothingSpecial`仅仅是一个普通的函数，但当用`new`调用时，几乎是一种副作用，它会 *构建* 一个对象，并被我们赋值到`a`。这个 **调用** 是一个 *构造器调用*，但是`NothingSpecial`本身并不是一个 *构造器*。

      换句话说，在JavaScript中，更合适的说法是，“构造器”是在前面 **用new关键字调用的任何函数**。函数不是构造器，但是当且仅当`new`被使用时，函数调用是一个“构造器调用”

   -  模拟面向类的机制

      ```javascript
      function Foo(name) {
      	this.name = name;
      }

      Foo.prototype.myName = function() {
      	return this.name;
      };

      var a = new Foo( "a" );
      var b = new Foo( "b" );

      a.myName(); // "a"
      b.myName(); // "b"
      ```

      1. `this.name = name`：在每个对象上添加了`.name`属性，和类的实例包装数据值很相似。
      2. `Foo.prototype.myName = ...`：这也许是更有趣的技术，它在`Foo.prototype`对象上添加了一个属性（函数）。

      `.constructor`不是一个魔法般不可变的属性。它是不可枚举的，但是它的值是可写的（可以改变），而且，你可以在`[[Prototype]]`链上的任何对象上添加或覆盖（有意或无意地）名为`constructor`的属性，用你感觉合适的任何值。

      `a1.constructor`是极其不可靠的，在你的代码中不应依赖的不安全引用。**一般来说，这样的引用应当尽量避免。**

   -  “（原型）继承”

      ```javascript
      unction Foo(name) {
      	this.name = name;
      }

      Foo.prototype.myName = function() {
      	return this.name;
      };

      function Bar(name,label) {
      	Foo.call( this, name );
      	this.label = label;
      }

      // 这里，我们创建一个新的`Bar.prototype`链接链到`Foo.prototype`
      Bar.prototype = Object.create( Foo.prototype );

      // 注意！现在`Bar.prototype.constructor`不存在了，
      // 如果你有依赖这个属性的习惯的话，可以被手动“修复”。

      Bar.prototype.myLabel = function() {
      	return this.label;
      };

      var a = new Bar( "a", "obj a" );

      a.myName(); // "a"
      a.myLabel(); // "obj a"
      ```

      以下方式存在误解:

      ```javascript
      // 不会如你期望的那样工作!
      Bar.prototype = Foo.prototype;

      // 会如你期望的那样工作
      // 但会带有你可能不想要的副作用 :(
      Bar.prototype = new Foo();
      ```

      -  `Bar.prototype = Foo.prototype`不会创建新对象让`Bar.prototype`链接。它只是让`Bar.prototype`成为`Foo.prototype`的另一个引用，将`Bar`直接链到`Foo`链着的 **同一个对象**：`Foo.prototype`。这意味着当你开始赋值时，比如`Bar.prototype.myLabel = ...`，你修改的 **不是一个分离的对象** 而是那个被分享的`Foo.prototype`对象本身，它将影响到所有链接到`Foo.prototype`的对象。
      -  `Bar.prototype = new Foo()`**确实** 创建了一个新的对象，这个新对象也的确链接到了我们希望的`Foo.prototype`。但是，它是用`Foo(..)`“构造器调用”来这样做的。如果这个函数有任何副作用（比如logging，改变状态，注册其他对象，**向this添加数据属性**，等等），这些副作用就会在链接时发生（而且很可能是对错误的对象！），而不是像可能希望的那样，仅最终在`Bar()`的“后代”被创建时发生
      -  使用`Object.create(..)`来制造一个新对象，这个对象被正确地链接，而且没有调用`Foo(..)`时所产生的副作用。一个轻微的缺点是，我们不得不创建新对象，并把旧的扔掉，而不是修改提供给我们的默认既存对象。
      -  ES6之前，有一个非标准的，而且不是完全对所有浏览器通用的方法：通过可以设置的`.__proto__`属性。ES6中增加了`Object.setPrototypeOf(..)`辅助工具，它提供了标准且可预见的方法。

      ```javascript
      // ES6以前
      // 扔掉默认既存的`Bar.prototype`
      Bar.prototype = Object.create( Foo.prototype );

      // ES6+
      // 修改既存的`Bar.prototype`
      Object.setPrototypeOf( Bar.prototype, Foo.prototype );
      ```

   -  "类"之间的关系

      考察一个实例（一个JS对象）的继承血统（在JS中是委托链接），在传统的面向类环境中称为 *自省（introspection）*（或 *反射（reflection）*）

      ```javascript
      function Foo() {
      	// ...
      }

      Foo.prototype.blah = ...;

      var a = new Foo();
      ```

      `instanceof`操作符的左边操作数接收一个普通对象，右边操作数接收一个 **函数**。`instanceof`回答的问题是：**在a的整个[[Prototype]]链中，有没有出现被那个被Foo.prototype所随便指向的对象？**

      不幸的是，这意味着如果你拥有可以用于测试的 **函数**（`Foo`，和它带有的`.prototype`引用），你只能查询某些对象（`a`）的“祖先”。如果你有两个任意的对象，比如`a`和`b`，而且你想调查是否 *这些对象* 通过`[[Prototype]]`链相互关联，单靠`instanceof`帮不上什么忙

      ```javascript
      Foo.prototype.isPrototypeOf( a ); // true
      ```

      注意在这种情况下，我们并不真正关心（甚至 *不需要*）`Foo`，我们仅需要一个 **对象**（在我们的例子中就是随意标志为`Foo.prototype`）来与另一个 **对象** 测试。`isPrototypeOf(..)`回答的问题是：**在a的整个[[Prototype]]链中，Foo.prototype出现过吗？**

      大多数浏览器（不是全部！）还一种长期支持的，非标准方法可以访问内部的`[[Prototype]]`：

      ```javascript
      a.__proto__ === Foo.prototype; // true
      ```

      这个奇怪的`.__proto__`（直到ES6才标准化！）属性“魔法般地”取得一个对象内部的`[[Prototype]]`作为引用

      和我们早先看到的`.constructor`一样，`.__proto__`实际上不存在于你考察的对象上。事实上，它存在于（不可枚举地）内建的`Object.prototype`上，和其他的共通工具在一起

      而且，`.__proto__`看起来像一个属性，但实际上将它看做是一个 getter/setter 更合适

      ```javascript
      Object.defineProperty( Object.prototype, "__proto__", {
      	get: function() {
      		return Object.getPrototypeOf( this );
      	},
      	set: function(o) {
      		// setPrototypeOf(..) as of ES6
      		Object.setPrototypeOf( this, o );
      		return o;
      	}
      } );
      ```

      所以，当我们访问`a.__proto__`（取得它的值）时，就好像调用`a.__proto__()`（调用getter函数）。虽然getter函数存在于`Object.prototype`上（参照第二章，`this`绑定规则），但这个函数调用将`a`用作它的`this`，所以它相当于在说`Object.getPrototypeOf( a )`

      `.__proto__`还是一个可设置的属性，就像早先展示过的ES6`Object.setPrototypeOf(..)`。然而，一般来说你 **不应该改变一个既存对象的[[Prototype]]**

5. ### 对象链接

   `[[Prototype]]`机制是一个内部链接，它存在于一个对象上，这个对象引用一些其他的对象。

   1. 创建链接

      `Object.create(..)`创建了一个链接到我们指定的对象（`foo`）上的新对象（`bar`），这给了我们`[[Prototype]]`机制的所有力量（委托），而且没有`new`函数作为类和构造器调用产生的任何没必要的复杂性，搞乱`.prototype`和`.constructor` 引用，或任何其他的多余的东西。

      **注意：** `Object.create(null)`创建一个拥有空（也就是`null`）`[[Prototype]]`链接的对象，如此这个对象不能委托到任何地方。 详见：Object.create(null) -> undefined

      因为这样的对象没有原形链，`instancof`操作符（前面解释过）没有东西可检查，所以它总返回`false`。

      由于他们典型的用途是在属性中存储数据，这种特殊的空`[[Prototype]]`对象经常被称为“dictionaries（字典）”，这主要是因为它们没有可能受到在`[[Prototype]]`链上任何委托属性/函数的影响，所以它们是纯粹的扁平数据存储。

      ```javascript
      if (!Object.create) {
      	Object.create = function(o) {
      		function F(){}
      		F.prototype = o;
      		return new F();
      	};
      }
      ```

      这个填补工具通过一个一次性的`F`函数并覆盖它的`.prototype`属性来指向我们想连接到的对象。之后我们用`new F()`构造器调用来制造一个将会链到我们指定对象上的新对象。

      ```javascript
      var anotherObject = {
      	cool: function() {
      		console.log( "cool!" );
      	}
      };

      var myObject = Object.create( anotherObject );

      myObject.doCool = function() {
      	this.cool(); // internal delegation!
      };

      myObject.doCool(); // "cool!"
      ```

      这里，我们调用`myObject.doCool()`，它是一个 *实际存在于* `myObject`上的方法，这使我们的API设计更清晰。*在它内部*，我们的实现依照 **委托设计模式**，利用`[[Prototype]]`委托到`anotherObject.cool()`。

   # Review

   1. 当试图在一个对象上进行属性访问，而对象没有该属性时，对象内部的`[[Prototype]]`链接定义了`[[Get]]`操作。下一步应当到哪里寻找它。这种对象到对象的串行链接定义了对象的“原形链”（和嵌套的作用域链有些相似），在解析属性时发挥作用。

   2. 所有普通的对象用内建的`Object.prototype`作为原形链的顶端（就像作用域查询的顶端是全局作用域），如果属性没能在链条的前面任何地方找到，属性解析就会在这里停止。`toString()`，`valueOf()`，和其他几种共同工具都存在于这个`Object.prototype`对象上，这解释了语言中所有的对象是如何能够访问他们的。

   3. 使两个对象相互链接在一起的最常见的方法是将`new`关键字与函数调用一起使用，在它的四个步骤中，就会建立一个新对象链接到另一个对象。

   4. 那个用`new`调用的函数有一个被随便地命名为`.prototype`的属性，这个属性所引用的对象恰好就是这个新对象链接到的“另一个对象”。带有`new`的函数调用通常被称为“构造器”，尽管实际上它们并没有像传统的面相类语言那样初始化一个类。

   5. 虽然这些JavaScript机制看起来和传统面向类语言的“初始化类”和“类继承”类似，而在JavaScript中的关键区别是，没有拷贝发生。取而代之的是对象最终通过`[[Prototype]]`链链接在一起。

   6. 由于各种原因，不光是前面提到的术语，“继承”（和“原型继承”）与所有其他的OO用语，在考虑JavaScript实际如何工作时都没有道理。

      相反，“委托”是一个更确切的术语，因为这些关系不是 *拷贝* 而是委托 **链接**。