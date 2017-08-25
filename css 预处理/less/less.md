# less笔记

>  官方文档：http://lesscss.org/

1. Variable(变量)

   >  One of the main features of *Less* is the ability to create variables just like you would in a standard programming language

   新加入变量机制:   `@varible: num `

2. Mixins(混合)

   >  LESS enables us to use an existing class or ids and apply all it's styles directly to another selector. 

   ```less
   .box{
     width:....
     .border;
   }
   .border{
     border: solid 4px black;
   }
   ```

   >  Another cool thing mixins can do is receive parameters.In the following example we add an argument for the width and height of our circles, with a default value of 25 pixels. This will create a small circle 25x25 and a big one 100x100 pixels.

   ```less
   #circle(@size: 25px){
     background-color: #4CAF50;
     border-radius: 100%;

     width: @size;
     height: @size;
   }

   #small-circle{
     #circle
   }

   #big-circle{
     #circle(100px)
   }
   ```

3. Nesting and Scope(作用域)

   >  Nesting can be used to structure your stylesheet in a way that matches the HTML structure of the page

   ```less
   ul{
     background-color: #03A9F4;
     padding: 10px;
     list-style: none;

     li{
       background-color: #fff;
       border-radius: 3px;
       margin: 10px 0;
     }
   }
   ```

4. Operations(运算)

   >   You can do basic math operations to numerical values and colors.

5. Functions(函数)

   >   http://lesscss.org/functions/

   ```less
   @var: #004590;

   div{
     height: 50px;
     width: 50px;
     background-color: @var;

     &:hover{
       background-color: fadeout(@var, 50%)
     }
   }
   ```

6. More

