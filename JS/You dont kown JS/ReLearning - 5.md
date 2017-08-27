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

   ​

