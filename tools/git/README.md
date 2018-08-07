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

`commited（已提交）`、`modified（已修改）` 以及 `staged（已暂存）`

1. 工作目录下无非是两种状态：`tracked（跟踪）` 和 `untracked（未跟踪）`

2. 编辑过某些文件后处于 `modified` 状态，放入暂存区然后提交了修改后变回了未修改状态

3. `git status` 查看当前状态

4. `.gitignore` 可以忽略文件，


