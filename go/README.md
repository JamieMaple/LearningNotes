# GO 学习笔记

### 你好，世界

``` go
package main

import "fmt"

func main() {
  fmt.Printf("Hello, 世界\n")
}
```

### package 包

和 c/c++ 程序一样，程序都是从主函数开始的，然后引入包等等

##### import

引入写法有两种

multiple line:
``` go
import "fmt"
import "math"
```

factored import statement
``` go
import (
  "fmt"
  "math"
)
```

##### export

不同于其他语言，他的导出很特别

> In Go, a name is exported if it begins with a capital letter.

比如说 `math` 包的 `math.Pi` 这个导出常量

如果使用小写或者不存在的导出变量会直接抛出 `unexported name` 的错误


### functions

非常不同寻常的函数

``` go
func add(a int, b int) int {
  return a + b
}
```

1. 参数类型声明位于参数后面，函数返回类型也写在函数 {} 前面

2. 如果多个参数共享一个参数，你可以省略只剩下最后一个参数后面带着类型，比如说前面的就可以写作 `(a, b int)`

3. 函数可以返回多个值

``` go
func swap(a, b int) (int, int) {
  return b, a
}
```

4. 可以命名返回值，需要注意的是设置的返回值存在提升

> If so, they are treated as variables defined at the top of the function.

``` go
func test(a, b int) (x int) {
	x = a + b
	return
}
```

### 变量声明

1. 单个变量： `var <variableName> <type>`

2. 多个变量共享一个状态：`var <var1> <var2> <...vars> <type>`

### 变量初始化

1. 普通初始化：`var a, b int = 1, 2`

2. 省略类型初始化：`var a, b = 1, 2`

### 简短变量声明

`k := 2`

> Inside a function, the := short assignment statement can be used in place of a var declaration with implicit type.

**注意** 该种声明只针对函数内部适用，不对函数外部用


### 变量类型

1. bool

2. string

3. int int8 int 16 int32 int64

4. uint uint8 uint16 uint32 uint64 uintptr (无符号整形)

5. byte // alias for uint8

6. rune // alias for int32

7. float32 float64

8. complex64 complex128

**需要注意的是** 数值过大溢出或者过小溢出会直接报错，而溢出到负数边界

**字符串型** 只能使用双引号，单引号直接报错

几个 int 的不同

> The int, uint, and uintptr types are usually 32 bits wide on 32-bit systems and 64 bits wide on 64-bit systems.

可以看到的是，会随着硬件 cpu 情况变化而变化

### initial zero value

1. string -> ""

2. 0 -> numeric

3. false -> boolean


### 类型转化(type convention)

可以对比其他静态语言

只不过有点不同地方在于 go 的类型转化必须显示声明，否则直接报错，比如 `Math.Sqrt(float(....))`


### 类型推断(type inference)

### const 常量

`const a = 1`

> Constants cannot be declared using the := syntax.

### loop 循环

##### for loop

``` go
sum := 0
for i := 0; i < 10; i++ {
  sum += i
}
```

> Unlike other languages like C, Java, or JavaScript there are no parentheses surrounding the three components of the for statement and the braces { } are always required.

##### 没有 while 循环，for is go's while

``` go
for sum <= 1000 {
  sum = sum * 2
}
```

##### if 

1. 同上不需要左右()，只需要{}

2. 也可以在 if 前面加入一个简短的 statement 声明

> Variables declared by the statement are only in scope until the end of the if.

``` go
if v := math.Pow(x, n); v < lim {
  return v
}
return lim
```

##### switch

> In effect, the break statement that is needed at the end of each case in those languages is provided automatically in Go.

1. 每个 case 自带 break

> Another important difference is that Go's switch cases need not be constants, and the values involved need not be integers.

2. case 不需要常量 const，case 的值要类型匹配 switch 的值，不存在隐式类型转化隐式

3. switch 可以没有条件，默认条件为 true


##### 延迟执行

`defer some func` 直到所在函数 return 才执行 defer 语句，但是传的参数立即求值计算的

> A defer statement defers the execution of a function until the surrounding function returns.

延迟执行函数推入一个调用栈中，所在函数 return 时后入先出的执行延迟函数

> Deferred function calls are pushed onto a stack. When a function returns, its deferred calls are executed in last-in-first-out order.

##### 指针 Pointers

空指针是 `nil`

``` go
var p int*
i := 42
i = &i
```

但是和 C 不同，go 的指针没有运算（=。= 虽然我真的都没用 c 的指针运算）

###### 结构体 Structs

``` go
type struct {
  X int
  Y int
}
```

结构体指针引用不是用 `->` ，直接使用 `.`
当然也可以使用 `(*p).X`

##### 数组 Array

`var a [2]string`

1. slice

`a[low : high]`

This selects a half-open range which includes the first element, but excludes the last one.

slice 出来的值是一个引用，注意对slice出来的引用修改元素会影响被引用的 array

slice 的两边参数任一都可以省略

2. 字面量写法

``` go
[3]bool{true, false, false}

// 注意下面的有别于上面的

[]bool{true, false, false}
// this creates the same array as above, then builds a slice that references it
```

3. `len()` 和 `cap()` 俩个函数

len: 数组包含元素的长度

> The length of a slice is the number of elements it contains.

cap: 数组从首元素开始的容量大小

> The capacity of a slice is the number of elements in the underlying array, counting from the first element in the slice.

4. `nil` array

> A nil slice has a length and capacity of 0 and has no underlying array.

5. 动态数组 -- 大概就是名义上的变长的数组吧

创建： `make()`  函数，比如说 `make([]int, 5)`，第一个参数表示的是要创建的几维数组，第二个参数是指数组包含元素的长度，此时函数返回了一个包含了5个初始值0的动态一维数组

该函数第三个参数为他的容量大小


6. 数组能包含其他类型数组

7. `append` 添加数组元素

``` go
package main

import "fmt"

func main() {
	var s []int
	printSlice(s)

	// append works on nil slices.
	s = append(s, 0)
	printSlice(s)

	// The slice grows as needed.
	s = append(s, 1)
	printSlice(s)

	// We can add more than one element at a time.
	s = append(s, 2, 3)
	printSlice(s)
	
	s = append(s, 2)
	printSlice(s)
	
	s = append(s, 2, 3, 4)
	printSlice(s)
}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}

// len=0 cap=0 []
// len=1 cap=1 [0]
// len=2 cap=2 [0 1]
// len=4 cap=4 [0 1 2 3]
// len=5 cap=8 [0 1 2 3 2]
// len=8 cap=8 [0 1 2 3 2 2 3 4]

```

这里需要注意的一点是容量（我猜测）是二倍于原容量扩容，好处显而易见，如果对于一个经常变动的数组而言能够减少频繁的扩容操作

8. `range` 遍历数组

``` go
	stringArr := []string{"hello", "world", "你好", "世界"}
	for i, v := range stringArr {
		fmt.Printf("%d, %s\n", i, v)
	}
```

如果要跳过索引或者值

只需把对应的换成 `_`，当然只要索引就可以不用换，直接省略

##### `map` 应该算 go 的哈希表吧

** 多多注意最后一行的逗号，这也算错误。**

创建：`make(map[type]type)`

字面量创建：`map[type]type`

``` go
s := make(map[string]string)

s := map[string]string {
  "hello": "world",
  "你好": "世界",
}
```

> If the top-level type is just a type name, you can omit it from the elements of the literal.

也就是说可以省略少写点代码

insert or update: `m[key] = elem`, `elem = m[key]`

delete: `delete(m, key)`

test key: `elem, ok = m[key]`

`ok` -> false / true

##### function closure 闭包创建

> A closure is a function value that references variables from outside its body.

由于 go 不像 js 那样没有包管理，目前在 go 的主要作用也就是用来保存一些变量比如一些状态

##### methods

`go` 不同于其他语言尤其像 java 那样有 class

但是能够在结构体上也就是 type 上使用方法，这还是可以当做 oop 的，顺便还能函数式编程

``` go
type Person struct {
  name string
  age  int
}
func (P Person) sayName() {
  fmt.Println("hello I am ", P.name, ", I am ", P.age, " years old")
}
```

go 没有 class，由于可以在 type 上定义方法，所以我觉得和 class 差不多了

** 注意 ** 

> You can only declare a method with a receiver whose type is defined in the same package as the method.
> You cannot declare a method with a receiver whose type is defined in another package.

方法定义要和类型同一个包，不能处在不同的包内

####### 指针传参

``` go
func (P *People) ChangeAge(age int) {
  P.age = age
}
```

指针传参传入的是一个引用不再是像值传递那样，值的地址被传入，能够对原始值进行修改
所以很显然，一般来讲，指针传参在方法使用上更普遍

####### 与函数传参对比

1. 传参方面

``` go
var v Vertex
ScaleFunc(v, 5)  // Compile error!
ScaleFunc(&v, 5) // OK
```

函数传入的类型必须一一对应，否则直接抛出错误

``` go
var v Vertex
v.Scale(5)  // OK
p := &v
p.Scale(10) // OK as (&p).Scale(10)
```

> For the statement v.Scale(5), even though v is a value and not a pointer, the method with the pointer receiver is called automatically.

方法依据定义时传入的地址引用或值传入决定，可以不需要一一对应，仅仅是看方法的传参

引用传参能够减少函数在传参时再创建结构体的时间和空间

在选择上，最好代码风格统一只使用一个，而最好不要混合使用

> In general, all methods on a given type should have either value or pointer receivers, but not a mixture of both.

##### Interfaces

> An interface type is defined as a set of method signatures.

> A value of interface type can hold any value that implements those methods.

> Implicit interfaces decouple the definition of an interface from its implementation, which could then appear in any package without prearrangement.

``` go
type Person  interface {
  SayName() string
}
```

interface 要注意 nil 传入问题

`interface{}` 所有的类型都实现空接口


> Empty interfaces are used by code that handles values of unknown type.

比如最常用的 `fmt.Print` 就是用了空接口

###### type assertion

> A type assertion provides access to an interface value's underlying concrete value.

写法：

``` go
  t, ok := i.(string)
```

> To test whether an interface value holds a specific type, a type assertion can return two values: 
> the underlying value and a boolean value that reports whether the assertion succeeded.

传两个就算第一个类型不符合，依然不会报错

###### type switch

和 go 的 switch 一样，自带 break

``` go
var i interface{}

switch v := i.(type) {
  case int:
    fmt.Printf("int")
  case string:
    fmt.Printf("string")
  default:
    fmt.Printf("no type found !")
}

```

###### stringers

``` go
type Stringer interface{
  String() string
}
```

> A Stringer is a type that can describe itself as a string.
> The fmt package (and many others) look for this interface to print values.

个人的理解是可以配合 fmt 标准包使用

##### Errors

``` go
type error interface {
  Error() string
}
```

> As with fmt.Stringer, the fmt package looks for the error interface when printing values.

``` go
// 一个常见的错误处理
i, err = someFun()
if err != nil {
  fmt.Println(err)
  return
}

// do others
```

返回 error 类型配套一个 Error 接口方法

##### io Readers

``` go
func (T) Read(b []byte) (n int, e error)
```



