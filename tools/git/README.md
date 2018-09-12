# Git

> 为了更好理解并使用好 git，打算重新学好 git

## 三种工作区，三个状态

### 三种工作区

`working-direcotry`、`staging area` 以及 `repository`

1. 其中 git repository（也就是仓库）用以保存项目元数据以及对象数据库，clone 到时候就是拷贝的这里

2. 其中 working directory （也就是工作区）是项目对某个版本独立提取出来的内容，通常我们使用或修改的目录

3. 其中 staging area （也就是暂存区）是一个文件，保存了下次将提交的文件列表信息，有时候被称为 `索引`

#### 基本工作流程

1. 在 working directory 修改文件

2. 暂存文件，把文件的快照放入暂存区域

3. 提交更新，找到暂存区的文件，将快照永久性存储到 Git 仓库

#### 常用的命令行操作

1. git config ...，三级目录 `/etc/gitconfig` `~/.gitconfig` `.git/config`

2. `git help`

#### Git 基础

1. `git init` 会创建一个 `.git` 的子目录文件

2. `git add` `git commit` 

3. `git clone` 支持多种数据传输协议

### 三个状态

> 最初的状态：`Untracked`

1. `add file`

2. `remove file`

`commited（已提交）`、`modified（已修改）` 以及 `staged（已暂存）`

1. 工作目录下无非是两种状态：`tracked（跟踪）` 和 `untracked（未跟踪）`, 如果已经跟踪的文件被修改，需要 `stage for commit`

2. 编辑过某些文件后处于 `modified` 状态，放入暂存区然后提交了修改后变回了未修改状态

3. `git status` 查看当前状态

4. `.gitignore` 可以忽略文件，

5. `git diff` 可以查看已暂存和未暂存的修改，也就是说仅针对 `git add `

6. `git commit` 提交到仓库，`git commit -a` 能够跳过 `add` 步骤

7. `git rm` 从工作目录中删除文件记录

8. `git mv` 移动或者重命名文件本质上三条命令： `mv` `git rm` `git add`

9. `git log` 用于回顾提交历史，`-p` 显示每次提交内容的差异，`-{n}` 代表最近提交几次，`--stat` 能够看到简略的统计信息，**很有用的一条：`--graph`** 可以看到一个图，大量的参数

10. `git commit --amend` 会尝试重新提交

11. `git add` 会暂存多个内容，如果要取消暂存某些文件，就只需 `git reset HEAD <file>` 来取消暂存

12. `git checkout -- <file>` 撤销之前对某个文件所做的修改

### 远程仓库

1. `git remote` 查看远程仓库服务器

    `-v` 参数可以显示对应的 URL

    `add <shortname> <url>` 可以用来添加 git 新仓库

    `show` 显示远程仓库的一些信息

    `rm` 删除远程仓库

    `rename` 重命名远程仓库名

2. `git fetch <shortname>` 能够从远端拉取所有还没的数据 

3. `git pull <remote-name> <branch-name>` 能够自动抓取然后合并远程分支到主要分支

4. `git push <remote-name> <branch-name>` 能够将分支内容推送到

5. `git remote <remote-name> <new-name>` 重命名远程仓库

6. `git remote rm <remote-name>` 删除远程仓库

#### `git tag` 标签相关

1. `git tag` 列出已有的标签

##### 创建标签

轻量标签（lightweight）和附注标签（annotated）

1. 附注标签

cmd: `git tag -a {tagName} -m '{message}'`

其中 `-a` 选项是指附注标签（annotated），`-m` 选项是指提交的信息

`git show` 查看标签信息与对应的提交信息

2. 轻量标签

`git tag {tagname}` 无需 `-a` `-s` 以及 `-m` 参数，只需提供标签名字

#### Git Alias

``` shell
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status

# 取消暂存文件
git config --global alias.unstage 'reset HEAD --'

# last log
git config --global alias.last 'log -1 HEAD'

# 外部命令，使用 `!`
git config --global alias.vim '!vim'
```

## Git 分支

Git 分支本质上仅仅是指向提交对象的可变指针，默认分支为 `master`

Git 有一个特殊名为 `HEAD` 的指针

进行提交操作时，Git 会保存一个提交对象（commit object），该对象会包含一个纸箱暂存内容快照的指针

`git commit` 提交时：

1. 先计算每一个子目录的校验和，然后再 Git 仓库中校验和保存为树对象

2. Git 创建一个提交对象，包含一些信息同时包含纸箱这个树对象的指针

3. 做些修改后再次提交，产生的提交对象会包含一个指向上次提交对象的指针

### Git 仓库中几大对象

1. blob 对象（保存着文件快照）

2. 树对象（记录着目录结构和 blob 对象索引）

3. 提交对象（包含着指向前述树的指针与所有提交信息）

### 常见的命令

1. `git branch {branch-name}` 创建一个新分支，实际上只是创建一个可移动的新指针

2. `git log --decorate`





