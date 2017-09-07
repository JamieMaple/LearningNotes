# ReLearning - 7

### 异步

1. 事件轮询
2. 运行至完成，不会截断

### 并发(concurrency)

1. 非互动与互动
2. 协作并发
3. 重排与重绘

### 回调

1. 回调函数包装或封装了程序的 *延续*
2. 嵌套 / 链接的回调(Nested / Chained Callbacks)
3. 信任问题

### Promise 对象

1. Promise 是一种封装和组合未来值的易于复用的机制。

2. Promise 的决议结果可能是拒绝而不是完成。

3. 拒绝值和完成f的 Promise 不一样：完成值总是编程给出 的，而拒绝值，通常称为拒绝原因拒绝原因 （rejection reason），可能是程序逻辑直接设置的，也可能是从运行异常隐式得出的值。

4. 一旦 Promise 决议，它就永远保持在这个状态。此时它就成为了不变值（immutable value）。

5. Promise是一种用来包装与组合*未来值*，并且可以很容易复用的机制。

6. Promise 链式流

   ### Promise 模式 

   1. 顺序（sequence）模式：

      `new Promise((resolve, reject)=>{}).then(...).catch(...)...`

   2. 并发（parallel）模式

      `Promise.all([ .. ])`期待一个单独的参数，一个`array`，一般由Promise的实例组成。从`Promise.all([ .. ])`返回的promise将会收到完成的消息。

      从`Promise.resolve(..)`返回的主Promise将会在所有组成它的promise完成之后才会被完成。如果其中任意一个promise被拒绝，`Promise.all([ .. ])`的主Promise将立即被拒绝，并放弃所有其他promise的结果。

      要记得总是给每个promise添加拒绝/错误处理器，即使和特别是那个从`Promise.all([ .. ])`返回的promise

   3. 门闩（latch）/ 竞合（race）模式

      `Promise.race([ .. ])`将会在任意一个Promise解析为完成时完成，而且它会在任意一个Promise解析为拒绝时拒绝。

   4. 超时竞合

      ```javascript
      // `foo()`是一个兼容Promise

      // `timeoutPromise(..)`在早前定义过，
      // 返回一个在指定延迟之后会被拒绝的Promise

      // 为`foo()`设置一个超时
      Promise.race( [
      	foo(),					// 尝试`foo()`
      	timeoutPromise( 3000 )	// 给它3秒钟
      ] )
      .then(
      	function(){
      		// `foo(..)`及时地完成了！
      	},
      	function(err){
      		// `foo()`要么是被拒绝了，要么就是没有及时完成
      		// 可以考察`err`来知道是哪一个原因
      	}
      );
      ```

   5. 其他第三方库


### Promise API 总结

1. new Promise(..) Constructor
   -  The *revealing constructor* `Promise(..)` must be used with `new`
   -  must be provided a function callback that is synchronously/immediately called.
   -  function is passed two function callbacks that act as resolution capabilities for the promise. We commonly label these `resolve(..)` and `reject(..)`
2. Promise.resolve(..) and Promise.reject(..)
   -  A shortcut for creating an already-rejected Promise
3. then(..) and catch(..)
   -  `then(..)` takes one or two parameters, the first for the fulfillment callback, and the second for the rejection callback. If either is omitted or is otherwise passed as a non-function value, a default callback is substituted respectively. 
   -  `catch(..)` takes only the rejection callback as a parameter, and automatically substitutes the default fulfillment callback, as just discussed. In other words, it's equivalent to `then(null,..)`
   -  `then(..)` and `catch(..)` also create and return a new promise, which can be used to express Promise chain flow control. 
4. Promise.all([ .. ]) and Promise.race([ .. ])
   -  For `Promise.all([ .. ])`, all the promises you pass in must fulfill for the returned promise to fulfill. If any promise is rejected, the main returned promise is immediately rejected, too.
   -  For `Promise.race([ .. ])`, only the first promise to resolve (fulfillment or rejection) "wins," and whatever that resolution is becomes the resolution of the returned promise.
5. other libraries

### Promise 局限性

1. Sequence Error Handling
2. Single Value
3. Single Resolution
4. Inertia
5. Promise Uncancelable

### Generator

```javascript
function *foo(){...} // *的位置可以放前面，也可以省略前面的空格
yield // 表示运行到函数某个位置暂停
it.next() // 表示从暂停位置继续，第一个next()总是启动一个generator，
          // 然后运行至第一个yield。
          // 但是第二个next(..)调用满足了第一个暂停的yield表达式，
          // 而第三个next(..)将满足第二个yield，如此反复
```

