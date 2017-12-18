# React Fiber 随笔 1

### 前言

1. what is fiber?

   >  In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **fiber** is a particularly lightweight [thread of execution](https://en.wikipedia.org/wiki/Thread_of_execution).
   >
   >  Like threads, fibers share [address space](https://en.wikipedia.org/wiki/Address_space). However, fibers use [co-operative multitasking](https://en.wikipedia.org/wiki/Computer_multitasking#Cooperative_multitasking.2Ftime-sharing) while threads use [pre-emptive multitasking](https://en.wikipedia.org/wiki/Pre-emptive_multitasking). Threads often depend on the kernel's thread scheduler to preempt a busy thread and resume another thread; fibers yield themselves to run another fiber while executing.				— — from [wiki](https://en.wikipedia.org/wiki/Fiber_(computer_science))

2. fiber 出发点

   >  The goal of React Fiber is to increase its suitability for areas like animation, layout, and gestures. Its headline feature is **incremental rendering**: the ability to split rendering work into chunks and spread it out over multiple frames.

   也就是虽然 `react` 本身虽然已经非常非常快了，但用户使用 `React` 时由于编码时没有注意到 js 这样一门单线程语言的特性，而导致大量同步和重复的运算霸占了主线程很多时间使得渲染等被严重阻塞，这正是 fiber 想要解决的问题 — 把大量计算分解成一个个异步的小任务，从而解决同步阻塞的问题。然而从目前版本来看（16.1.1），`fiber` 目前工作方式仍然同步进行，异步渲染将是 `React` 将来的特性。

### 源码速览

1. 先来看看文件目录结构

   ```javascript
   // src 文件下面超级超级多
   |- ReactFiber.js					// 存放了 fiber 数据结构以及一些操作
   |- ReactChildFiber.js				// 其他的字如其名...我也没看完 QAQ
   |- ReactFiberClassComponent.js	
   |- ReactFiberBeginWork.js			// @1
   |- ReactFiberCommitWork.js			// @2
   |- ReactFiberCompleteWork.js		// @3
   // 上面三个文件就是 fiber 的主要工作流程
   |- ReactFiberContext.js
   |- ReactFiberDevToolsHook.js
   |- ReactFiberErrorLogger.js
   |- ReactFiberExpirationTime.js
   |- ReactFiberHostContext.js
   |- ReactFiberHydrationContext.js
   |- ReactFiberInstrumentation.js
   |- ReactFiberReconciler.js
   |- ReactFiberRoot.js
   |- ReactFiberScheduler.js
   |- ReactFiberStack.js
   |- ReactPotal.js
   |- ReactTypeOfInternalContext.js
   ```

   首先重点文件就是 fiber 这样的数据结构

   在我们先前的 react 包里面有个单独的文件也就是 ReactCurrentOwner.js，抛开 flow 类型限定，他就用到了 `Fiber` 这样的 type，而这样的 `type` 也就在我们的 ReactFiber.js 文件里面

   抛开其他引入的一堆文件以及 `__dev__` 里面的描述外，主要就是 Fiber type 和一些 操作

   介绍 Fiber 这样的 type 时候有个很重要的注释

   >  A Fiber is work on a Component that needs to be done or was done. There can be more than one per component.

   ```javascript
   export type Fiber = {|
     tag: TypeOfWork,							
     // fiber 节点标签，可以从ReactTypeOfWork.js 中看到一些
     key: null | string,						// 比对用的 key 标识符
     type: any,								// fiber 节点类型
     stateNode: any,							// fiber 节点的状态
     return: Fiber | null,						// fiber 节点的爸爸，可以俩个(滑稽)
     child: Fiber | null,						// 指向儿子的单链
     sibling: Fiber | null,					// 指向兄弟的单链
     index: number,                   			// 某一个索引值？
     ref: null | (((handle: mixed) => void) & {_stringRef: ?string}), // 附加属性
     pendingProps: any,						// 
     memoizedProps: any,
     updateQueue: UpdateQueue<any> | null,		// 处理更新回调的一个队列
     memoizedState: any,						// 记录输出的状态
     internalContextTag: TypeOfInternalContext,
     effectTag: TypeOfSideEffect,				// 二进制副作用标记
     nextEffect: Fiber | null,					// 单链指向下一个 fiber
     firstEffect: Fiber | null,				// 单链指向第一个 fiber
     lastEffect: Fiber | null,					// 单链指向最后一个 fiber
     expirationTime: ExpirationTime,			// 提供给他的时间？
     alternate: Fiber | null,					// 单链指向更新时候被克隆出来的 fiber

     // __DEV__ only
     _debugID?: number,
     _debugSource?: Source | null,
     _debugOwner?: Fiber | null,
     _debugIsCurrentlyTiming?: boolean,
   |};

   // 构造相关 fiber 的函数都不对外
   /*
   ** 主构造函数
   ** @param tag {TypeOfWork} 
   ** @param key {null|string}
   ** @param internalContextTag {TypeOfInternalContext}
   */
   function FiberNode(...){...}
   /*
   ** 这是 FiberNode 构造函数之上套的一层壳，对内的构造函数
   ** tips:
   ** 		1. 不要在其上添加实例方法
   **		2. 不要用 `instanceof Fiber` 之类的做测
   **		。。。还有几条不翻译了。。。
   ** @params 同上
   ** return new FiberNode(...params)
   */
   function createFiber(...){...}
   ```

   然后来看 `export` 的内容

   ```javascript
   export function createWorkInprogress(){}
   export function createHostRootFiber(){}
   export function createFiberFromElement(){}
   export function createFiberFromFragment(){}
   export function createFiberFromText(){}
   export function createFiberFromHostInstanceForDeletion(){}
   export function createFiberFromCall(){}
   export function createFiberFromReturn(){}
   export function createFiberFromPortal(){}
   ```

   ​

### Reference

>  https://github.com/acdlite/react-fiber-architecture
>
>  http://makersden.io/blog/look-inside-fiber/
>
>  https://www.youtube.com/watch?v=aV1271hd9ew