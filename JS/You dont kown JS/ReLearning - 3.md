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

      ​