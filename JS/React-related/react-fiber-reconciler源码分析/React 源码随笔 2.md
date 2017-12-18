# React 源码随笔 2

1. ReactChildren

   惯例几个包引入：fbjs以及前面的 `ReactElement` 和 `ReactDebugCurrentFrame` 以及以下几个常量

   ```javascript
   // 几个常量
   var ITERATOR_SYMBOL, FAUX_ITERATOR_SYMBOL, REACT_ELEMENT_TYPE, REACT_PORTAL_TYPE, SEPARATOR, SUBSEPARATOR
   ```

   -  一个处理编码安全问题的Reactid内部函数 — escape()，还有一个获取 `componentKey` 的函数

   ```javascript
   function escape(key) {
     var escapeRegex = /[=:]/g;
     var escaperLookup = {
       '=': '=0',
       ':': '=2',
     }
     var escapedString = ('' + key).replace(escapeRegex, function(match) {
       return escaperLookup[match];
     })
     return '$' + escapedString
   }
   ```

   =.= fb 还有一个 TODO 没有写吧：测试单孩子或者只有一个孩子数组是否有相同的key

   -  正则表达式解决用户输入/转义一下

   ```javascript
   var userProvidedKeyEscapeRegex = /\/+/g;
   function escapeUserProvidedKey(text) {
     return ('' + text).replace(userProvidedKeyEscapeRegex, '$&/');
   }
   ```

   -   contextPool

      ```javascript
      var POOL_SIZE = 10;
      var traverseContextPool = [];
      function getPooledTraverseContext(
        mapResult,
        keyPrefix,
        mapFunction,
        mapContext,
      ) {
        if (traverseContextPool.length) {
          var traverseContext = traverseContextPool.pop()
          traverseContext.result = mapResult
          traverseContext.keyPrefix = keyPrefix
          traverseContext.func = mapFunction
          traverseContext.context = mapContext
          traverseContext.count = 0
          return traverseContext
        } else {
          return {
            result: mapResult,
            keyPrefix: keyPrefix,
            func: mapFunction,
            context: mapContext,
            count: 0,
          }
        }
      }

      function releaseTraverseContext(traverseContext) {
        traverseContext.result = null
        traverseContext.keyPrefix = null
        traverseContext.func = null
        traverseContext.context = null
        traverseContext.count = 0
        if (traverseContextPool.length < POOL_SIZE) {
          traverseContextPool.push(traverseContext)
        }
      ```

      这里的两个函数名如其作用，大概意思应该就是对上下文栈的获取以及释放(也就是返还给上下文栈)。

      这个上下文栈总大小为 10，然后调用一次 `getPooledTraverseContext` 可以得到一个上下文对象还包括有一个 `count` 计数器。

      我们可以在后续的方法调用中看到，`getPooledTraverseContext` 和 `releaseTraverseContext` 成对成对地出现了 2 次而且同时伴随着 `traverseAllChildren` 的调用，分别在 `forEachChildren` 和 `mapIntoWithKeyPrefixInternal`  中。 对于很多子节点而言的树，这么做能够减轻开销每次创建对象的成本。。。fb 优化真的是无所不用其极。。。

      `releaseTraverseContext` 作用是释放当前的上下文，赋值成 null 通知 gc，同时将其放入 `traverseContextPool`，就保留原始对象结构。

   -  五个导出的方法

      ```javascript
      export {
        forEachChildren as forEach,
        mapChildren as map,
        countChildren as count,
        onlyChild as only,
        toArray,
      }
      ```

      `React` 官网：

      >  #### `React.Children.map` 
      >
      >  Invokes a function on every immediate child contained within `children` with `this` set to `thisArg`. If `children` is a keyed fragment or array it will be traversed: the function will never be passed the container objects. If children is `null` or `undefined`, returns `null` or `undefined` rather than an array.
      >
      >  #### `React.Children.forEach`
      >
      >  Like [`React.Children.map()`](https://reactjs.org/docs/react-api.html#reactchildrenmap) but does not return an array.
      >
      >  #### `React.Children.count`
      >
      >  Returns the total number of components in `children`, equal to the number of times that a callback passed to `map` or `forEach` would be invoked.
      >
      >  #### `React.Children.only`
      >
      >  Verifies that `children` has only one child (a React element) and returns it. Otherwise this method throws an error.

      1. `forEachChildren`

         ```javascript
         function forEachChildren(children, forEachFunc, forEachContext) {
           if (children == null) {
             return children
           }
           var traverseContext = getPooledTraverseContext(
             null,
             null,
             forEachFunc,
             forEachContext,
           )
           traverseAllChildren(children, forEachSingleChild, traverseContext)
           releaseTraverseContext(traverseContext)
         }
         ```

         一开始判断孩子的情况，再继续通过 `traverseContext` 拿到上下文对象，然后就  `traverseAllChildren` 先判断是否为 null，不为就再传给核心遍历函数 `traverseAllChildrenImpl` (nameSoFar为 '')

         ```javascript
         // 初次遍历先对 children 的 type 进行判断，不符合条件的全归为 null
         var type = typeof children;
         if (type === 'undefined' || type === 'boolean') {
           children = null;
         }
         // 如果 children 为单个元素或者 null ，执行 callback 并返回 1
         // 同时这也是后续递归的出口点
         // 返回 1 这里很巧妙，单个孩子节点的时候可以返回 1,
         // 不是的话也可以通过递归带出到后面的子节点之和
         // 。。。貌似尾递归虽然是标准，但依然没有被浏览器（包括chrome）采纳，我有点
         // 好奇会不会有性能问题。。。
         if (
             children === null ||
             type === 'string' ||
             type === 'number' ||
           	// 注释有一行有关 fiber
             (type === 'object' && children.$$typeof === REACT_ELEMENT_TYPE) ||
             (type === 'object' && children.$$typeof === REACT_PORTAL_TYPE)
           ) {
           	// 所有叶子节点调用传入的回调函数，传参为当前的上下文，当前叶子节点以及name信息
             callback(
               traverseContext,
               children,
               nameSoFar === '' ? SEPARATOR + getComponentKey(children, 0) : nameSoFar,
             )
             return 1
           }

         var child
         var nextName
         var subtreeCount = 0 // 计算子节点个数
         var nextNamePrefix = nameSoFar === '' ? SEPARATOR : nameSoFar + SUBSEPARATOR

         if (Array.isArray(children)) {
           for (var i = 0; i < children.length; i++) {
             child = children[i]
             nextName = nextNamePrefix + getComponentKey(child, i)
             // 开始递归、不断地递归、无限地递归
             // 所以从这个地方可以看到。。以后写 React 最好不要组件嵌套太深
             // 真的会影响性能啊啊啊啊啊！！！！
             subtreeCount += traverseAllChildrenImpl(
               child,
               nextName,
               callback,
               traverseContext,
             )
           }
         } else {
           // 其他非数组情况
           // @第一种情况，iterable (可迭代)
           var iteratorFn =
               (ITERATOR_SYMBOL && children[ITERATOR_SYMBOL]) ||
               children[FAUX_ITERATOR_SYMBOL];
           if (typeof iteratorFn === 'function') {
             if (__DEV__) {
               // @第一种情况的分支，不能允许 Map 数据结构类型的 children
               // children.entries 返回的是 MapIterator
               if (iteratorFn === children.entries) {
                 warning(
                   didWarnAboutMaps,
                   'Using Maps as children is unsupported and will likely yield ' +
                   'unexpected results. Convert it to a sequence/iterable of keyed ' +
                   'ReactElements instead.%s',
                   ReactDebugCurrentFrame.getStackAddendum(),
                 );
                 didWarnAboutMaps = true;
               }
             }
         	// 其他可迭代对象则可以递归调用 `traverseAllChildrenImpl` 
             var iterator = iteratorFn.call(children);
             var step;
             var ii = 0;
             while (!(step = iterator.next()).done) {
               child = step.value;
               nextName = nextNamePrefix + getComponentKey(child, ii++);
               subtreeCount += traverseAllChildrenImpl(
                 child,
                 nextName,
                 callback,
                 traverseContext,
               );
             }
             // @第二种 不允许对象传入
           } else if (type === 'object') {
             var addendum = '';
             if (__DEV__) {
               addendum =
                 ' If you meant to render a collection of children, use an array ' +
                 'instead.' +
                 ReactDebugCurrentFrame.getStackAddendum();
             }
             var childrenString = '' + children;
             invariant(
               false,
               'Objects are not valid as a React child (found: %s).%s',
               childrenString === '[object Object]'
               ? 'object with keys {' + Object.keys(children).join(', ') + '}'
               : childrenString,
               addendum,
             );
           }
         }
         // 返回 *当前节点下所有* 子节点个数
         return subtreeCount;
         ```

         `name` 属性虽然可能比较没用，但这样倒是方便理解了递归，而且这样还可以方便看清 children 树的层级关系

         `callback` 传的函数有 `forEachSingleChildren` ，`mapSingleChildIntoContext`

         ```javascript
         function forEachSingleChild(bookKeeping, child, name) {
           var {func, context} = bookKeeping;
           func.call(context, child, bookKeeping.count++);
         }
         ```

         第一个参数其实就是 `traverseContext`，而他只需要其中的 `func` 、 `context` 和 `count`。

      2. onlyChild

         ```javascript
         function onlyChild(children) {
           invariant(
             isValidElement(children),
             'React.Children.only expected to receive a single React element child.',
           );
           return children;
         }
         ```

         判断是否只有一个孩子节点，若只有一个就返回原孩子节点；否则抛出一个错误。

      3. countChildren

         ```javascript
         function countChildren(children, context) {
           return traverseAllChildren(children, emptyFunction.thatReturnsNull, null)
         }
         ```

         计算节点的总数量，传入了一个 `emptyFunction.thatReturnsNull` (fbjs的一个util)

      4. toArray

         ```javascript
         // @main
         function toArray(children) {
           // 返回的结果
           var result = []
           // 调用了一个函数，但是没有传入 context
           mapIntoWithKeyPrefixInternal(
             children,
             result,
             null,
             emptyFunction.thatReturnsArgument,
           )
           
           return result
         }
         /*
         ** @mapIntoWithKeyPrefixInternal
         */
         function mapIntoWithKeyPrefixInternal(
         	children,
             array,
             prefix,
             func,
             context,
         ) {
           var escapedPrefix = ''
           // 处理prefix,此时为null也就 ''
           if (prefix != null) {
             escapedPrefix = escapeUserProvidedKey(prefix) + '/';
           }
           // 拿到 traverseContext 对象
           var traverseContext = getPooledTraverseContext(
             array,
             escapedPrefix,
             func,
             context,
           )
           // 递归遍历所有孩子节点，传入 `mapSingleChildIntoContext` 回调函数
           traverseAllChildren(children, mapSingleChildIntoContext, traverseContext)
           // 返还traverseContext
           releaseTraverseContext(traverseContext)
         }
         /*
         ** @mapSingleChildIntoContext
         ** @bookKeeping => traverseContext
         ** @child => (孩子)叶子节点
         ** @childKey => nameSoFar
         */
         function mapSingleChildIntoContext(bookKeeping, child, childKey) {  
           // result => 需要带出的数组，
           // keyPrefix => escapedPrefix, 这里此时是 null
           // func => 本来是用户定义的函数，这里是 emptyFunction.thatReturnsArgument
           var {result, keyPrefix, func, context} = bookKeeping;
           // 此时的context是不存在的，所以mappedChild指向了undefined?global
           // 由于传入的是emptyFunction.thatReturnsArgument，所以返回了 child
           var mappedChild = func.call(context, child, bookKeeping.count++);
           if (Array.isArray(mappedChild)) {
             // 遇到更深层次的节点，递归的调用mapIntoWithKeyPrefixInternal
             // 所以千万不要嵌套太深！！！
             mapIntoWithKeyPrefixInternal(
               mappedChild,
               result,
               childKey,
               emptyFunction.thatReturnsArgument,
             );
             // 如果不是 null 且不是数组，同时也是递归的出口
           } else if (mappedChild != null) {
             // 先判断是否是 React Element，然后就克隆换一个 key 推入要带出的数组
             if (isValidElement(mappedChild)) {
               mappedChild = cloneAndReplaceKey(
                 mappedChild,
                 // Keep both the (mapped) and old keys if they differ, just as
                 // traverseAllChildren used to do for objects as children
                 keyPrefix +
                   (mappedChild.key && (!child || child.key !== mappedChild.key)
                     ? escapeUserProvidedKey(mappedChild.key) + '/'
                     : '') +
                   childKey,
               );
             }
             result.push(mappedChild);
           }
         }
         ```

      5. mapChildren

         类似 toArray，不过他传入了用户自定义的 func 以及 context 实际上也就是对 toArray 的扩展































