
# 工具

> ctags

## 技巧102：认识 ctags

1. 可以使用它来快速跳转到函数或者类的定义，也可以用于建立自动补全的单词列表

2. OSX 安装 ctags: `brew install ctags`

## 技巧103：配置 Vim 使用 ctags

1. 首先确保 tag 文件是最新的，`set tags` 设置 tags 文件路径

   查看 tags 默认情况：`:set tags?` 

   每次版本管理时候最好忽略掉 `tags` 文件 
   `!tags - R` 可以在 vim 中手动执行 ctags

2. 可以对键盘做映射

   比如 `:nnoremap <F5> :!tags -R<CR>`

3. 可以在每次保存的时候自动执行 ctags

   `:autocmd BufWritePost * call system("ctags -R")`

4. 通过版本控制工具的回调机制自动执行 ctags
  
   比如 git 的几个钩子 hooks

5. `Ctrl - ]` 通过此条命令可以从关键词处跳转到他的定义处，然后可以通过 `Ctrl-t` 回到原来的地方，等价于 `:pop`

6. 当出现多个匹配时，存在优先级关系，我们可以从中进行选取，查阅 `:h tag-priority`

7. `:tselect` `:tprev` `:tnext` `:tfirst` `:tlast`

8. 当关键词有多个时，我们可以使用 `g<Ctrl-]>` 来从匹配列表中选取我们需要的

9. 可以通过使用 `:tag {keyword}` 与 `:tjump {keyword}`，两者分别等同于 `<Ctrl - ]>` 以及 `g<Ctrl - ]>`，另外这些 Ex 命令可以使用正则表达式

# Quickfix 列表

## 技巧105：不用离开 Vim 也能编译代码

1. `:make` 会让 Vim 在 quickfix 列表每一项创建一项记录并让光标跳到第一处错误，`:make!` 会保持光标位置不变

2. `:cn[ext]` 和 `:cp[revious]` 分别在 quickfix 列表中前进和返回，也可以使用 `Ctrl - i` 和 `Ctrl - o`

## 技巧106：浏览 Quickfix 列表

1. `:h quickfix` 查看更多

4. `:c` 开头
   `:cn[ext]` `cp[rev]`
   `:cf[irst]` `cl[ast]`
   `cnfile` `cpfile` 跳转到到下一个文件的第一项、上一个的最后一项
   `cc N` 跳转到某一项
   `copen` `cclose` 打开或关闭 quickfix，当它是活动窗口时，可以 `:q`
   `cdo {cmd}` `cfdo {cmd}` 每一行执行 每个文件执行
   填充 quickfix 命令有很多：`:make` `:grep` `:vimgrep` 等等发，只能有一个列表
   `:lmake` `:lgrep` `:lvimgrep` 创建位置列表不限制
   
## 技巧107：回溯以前的 Quickfix 列表

1. `:colder` 可以回溯 quickfix 之前的版本

2. `:cnewer` 可以回到比较新的列表

## 技巧108：定制外部编译器

1. `makeprg` 允许指定 `:make` 时调用的程序

2. `nodelint` 反对使用，还是使用 `eslint` 故不再深入，需要时再深入使用

# 通过 grep、vimgrep 以及其他工具对整个工程进行查找

## 技巧109：不必离开 vim 也能调用 grep

1. `grep`

2. `:grep` vim 会自动加入 `-n` 参数显示行号，`-i` 参数不区分大小写

## 技巧110：定制 grep 程序

1. `:grep` 是外部 grep 的包装，可以配置 `grepprg` 和 `grepformat` 两个选项

2. `ack` 可以取代 `grep` 的外部程序

3. `Ack.vim` 插件

## 技巧111：使用 Vim 内置正则表达式引擎的 Grep

1. `:vimgrep` 会把所有匹配项都放入 quickfix 列表，然后可以使用 quickfix 的命令

2. 通用格式：`:vim[grep][!] /{pattern}/[g][j] {file}...`

3. `##` 表示参数列表的所有文件

4. 同样也适用于 `:vimgrep` 可以先匹配模式，再让模式域为空

# 自动补全

