# 读书笔记

> 希望自己废弃使用上下左右和回退

## 技巧1：`.`操作符

重复上次上次修改

### 几个新学到的操作

1. `>G` 增加当前行到文档末未出单缩进层级

2. 在插入模式中记录一些按键，会重复所有按键操作

3. `.` 是一个微小的宏

## 技巧2：不要自我重复

1. 比如说添加 `;` 可以使用这个 `.`

2. `A` + `;` + ';'

3. 对于大量的行重复操作只需选中指定行然后 `normal .`

## 技巧3：以退为进

1. `f` 查找当前行某字符, f{char}

2. `;` 重复上次查找的字符

3. `,` 与 `;` 相反操作

## 技巧4：执行、重复、回退

1. 回退操作 `u`

2. `F` 查找当前行上一个操作符，F{char}，重复回退同 `f`

3. 查找下一个匹配项 `/patten`，重复 `n`, 回退 `N`

4. 查找上一个匹配项 `?patten`, 重复回退同上

5. 执行替换 `:s/target/replacement`, 重复 `&`, 回退 `u`

6. 执行一系列修改 `qx{change}q`，重复 `@x`, 回退 `u`

## 技巧5：查找并手动替换

1. `*` 向后查找当前光标下的单词

## 技巧6：`.` 范式

前面几个技巧有共通的地方：一个键移动，另一个键执行


## 技巧7：停顿时请移开画笔

不使用的（停顿的）时候使用普通模式

## 技巧8：把撤销单元切成块


由于 vim 把 `i{text}` 当做了一次修改，所以可以在适当时候推出 insert mode

## 技巧9：构造可重复的修改

`daw` -> delete a word

## 技巧10：用次数做简单的算术运算

`ctrl - a` 增加，前面可带上数字

`ctrl - c` 减少，前面可带上数字

## 技巧11：重复优先次数

比起 `dnw` 以及 `ndw`，应该更倾向于 `dw...`

以后没有特殊情况，全都是用 `dw...`


## 技巧12：双剑合璧，天下无敌

公式：operator{motion} 

比如：`dl`, `daw`, `dap`,

可以配对组合使用，

当一个 operator 被连续调用两次时候，作用于当前行


# 插入模式技巧

## 技巧13：在插入模式中即时更正错误

1. `Ctrl - h` 删除前一个字符

2. `Ctrl - w` 删除前一个单词

3. `Ctrl - u` 删除至行首


## 技巧14：返回普通模式

1. Esc

2. Ctrl - [

3. Ctrl - o 插入-普通模式

4. `zz` 可以刷新屏幕，可以配合上条使用

## 技巧15：不离开插入模式，粘贴寄存器的文本

1. `yt{char}` 复制内容到专用寄存器中

2.  Ctrl - r + 0 把刚才复制的文本粘贴到光标所在位置

3. Ctrl - r {register} 粘贴寄存器的内容

4. Ctrl - r + Ctrl - p {register} 粘贴文本并修正不必要的缩进

## 技巧16：插入模式中做运算

1. Ctrl - r {运算内容} 可以做运算

## 技巧17：用字符编码插入非常用字符

1. Ctrl - v {code} 可以插入字符，同时也能够插入 Unicode 字符

2. 如果上述操作后续跟着非数字键，会插入按键本身代表的字符

3. Ctrl - k {char1}{char2} 以二合字母插入非常用字符

## 技巧18：用二和字母插入非常用字符

1. Ctrl - k {char1}{char2}

2. 常用分数 ½ 等可用分子分母数字表示

## 技巧19：用替换模式替换已有文本

1. R 从普通模式进入替换模式

2. gR 进入虚拟替换模式，会把 tab 当做一串空格处理

3. r{char} 和 gr{char} 允许覆盖一个字符然后回到普通模式, 后者是虚拟替换模式


## 技巧20：可视模式

1. `viw` 高亮选择某个词

2. `c` 删除词然后进入插入模式

## 技巧21：选择高亮选区

1. `v` 进入字符可视化模式

2. `V` 进入面向行的可视化模式

3. Ctrl - v 进入面向列块的可视化模式

4. `o` 调整可切换高亮区的左右活动端

5. `gv` 重选上次的高亮选区

## 技巧22：重复执行面向行的可视化命令

配合使用 `.` 操作符

## 技巧23：操作符命令优先可视命令

1. `U` 将所选文字转成大写

2. `vit` visually select inside the tag

3. `U` 在可视化模式下大写选中的文本，同下 `gU{motion}`

4. `gU` 让 text 大写

## 技巧24：面向列块的可视化模式编辑表格数据

1. `gv` 重新选区上次选区的分区

## 技巧25：修改列文本

1. `e` 表示的是到单词 end

2. `I` 表示光标至于行首并进入插入模式

## 技巧26：在长短不一的高亮块后添加文字

在 vim 中列块可视模式下，键入$进入插入模式，在插入模式期间输入内容只会作用在当前行，当返回普通模式时，就会将修改扩散到其余选中的行。

## 技巧27：认识命令行模式

1. `esc` 键可以任何时候从命令模式切换回普通模式

2. 出于历史原因，命令模式中的命令又被称为 Ex 命令

3. 按 `/` 或者 `Ctrl - r + =` 访问表达式寄存器都会激活命令模式

4. 读写命令 `:edit` `:write` 

5. 创建新标签页：`tabnew`

6. 分割窗口：`:split`

7. 操作参数列表：`:prev/next`

8. 操作缓冲区列表：`:bprev/bnext`

9. .... 太多了


## 技巧28：在一行或多个连续行上执行命令

1. :print :p 打印当前行，可以搭配数字或范围 {num}, {start, end}

  比如：: 2,3p, :.,$p, :%p

  其中 . 代表当前行，%代表当前文件中的所有行

  同时，支持 pattern

  数字可以为 0，作用可以对文件首部进行插入

2. :$ 跳到最后一行

3. `{num}G` 跳到某一行

4. :move{address} :copy{address} 移动或者删除操作

## 技巧29：使用 `:t` 和 `:m` 复制和移动行

1. :copy 用法 [range]copy {address}，其简写形式为 :co

2. 被可视模式选中的 `'<,'>` 代表了高亮选取，所以可以对他进行一些操作

3. dGp === :'<,'>m$

## 技巧30：在指定范围上执行普通模式命令

1. normal 代表普通模式下进行操作，后面可以跟常用的命令

2. 上述配合 VG 等使用比较好

## 技巧31：重复上次的 Ex 命令

1. `@:` 重复上次 Ex 命令

2. `@@` 重复上次 `@:` 重复的命令

3. 对于之前出现过的像 delete、yank、put、copy、move、join、noraml、substitute、pattern 等用 `u` 即可撤销其影响

4. 待后面详细了解 `bnext` 和 `bprevious` 命令


## 技巧32：自动补全 EX

1. 输入文字后 `ctrl - d` 能够让 vim 显示可用的补全列表

2. `tab` 能够补全，同时 `shift - tab` 能够反向补全

3. `set wildmoe=longest,list` 习惯 bash

4. `set wildmenu` 和 `set wildmode=full` 能够提供更友好的 zsh 补全菜单

## 技巧33：当前单词插入命令行

1. `*` 跳到下一个匹配项（相同单词上）

2. 打开某个字串的帮助文档 `:help Ctrl - r Ctrl-a`

## 技巧34：回溯命令

1. `set history=20` 可以设置历史记录的上限

2. `q:` 进入命令行窗口

3. 命令行切换到命令行窗口 `ctrl - f` 映射项切换到命令行窗口

## 技巧35：运行 shell 命令

1. `:!` 前缀可以在命令行下运行外部程序

2. `shell` 可以启动一个交互的 shell，执行几条命令

3. `shell` 中运行的 vim可以先通过 ctrl-z 挂起 vim 的进程，然后把控制权让出，然后可以通过 `fg` 唤醒 vim

其中可以通过 `shell` 的 `jobs` 命令查看被挂起的任务
**PS: nvim `shell` 被反对使用，请使用 `:te[rminal]`**

4. `write !${cmd}` 将缓冲区的内容作为制定 cmd 的标准输入

5. `read !{cmd}` 将命令的标准输出重定向到缓冲区（文件内？）

6. `[range]` 能够对外部命令进行过滤缓冲区内容，比如 `.,$!echo`

7. 快捷命令：`!G` === `:.,$`

## 技巧36：批处理 Ex 命令

1. 可以将 Ex 命令存在脚本里面并加载，然后 `:source` 执行命令

2. 可以 vim 一组文件 `vim *.js` 打开后可以通过 `args` 一个一个遍历这些文件，分别通过 `:first` 以及 `next` 可以遍历

## 技巧37：用缓冲区列表管理打开的文件

1. 我们编辑文件并不是在编辑文件，而是在编辑文件在内存中的缓冲区，也就是所说的 “缓冲区”

2. 一般我们的命令都是针对内存中缓冲区操作的，但也有直接对文件进行操作的，比如 `:write`, `:update`, `:saves`

3. `:ls` 能够列出载入缓冲区的列表，`:bnext` 能够切换到下一个缓冲区

4. 上面 `:ls` 列出的文件中，`%` 可指明那个缓冲区当前窗口可见，`#` 表示轮换文件

5. `Ctrl - ^` 可以在当前文件和轮换文件快速切换

6. `bprev` 和 `bnext` 前后移动，`:bfirst` 和 `:blast` 代表列表的开头和结尾

7. `:ls` 命令能够得到所有缓冲区，其中包含有自动分配的编号。可以通过 `buffer {num}` 或者 `buffer {name}` 跳到缓冲区

8. `:bd` 和 `:bdelete` 表示删除某一个或一个范围内的缓冲区

9. 可以感受到内置的缓冲区管理功能并不最佳

## 技巧38：用参数列表将缓冲区分组

1. `:args` 能够填充文件参数

2. `*` 用于匹配指定文件夹下面的文件，不会递归

3. `**` 可以递归地进入指定目录的子目录

4. 可以使用反引号括起来使用 shell 命令

5. `:next` 和 `:prev` 可以遍历缓冲区文件

## 技巧39：管理隐藏缓冲区

1. args `a` 代表的是活动缓冲区

2. args `h` 代表的是隐藏缓冲区

3. `qall!` 退出所有分区不保存修改无须检查

4. `wall` 保存所有缓冲区的修改无须检查

5. `set hidden` 后就可以不用结尾带叹号执行 next 等命令

## 技巧40：将工作区切分成窗口

1. `Ctrl - w + s` 水平切分窗口，`Ctrl - w + v` 垂直切分

2. 先执行 `Ctrl - w + s` 再 `:edit {filename}` 把文件划分成了两个窗口，并在另一个新的缓冲区

3. `split {filename}` 命令将上述步骤合二为一

4. `:sp {filename}` 和 `:vsp {filename}` 分别水平和垂直切分当前窗口，并载入 {file}

5. `Ctrl - w + w` 循环切换， `Ctrl - w + h|j|k|l` 分别于方向键切换的窗口相同

6. `Ctrl - w` 两次也可以循环切换

7. `Ctrl - w + c` 关闭活动窗口，`Ctrl - w + o` 保留活动窗口， 关闭其他所有窗口


## 技巧41：用标签页将窗口分组

1. `tabe[edit] {filename}` 打开一个新标签页

2. `Ctrl - w + T` 创建并移动到新的标签页

3. `:tabn[ext] {N}` 和 `gt {N}` 切换到编号为 N 的标签页，可以省略 N

4. `:tabp[revious]` 和 `gT` 切换到上一个标签页

5. `:tabm[ove] {N}` 重新排列标签页到 N

6. `:tabc[lose]` 删除该  tab

## 技巧42：用 :edit 打开文件

1. 使用 `:e[dit]` 打开绝对或者相对路径

2. 使用 `:e %<Tab>` 来补全完整的文件路径, 使用 `:e %:h<Tab>` 来补全同时省略该文件名

3. 可以对 `%:h` 进行扩展，为他创建一个映射项.

## 技巧 43：使用 find 命令打开文件

1. 首先得配置 `path`，命令：`:set path+=dir/**` 执行

2. 有些插件会自动设置 path 选项

## 技巧44：使用 netrw 管理文件系统

1. vim 自带了 netrw 插件，它属于一种标配插件

2. `-` 返回上级目录

3. 可以使用 `/` 来快速查找并打开文件

4. `:e.` 与 `:E` 相对活动文件打开一个文件

5. `:Sexplore` 与 `:Vexplore` 分别在一个水平和垂直窗口打开文件管理器

5. `netrw` 插件支持网络读写文件，包括多种协议


## 技巧45：把文件保存到不存在的目录中

1. 使用 `:e` 打开一个新的文件会创建一个缓冲区

2. 当使用上述命令来打开不存在文件夹中的文件时，已然会创建缓冲区，但是无法 `:w` 对文件进行写入磁盘的操作

3. 但是可以通过执行 `shell` 创建新目录 `:!mkdir -p %:h`

**PS：`%` 代表了活动缓冲区的完整文件路径，`:h` 修饰符去除了文件名但保留了路径**

## 技巧46：以超级管用户权限保存文件

1. 对于需要 root 权限的文件而言，一般可以 `sudo vim` 来对文件进行修改，也可以 `:w !sudo tee % > /dev/null`

# motions 动作命令 

## 技巧47：让手指保持在本位行上

1. **禁止在使用 vim 的时候使用上下左右，取而代之的是 `hjkl`**

2. 右手保持在该在的位置上，也就是食指总是在 `j` 上，左右应当用更快的移动方式 -- 面向单词

3. 可以使用 `normap` 来禁用上下左右键盘

## 技巧48：区分实际行和屏幕行

1. `wrap` 被启用时每个超出窗口宽度的文本行都会回绕显示

2. `number` 启用设置可以显示实际行号

3. `j` 和 `k` 在屏幕实际行上移动，而 `gj` 和 `gk` 在屏幕行上下移动

4. `j k 0 $` 都操纵实际行，但是可以在前面加上 `g` 前缀操作屏幕行

5. 可以重新做映射是的操作屏幕行映射到实际行上

## 技巧49：基于单词的移动

1. `w` 和 `b` 都是以行首为目标，前者是下一个单词的开头，后者是当前或上一个单词的开头

2. `e` 和 `ge` 都以词尾为目标，前者是正向移动，后者是反向移动

3. `w` 和 `e` 正向移动单词，`b` 和 `ge` 反向移动单词

4. vim 中有“单词”和“字串”两种定义，前者是 `word`，后者是 `WORD`
   
5. 所以也就还有 `W` `B` `E` 以及 `gE`

## 技巧50：对字串进行查找

1. `f{char}` 是 vim 中移动最快的方式之一，他会在本行查找指定 char

2. 上述命令重复一般用 `;`，返回一般使用 `,`

3. 反向字符查找命令是缺省的 `<leader>` 键，允许将其他键映射到别的键

4. `f{char}` 正向移动到下一个 {char} 位置上，
   `F{char}` 反向移动到上一个 {char} 位置上，
   `t{char}` 正向移动到下一个 {char} 的前一个字符上，
   `T{char}` 反向移动到上一个 {char} 的后一个字符上。
    
   `t{char}` 在配合 `d{motion}` 删除逗号后面的句子比较实用

## 技巧51：通过查找进行移动

1. `/{word}` 能够对单词匹配，同时还能匹配当前行之外的

2. 这种操作也可以在可视模式以及操作符待决策模式中使用

## 技巧52：用精确的文本对象选择选区

1. vim 能够理解类似像 HTML 标签那样具有规整格式的结构

2. 配合 `i[nside]` 和 `a[ll]` 使用，后面可以填： 
  `t`
  `\`` `'` `"`
  `(|b` `[` `{|B` 等

3. 可以用于可视模式以及各种 `operator` 后，常见的比如说
  `d{motion}` `c{motion}` `y{motion}`

## 技巧53：删除周边，修改内部

1. vim 中文本对象有两类，一类用于操作对象内部的文本，另一类则操作对象周围的文本

2. `i` 和 `a` 后面可以跟着 `w`、`W` `s` 和 `p` 集中范围，`a` 稍微要多点空格或空行，可以记为周围（around）和内部（inside）

3. 一般来说 `d` 操作符和各种 `a` 更配，`c` 和 `iw` 更配

## 技巧54：设置位置标记， 以便快速调回

1. `m{a-zA-Z}` 可以对选定的字母标记当前光标所在的位置

2. `'{mark}` 会跳到位置标记的所在行，并把光标置于该行的第一个非空白字符上

3. ``{mark}` 会调到位置标记的所在行所在列，更加精确

4. 可以运用上述精确跳转交换两个词

5. vim 会自动做一些标记

## 技巧55：在匹配括号间跳转

1. `%` 命令可以作用于 (), {}, [] 间跳转

2. `%` 先执行一遍会使得 vim 自动对之前发生跳转的位置做标记，可以通过 `Ctrl - o` 或 ```` 跳转到原来位置

3. vim 发布时自带了一个 `matchit` 插件，增强了 `%` 命令，激活后就能够在开或闭标签跳转

4. 使用 `runtime marcos/matchit.vim` 启用插件

5. 使用 sourround.vim `S"` 插件能够很容易的为文本添加分隔符（以双引号为例），也可以对分隔符进行修改：`cs}]`

## 技巧56：遍历跳转列表

1. `Ctrl - o` 和 `Ctrl - i` 能对跳转列表进行遍历，前者是后退，后者是前进

2. `:jumps` 命令用于查看文件列表内容

3. `[count]G` 可以跳转到指定行号


4. `(` 和 `)` 跳转上一句或下一句的开头，`{` 和 `}` 跳转到上一段或者下一段的开头


5. `H|M|L` 跳转到屏幕最上方、正中间或最下方

6. `Tab` 和 `Ctrl - i` 同为前进键

## 技巧57：遍历改变列表

1. `:changes` 维护了一张改变列表，里面记录了对每个缓冲区所做的修改

2. `g,` 和 `g;` 分别正向和反向遍历，这与 `f{char}` 表现相反

3. ``^` 回到上次插入的位置，`gi` 回到上次推出插入的位置同时进入插入模式

## 技巧58：跳转到光标下的文件夹

1. `gf` 可以跳转到光标所在文件

2. `:set suffixesadd+=.rb` 为文件添加后缀名

3. 可以配合 `Ctrl - o` 进行来回切换的操作

4. 对于第三方库提供的功能，设置 `path ` 就能够匹配到

5. 与此类似，移步技巧（如移动到某个函数定义）需要一些配置 `Ctrl - ]`

## 技巧59：用全局位置标记在文件间快速跳转

1. `m{letter}` 标记当前光标位置，小写字母创建局部标记，大写创建全局标记，``{letter}` 快速跳转到标记位置

2. 在浏览代码钱设置一个全局标记比较常用，然后就能使用 `Ctrl - o` 返回原来的位置

3. 一般来说，在使用 `:grep` `:vimgrep` `:make` `:args {arglist}` 以及 `argdo` 之前要设置全局标记

4. 26和全局位置标记基本用不完

## 技巧60：用无名寄存骑实现删除、复制和粘贴操作

1. 对于字符而言，`xp` 可以用于替换光标**之后**的两个字符

2. 对于文本而言，`ddp` 用于剪切当前行并将内容复制到光标**之后**

3. `yy` 创建副本

4. `P` 复制到从光标前，`p` 复制到光标后

## 技巧61：深入理解 Vim 寄存器

1. `"{register}` 可以通过命令指定要使用的寄存器，不指明的情况下缺省使用无名寄存器

2. 与 cut、copy 和 paste 相对，Vim 使用 delete、yank 和 put

3. `"ayiw` 和 `"bdd` 以及 `"ap` 都指明了寄存器 `a`，有名寄存器有 26个字母的数字，形如大写 `A` 这样的形式可以将新内容添加到原有内容之后 

4. 可以使用 Ex 命令，配合 `:global` 命令可以达到很好的效果

5. `""` 即无名寄存器

6. `x` 和 `d` 应该说是剪切操作更恰当

7. 复制专用寄存器可以使用数字 `0` 来表示，只有在使用 `y{motion}` 时候才会被使用

8. 黑洞寄存器 `"_`

9. `"+` 系统剪贴板，`"*` 选择专用寄存器（X11系统专用），windows 和 mac 没主剪切板的概念，两者可以混用

10. `"=` 表达式寄存器，在后续会提到

11. 还有很多寄存器，参见 `:h quote`

## 技巧62：用寄存器的内容替换高亮选区的文本

1. 可视模式下能够替换高亮选区，同时使用被替换的内容替换掉无名寄存器的内容

2. 交换两个单词可以使用，记住剪切第一个单词前标记位置

## 技巧63：把寄存器的内容粘贴出来

1. `xp` `diw` 等等，面向字符的粘贴位置与光标位置有关

2. 插入模式下可以通过 `Ctrl - r + 0` 来插入复制专用寄存器的内容，此种方式对于字符和小段文字更直观

3. `dd` `yy` 等等，面向行的粘贴会粘贴到当前行的上一行或下一行

4. `gp` `gP` 分别粘贴到当前行的上一行和下一行，并把光标位置放在被粘贴行的后面

## 技巧64：与系统剪贴板进行交互

1. 以前粘贴含有注释的话比较惨，会自动换行。。。 然后非常诡异

2. 对于上述情况，可以启用 `paste` 模式，然后粘贴完了在回来

3. 但是对上述不推荐，建议直接使用系统剪贴板 `"+p` 或 `"*p` 

> 另一半内容换文件了~~~

