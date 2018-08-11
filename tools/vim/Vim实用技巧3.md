
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

