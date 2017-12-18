# React 源码随笔 3

### ReactElementValidator

### 大体结构

同样先5个 fbjs 的[包，然后就引入了之前文件的函数

```javascript
import ReactCurrentOwner from './ReactCurrentOwner'
import {isValidElement, createElement, cloneElement} from './ReactElement'
import ReactDebugCurrentFrame from './ReactDebugCurrentFrame'
```

导出的是：

```javascript
export function createElementWithValidation(type, props, children)
export function createFactoryWithValidation(type)
export function cloneElementWithValidation(element, props, children)
```

这个包里面一堆验证东西的函数，也没啥好写的。

所以主要看三个函数

1. createElementWithValidation

   ```javascript
   export function createElementWithValidation(type, props, children) {
     // 类型检测
     var validType =
       typeof type === 'string' ||
       typeof type === 'function' ||
       typeof type === 'symbol' ||
       typeof type === 'number';
     // We warn in this case but don't throw. We expect the element creation to
     // succeed and there will likely be errors in render. 在渲染时抛出错误
     if (!validType) {...}
     // 创建元素
     var element = createElement.apply(this, arguments);

     // The result can be nullish if a mock or a custom function is used.
     // TODO: Drop this when these are no longer allowed as the type argument.
     if (element == null) {
       return element;
     }
     // 查看子节点是否为 React Element 同时检测 key 值是否有效
     if (validType) {
       for (var i = 2; i < arguments.length; i++) {
         validateChildKeys(arguments[i], type);
       }
     }
     // 验证
     if (typeof type === 'symbol' && type === REACT_FRAGMENT_TYPE) {
       validateFragmentProps(element);
     } else {
       validatePropTypes(element);
     }

     return element;
   }
   ```

2. `createElementFactoryWithValidation`

   调用上面的函数创建一个 factory ，同时还定义了一个 getter `type` 然后返回这个 factory

3. `cloneElementWithValidation`

   调用了 `cloneElmenet`，然后由于克隆的对象一般情况下都为验证过了的 Element 所以无需再次验证，只需调用 `validateChildKeys` 验证子节点和 `key` 然后再对 `propTypes` 进行验证。

   ​

   ​

