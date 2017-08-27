# ReLearning - 4

### Behavior Delegation

当一个属性/方法引用在第一个对象上发生，而这样的属性/方法又不存在时，这个链接就会被使用。在这种情况下，`[[Prototype]]`链接告诉引擎去那个被链接的对象上寻找该属性/方法。接下来，如果那个对象也不能满足查询，就沿着它的`[[Prototype]]`查询，如此继续。这种对象间一系列的链接构成了所谓的“原形链”。

换句话说，对于我们能在JavaScript中利用的功能的实际机制来说，其重要的实质 **全部在于被连接到其他对象的对象。**

### Towards Delegation-Oriented Design

1. Delegation Theory

   You will first define an **object** (not a class, nor a `function` as most JS'rs would lead you to believe) called `Task`, and it will have concrete behavior on it that includes utility methods that various tasks can use (read: *delegate to*!). Then, for each task ("XYZ", "ABC"), you define an **object** to hold that task-specific data/behavior. You **link** your task-specific object(s) to the `Task` utility object, allowing them to delegate to it when they need to.

   ```javascript
   var Task = {
   	setID: function(ID) { this.id = ID; },
   	outputID: function() { console.log( this.id ); }
   };

   // 使`XYZ`委托到`Task`
   var XYZ = Object.create( Task );

   XYZ.prepareTask = function(ID,Label) {
   	this.setID( ID );
   	this.label = Label;
   };

   XYZ.outputTaskDetails = function() {
   	this.outputID();
   	console.log( this.label );
   };

   // ABC = Object.create( Task );
   // ABC ... = ...
   ```

   作为与面相类（也就是，OO——面相对象）的对比，我称这种风格的代码为 **“OLOO”**（objects-linked-to-other-objects（链接到其他对象的对象））。所有我们 *真正* 关心的是，对象`XYZ`委托到对象`Task`（对象`ABC`也一样）。

   注意的不同：

   1. 前一个类的例子中的`id`和`label`数据成员都是`XYZ`上的直接数据属性（它们都不在`Task`上）。一般来说，当`[[Prototype]]`委托引入时，**你想使状态保持在委托者上**（`XYZ`，`ABC`），不是在委托上（`Task`）。
   2. 在类的设计模式中，我们故意在父类（`Task`）和子类（`XYZ`）上采用相同的命名`outputTask`，以至于我们可以利用覆盖（多态）。在委托的行为中，我们反其道而行之：**我们尽一切可能避免在[[Prototype]]链的不同层级上给出相同的命名**（称为“遮蔽”），因为这些命名冲突会导致尴尬/脆弱的语法来消除引用的歧义（见第四章），而我们想避免它。 这种设计模式不那么要求那些倾向于被覆盖的泛化的方法名，而是要求针对于每个对象的 *具体* 行为类型给出更具描述性的方法名。**这实际上会产生更易于理解/维护的代码**，因为方法名（不仅在定义的位置，而是扩散到其他代码中）变得更加明白（代码即文档）。
   3. `this.setID(ID);`位于对象`XYZ`的一个方法内部，它首先在`XYZ`上查找`setID(..)`，但因为它不能在`XYZ`上找到叫这个名称的方法，`[[Prototype]]`委托意味着它可以沿着链接到`Task`来寻找`setID()`，这样当然就找到了。另外，由于调用点的隐含`this`绑定规则（见第二章），当`setID()`运行时，即便方法是在`Task`上找到的，这个函数调用的`this`绑定依然是我们期望和想要的`XYZ`。我们在代码稍后的`this.outputID()`中也看到了同样的事情。 换句话说，我们可以使用存在于`Task`上的泛化工具与`XYZ`互动，因为`XYZ`可以委托至`Task`。

   -  相互委托（不允许）

      因为引擎的实现者发现，在设置时检查（并拒绝！）无限循环引用一次，要比每次你在一个对象上查询属性时都做相同检查的性能要高。

   -  浏览器间调试不同

   -  OO vs. OLOO

      ```javascript
      function Foo(who) {
      	this.me = who;
      }
      Foo.prototype.identify = function() {
      	return "I am " + this.me;
      };

      function Bar(who) {
      	Foo.call( this, who );
      }
      Bar.prototype = Object.create( Foo.prototype );

      Bar.prototype.speak = function() {
      	alert( "Hello, " + this.identify() + "." );
      };

      var b1 = new Bar( "b1" );
      var b2 = new Bar( "b2" );

      b1.speak();
      b2.speak();
      ```

      推荐以下写法:

      ```javascript
      var Foo = {
      	init: function(who) {
      		this.me = who;
      	},
      	identify: function() {
      		return "I am " + this.me;
      	}
      };

      var Bar = Object.create( Foo );

      Bar.speak = function() {
      	alert( "Hello, " + this.identify() + "." );
      };

      var b1 = Object.create( Bar );
      b1.init( "b1" );
      var b2 = Object.create( Bar );
      b2.init( "b2" );

      b1.speak();
      b2.speak();
      ```

      两段代码间的思维模式图片

   -  全图

      ![img](./imgs/mental-models.png)

   -  fair

      ![img](./imgs/mental-models-fair.png)

   -  OLOO

      ![img](imgs/mental-models-OLOO.png)

2. Object vs. Class

   先说es6的 class 语法糖

   ​