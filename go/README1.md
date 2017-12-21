# GO 学习笔记 
### hello world

``` go
package main

import "fmt"

func main() { 
  fmt.Printf("Hello World!\n")
}
```

第一个程序很简单

### 几个特点

1. 很多人保证所有的 go 代码放在一个工作区

2. 一个工作区同时能存在多个版本多个 repos

3. 每一个仓库包含了多个包，一个包可能会包涵多个 go 源码在一个文件夹

4. 包的位置决定了他的 import 位置

### 工作区（workspace）

主要文件结构有三个部分组成：`src` 、'pkg' 以及 'bin'

``` go
src 包含了 go 源代码文件
pkg 包含了包                    / go build source 的地方
bin 包含了可执行命令等          / go install 的二进制文件
```

### go 环境变量设置

默认选择：`export GOPATH=$HOME/go`

对于 fish 来说，需要在文件里面 `set -gx GOPATH=$HOME/go`

### import 包

1. import 的路径与它在工作区的位置或者远程 repo 相关

2. 标准包有他的缩写方式，比如说 `fmt` 和 'net/http'

3. 对于当前自己的包，需要在前面加上 `base path`



