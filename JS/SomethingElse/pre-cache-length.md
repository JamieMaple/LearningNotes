# Pre-caching Array.length

### Is it necessary for performance

我觉得预缓存 length 实际上是一个空间和时间的矛盾（算是算法的选择性问题）。。。

鄙人觉得要分情况：

-  是否 Array 为类似HTML Collection 那种动态类型，如果是静态的 Nodelist 性能差异不大
-  如果是 V8 引擎的浏览器对数组的length是有优化的，浏览器会对代码进行二次处理成浏览器认为性能更好的代码形式。。。所以此时还预缓存 length 就显得很多余

总结：

我觉得可以如果在不考虑IE9以下的版本都不用开辟新的内存存储 length ，但往往不用 HTML 直接引入原生而用 babel 编译出来的代码，所以实际使用中不用在意 length 的预缓存

---

### Reference

>  YDKJS 在第五章的性能中有谈及，其观点为浏览器对这个length有优化。。存疑（是否是现代浏览器，如果IE8及以下是否有优化？！）
>
>  知乎：https://www.zhihu.com/question/29714976
>
>  stackoverflow：https://stackoverflow.com/questions/17989270/for-loop-performance-storing-array-length-in-a-variable