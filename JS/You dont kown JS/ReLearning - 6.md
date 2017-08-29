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

      ​

