# React 源码分析随笔 1

version：v16.1.1

[源码](https://github.com/facebook/react/blob/master/packages/react/index.js)

### 先看主入口文件几个包

``` javascript
import assign from 'object-assign'
import ReactVersion from 'shared/ReactVersion'
import {enableReactFragment} from 'shared/ReactFeatureFlags'
```

1. assign

   目的：用于对象复制 — 应该是可以算某种程度上的 Object.assign(只支持 enum 为真的属性的替换) 替代

   [npm](https://www.npmjs.com/package/object-assign)

2. ReactVersion

   当前版本号：

   [repo](https://github.com/facebook/react/blob/master/packages/shared/ReactVersion.js)

3. enableReactFragment

   一个特性标志布尔值用于后续的判断 false (默认)

   [repo](https://github.com/facebook/react/blob/master/packages/shared/ReactFeatureFlags.js) 此外还包括其他一些特性的标志


### 主入口文件其他 React 核心包

``` javascript
import {Component, PureComponent, AsyncComponent} from './ReactBaseClasses'
import {forEach, map, count, toArray, only} from './ReactChildren'
import ReactCurrentOwner from './ReactCurrentOwner'
import {
  createElement,
  createFactory,
  cloneElement,
  isValidElement,
} from './ReactElement';
import {
  createElementWithValidation,
  createFactoryWithValidation,
  cloneElementWithValidation,
} from './ReactElementValidator';
import ReactDebugCurrentFrame from './ReactDebugCurrentFrame'
```

`React` 主要组成结构：

```javascript
var React = {
  // ReactChildren.js
  Children: {
    map,
    forEach,
    count,
    toArray,
    only,
  },
  // ReactBaseClasses.js
  Component,
  PureComponent,
  unstable_AsyncComponent: AsyncComponent, // 异步组件貌似暂时 unstable (不稳定)？
  // ReactElement.js 和 ReactElementValidator.js ，然后判断当前环境选取合适的函数
  createElement: __DEV__ ? createElementWithValidation : createElement,
  cloneElement: __DEV__ ? cloneElementWithValidation : cloneElement,
  createFactory: __DEV__ ? createFactoryWithValidation : createFactory,
  isValidElement: isValidElement,
  // 版本号
  version: ReactVersion,
  // 正如其名
  __SECRET_INTERNALS_DO_NOT_USE_OR_YOU_WILL_BE_FIRED: {
    ReactCurrentOwner,
    // Used by renderers to avoid bundling object-assign twice in UMD bundles:
    assign,
  },
};
// 默认是没有的
if (enableReactFragment) {
  React.Fragment = REACT_FRAGMENT_TYPE;
}

if (__DEV__) {
  Object.assign(React.__SECRET_INTERNALS_DO_NOT_USE_OR_YOU_WILL_BE_FIRED, {
    // These should not be included in production.
    ReactDebugCurrentFrame,
    // Shim for React DOM 16.0.0 which still destructured (but not used) this.
    // TODO: remove in React 17.0.
    ReactComponentTreeHook: {},
  });
}
```

1. ReactBaseClass — export 三种 Component

   [repo](https://github.com/facebook/react/blob/master/packages/react/src/ReactBaseClasses.js)

   -  含有一些 `Facebook` 独自开发的包

      [repo](https://github.com/facebook/fbjs/blob/master/packages/fbjs/README.md)

      ```javascript
      // emptyObject
      const emptyObject = {};

      if (__DEV__) {
        Object.freeze(emptyObject)
      }

      module.exports = emptyObject

      // invariant
      // https://github.com/facebook/fbjs/blob/master/packages/fbjs/src/__forks__/invariant.js
      // lowPriorityWarning
      ```

    - 这个文件中先看一个比较重要的包 `ReactNoopUpdateQueue`, 名如其用处，用于队列更新但是这个文件只是一个 **abstract API for an update queue**，它不提供任何操作，只是一个默认检测然后适当时候在 `console` 中跳出来警告或者报错，真正的 `updater` 是由使用时组件的 `renderer` 来提供的。

      具体结构如下, 就是一个含有4个方法的对象：

      ```javascript
      var ReactNoopUpdateQueue = {
        /*
        ** @param {ReactClass} pubilcInstance
        ** @return {boolean}
        */
        isMounted: function,				// 判断是否挂载组件
        /*
        ** @param [{ReactClass} publicInstance, {function} callback, {string} callerName]
        **
        */
        enqueueForceUpdate: function,		// 将 forceUpdate 推入队列
        /*
        ** @param [{ReactClass} publicInstance, {object} completeState, {function} callback, {string} callerName]
        */
        enqueueReplaceState: function,	// 将 replaceState 推入队列
        /*
        ** @param [{ReactClass} publicInstance, {object} partialState, {function} callback, {string} Name]
        ** fb貌似还有个 TODO 没写完
        */
        enqueueSetState: function,		// 将 setState 推入队列
      };
      ```

   -  一个最重要的东西 — Component

      ```javascript
      function Component(props, context, updater) {
        this.props = props
        this.context = context
        this.refs = emptyObject
        this.updater = updater || ReactNoopUpdateQueue
      }
      ```

      可以看到 `Component` 四大属性，其中三大属性 `props`, `context`和 `refs` 我们应该都很清楚了。

      第四个属性 `updater` 初始化使用了上述的 `ReactNoopUpdateQueue` (默认只是一个抽象的 API ，作用如上所述), 它用于后续的 `setState` 和 `forceUpdate` 有关更新的操作。

   -  `Component.prototype`

      ```javascript
      Component.prototype = {
        isReactComponent: object {}, // 这个地方我觉得如果是个 boolean 或者 function 可能更好
        /*
        ** @param: {object|function} parialState, {function} callback
        */
        setState: function,
        /*
        ** @param: {function} callback
        */
        forceUpdate: function,
      }
      ```

   -  一些还遗留下来没有删除老的api

      ```javascript
      if (__DEV__) {
        var deprecatedAPIs = {
          isMounted: Array[name, info],
          replaceState: Array[name, info],
        };
        var defineDeprecationWarning = function(methodName, info) {
          Object.defineProperty(Component.prototype, methodName, {
            get: function(),
          })
        }
        
        for (var fnName in deprecatedAPIs) {
          if (deprecatedAPIs.hasOwnProperty(fnName)) {
            defineDeprecationWarning(fnName, deprecatedAPIs[fnName])
          }
        }
      ```

      通过一个内部变量 `__dev__` 包裹（大家都懂 `var` ，所以包裹其实没有任何卵用，但是可能是代码的阅读性吧。。。）

       `isMounted` / `replaceState` 就是遗留下来的 api

      `defineDeprecationWarning` 是通过 `es5` 的 `Object.defineProperty` 定义下的 getter，为后续警告提供了一个方法

   -  `PureComponent` 和 `AsyncComponent` 两个竟然照抄 `Component` =.= (当然 `AsyncComponent` 的  `prototype` 是不一样的)

      1. `PureComponent` X )

         (如果觉得乱的话，略过略过 。。。毕竟js的原型链博大精深, 推荐 ydkjs 的面向委托编程方式，虽然可能不是业界主流，但是毕竟还是让人开眼界的)

         ```javascript
         // 一个空构造函数？？？刚开始看我觉得很多余
         function ComponentDummy() {}
         ComponentDummy.prototype = Component.prototype
         var pureComponentPrototype = (PureComponent.prototype = new ComponentDummy())

         pureComponentPrototype.constructor = PureComponent

         // 复制完整enum属性，然后设置isPureReactComponent 为 true
         Object.assign(pureComponentPrototype, Component.prototype)

         pureComponentPrototype.isPureReactComponent = true
         ```

         所以其实我看完还是不是很懂 `ComponentDummy` 这个构造函数的作用, 我觉得我下面这样写就可以了。。。我还是刚开始看的时候觉得很多余。。。

         ```javascript
         // 错误示范，吃一堑长一智。。。
         var pureComponentPrototype = PureComponent.prototype = new Component()

         pureComponentPrototype.contructor = PureComponent()

         Object.assign(pureComponentPrototype, Component.prototype)

         pureComponentPrototype.isPureReactComponent = true
         ```

         自信感爆棚呗。。。以为真的可以改。。。然鹅我忘记了一个事实，这样的做法显然不严谨。。。如果没有一个临时的空构造函数，那父类 `Component` 这个构造函数显然会潜在的影响到子类  `PureComponent` 。（参考红宝书的借用构造函数技术）

         （算是对基础的一次复习~~）

      2. `AsyncComponent`

         ```javascript
         var asyncComponentPrototype = (AsyncComponent.prototype = new ComponentDummy())
         asyncComponentPrototype.constructor = AsyncComponent
         Object.assign(asyncComponentPrototype, Component.prototype)

         asyncComponentPrototype.unstable_isAsyncReactComponent = true
         // 这是后续的回调渲染
         asyncComponentPrototype.render = function() {
           return this.props.children
         }
         ```

2. ReactCurrentOwner — 一个 API 也就是 {current: null | fiber}

   这里涉及到 `fiber` 了

   // TODO react-fiber

3. ReactElement — 五个 API

   ```javascript
   // 常量
   var REACT_ELEMENT_TYPE, RESERVED_PROPS
   // 函数
   var hasOwnProperty, 
       hasValidRef,  // getter
       hasValidKey,  // getter
       defineKyPropWarningGetter, 
       defineRefPropWarningGetter
   ```

   -  内部封装的比较重要的 ReactElement 函数，不需要使用 new，提供给其他 create 函数用

      重要说明：

   >  **The type argument can be either a tag name string (such as `'div'` or `'span'`), **
   >
   >  **or a [React component](https://reactjs.org/docs/components-and-props.html) type (a class or a function).**

   ```javascript
   // element
   var ReactElement = function(type, key, ref, self, source, owner, props) {
     var element = {
       // This tag allow us to uniquely identify this as a React Element
       $$typeof: REACT_ELEMENT_TYPE,
       // Built-in properties that belong on the element
       type: type,
       key: key,
       ref: ref,
       props: props,
       // Record the component responsible for creating this element.
       _owner: owner,
     };

     if (__DEV__) {
       element._store = {}
       // non-enumerable for test
       Object.defineProperty(element._store, 'validated', {...})
       Object.defineProperty(element, '_self', {...)
       Object.defineProperty(element, '_source', {...})
       if (Object.freeze) {...}
     }

     return element;
   }
   ```

   -  然后就是 `createElement` 函数

   ```javascript
   export function createElement(type, config, children){
     props <= config // (不包括原型链上的属性以及 RESERVERED_PROPS 定义所有的属性，比如ref、key) 
     self <= config.__self || null
     source <= config.__source || null
     children <= children || arguments.slice(2) // 也就是...children
     defaultProps <= type.defaultProps
     // 接下来就是看 key 和 ref 两个属性是否通过了 config 传入
     if (__DEV__) {
       if (key || ref) {...}
     }
     // 然后就由 ReactElement 函数带出 element
     return ReactElement(
       type,
       key,
       ref,
       self,
       source,
       ReactCurrentOwner.current, // null or *fiber*
       props,
     )
   }
   ```

   -  然后是一个老版本的 hook — createFactory

   ```javascript
   export function createFactory(type) {
     var factory = createElement.bind(null, type)
     factory.type = type
     return factory
   } // 返回的也不过是一个有 type 的 element
   ```

   -  接着就是 cloneAndReplaceKey

   ```javascript
   export function cloneAndReplaceKey(oldElement, newKey) {
     var newElement = ReactElement(
       oldElement.type,
       newKey,
       oldElement.ref,
       oldElement._self,
       oldElement._source,
       oldElement._owner,
       oldElement.props,
     )

     return newElement;
   } // 名如其用 -- 仅仅改变原来的 key 属性
   ```

   -  然后就是 cloneElement

   >  官方：Clone and return a new React element using `element` as the starting point. 
   >
   >  The resulting element will have the original element’s props with the new props merged in shallowly. 
   >
   >  New children will replace existing children.
   >
   >   `key` and `ref` from the original element will be preserved.

   ```javascript
   export function cloneElement(element, config, children) {
     var propName
     // 复制成新属性，然后一路初始化保留
     var props = Object.assign({}, element.props)
     var key = element.key
     var ref = element.ref
     var self = element._self
     var source = element._source
     // Owner will be preserved, unless ref is overridden
     var owner = element._owner

     if (config != null) {
       if (hasValidRef(config)) {
         // Silently steal the ref from the parent.
         ref = config.ref
         owner = ReactCurrentOwner.current // null or fiber
       }
       if (hasValidKey(config)) {...}

       // 覆盖属性
       var defaultProps;
       if (element.type && element.type.defaultProps) {
         defaultProps = element.type.defaultProps;
       }
       for (propName in config) {
         if (
           hasOwnProperty.call(config, propName) &&
           !RESERVED_PROPS.hasOwnProperty(propName)
         ) {
           if (config[propName] === undefined && defaultProps !== undefined) {
             // Resolve default props
             props[propName] = defaultProps[propName];
           } else {
             props[propName] = config[propName];
           }
         }
       }
     }
       
   //  {...children...}

     return ReactElement(element.type, key, ref, self, source, owner, props);
   }
   ```

   -  最后一个api，测试是否是 ReactElement

   ```javascript
   export function isValidElement(object) {
     return (
       typeof object === 'object' &&
       object !== null &&
       object.$$typeof === REACT_ELEMENT_TYPE
     )
   }
   ```

   ​













