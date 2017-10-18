# BFC (Block Formatting Context)

### Official Site

W3C  可视化格子模型：

>   https://www.w3.org/TR/CSS2/visuren.html

### Formatting Context

>  Formatting context是W3C CSS2.1规范中的一个概念。它是页面中的一块渲染区域，并且有一套渲染规则，它决定了其子元素将如何定位，以及和其他元素的关系和相互作用。

1. 常见的FC：
   -  Block Formatting context
   -  Inline Formatting context
2. 其他FC
   -  GridLayout Formatting Contexts（GFC）（CSS3）
   -  Flex Formatting Context （FFC）（CSS3）

---



## 重点BFC



### Block Formatting Context

>  In a block formatting context, each box’s left outer edge touches the left edge of the containing block (for right-to-left formatting, right edges touch). This is true even in the presence of floats (although a box’s *line boxes* may shrink due to the floats), unless the box establishes a new block formatting context (in which case the box itself *may* become narrower due to the floats).

国人的通俗解释：

>  BFC (Block Formatting Contexts) 即块级格式化上下文，从样式上看，它与普通的容器没有什么区别，但是从功能上，BFC 可以看作是隔离了的独立容器，容器里面的元素不会在布局上影响到外面的元素，并且 BFC 具有普通容器没有的一些特性，例如可以包含浮动元素，上面的第二类方法（如 overflow 方法）就是触发了父元素的 BFC ，使到它可以包含浮动元素，从而防止出现高度塌陷的问题。

---

### Create BFC

>  W3C:
>
>  Floats, absolutely positioned elements, inline-blocks, table-cells, table-captions, and elements with ‘overflow’ other than ‘visible’ (except when that value has been propagated to the viewport) establish new block formatting contexts.

以下几点会创建BFC：

-  The value of `float` is not `none`
-  The value of `position` is neither `static` nor `relative`
-  The value of `display` is `table-cell`, `table-caption`, `inline-block`, `flex`, or `inline-flex`
-  The value of `overflow` is not `visible`.

CSS3 add:

-  display 的 table-caption 值
-  position 的 fixed 值，其实 fixed 是 absolute 的一个子类，因此在 CSS2.1 中使用这个值也会触发 BFC ，只是在 CSS3 中更加明确了这一点。

利用上述条件创建BFC的side effect：

-  `display: table` may create problems in responsiveness
-  `overflow: scroll` may show unwanted scrollbars
-  `float: left` will push the element to the left, with other elements wrapping around it
-  ​
-  overflow: hidden` will clip elements that overflow

---

### Problems solved by using BFC

1. Using a Block Formatting Context to Prevent Margin Collapse — — (解决margin重叠问题)

   ```html
   <style>
     .container {
       background-color: red;
       overflow: hidden; /* creates a block formatting context */
     }

     p {
       background-color: lightgreen;
       margin: 10px 0;
     }
   </style>
   <div class="container">
     <p>Sibling 1</p>
     <p>Sibling 2</p>
     <p>Sibling 3</p>
   </div>
   ```

   上面会发生 collapsing margin 问题：

   原因：

   >  One thing that we must keep in mind is that vertical margins between adjacent block boxes (siblings) collapse only if they are in the same block formatting context.
   >
   >  If they belong to different block formatting contexts then the margins between them won’t collapse. 

   添加`overflow: hidden`到 子元素 div 元素生成一个 BFC 解决 collapsing margin (margin重叠)

2. Using a Block Formatting Context to Contain Floats — — (计算浮动高度)

   ```html
   <style>
     .container {
       background-color: green;
       /* create a block formatting context */
     }
     .container div {
       float: left;
       background-color: lightgreen;
       margin: 10px;
     }
   </style>
   <div class="container">
     <div>Sibling</div>
     <div>Sibling</div>
   </div>
   ```

   让容器元素变成一个 BFC 可以不用再利用伪元素等清除浮动。

   >  Now the container will contain the floated siblings and its height will expand to contain its children, with the elements back in the normal flow of the page within this formatting context.

   在这个 BFC 中，能让浮动元素回到普通流（Normal Flow）

3. Using Block Formatting Contexts to Prevent Text Wrapping — — (防止文字包围)

   通常可以利用`margin`来解决，但是我们也可以通过创建 BFC 解决文字包围的问题。

   ​

4. Using Block Formatting Contexts in Multi-column Layouts — — (在多列布局中使用)

   我觉得应该不常用吧。。。

----

### Question

1. 是否FC其实就是CSS的布局的形式之一。。。决定 box 的布局。。

---

### 补充

1. What is user agent stylesheet

   default stylesheet -> 解决方案就是常说的要添加reset CSS

2. What is Visual formatting model (可视化格式模型)

   >  https://www.w3.org/TR/CSS2/visuren.html

---

### Reference

BFC：

>  http://kayosite.com/remove-floating-style-in-detail.html
>
>  http://kayosite.com/block-formatting-contexts-in-detail.html
>
>  https://www.w3.org/TR/CSS21/visuren.html
>
>  http://www.bubuko.com/infodetail-1119912.html
>
>  http://www.html-js.com/article/1866
>
>  https://www.sitepoint.com/understanding-block-formatting-contexts-in-css/

Visual formatting model:

>  https://developer.mozilla.org/en-US/docs/Web/CSS/Visual_formatting_model
>
>  https://www.w3.org/TR/CSS2/visuren.html

