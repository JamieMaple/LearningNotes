# docker 学习笔记

### command

> display docker info

1. `docker --version` 查看版本号

1. `docker info` 查看更多版本细节

> exec docker image

1. `docker run <image> -p <own-port:docker-port>` 运行一个镜像

`-d` 可以开启 `attach mode`

> list docker images

1. `docker image ls <selector>` 列出镜像列表

> list docker containers

1. `docker container ls --all` 获取容器信息，`--all` 获取没在运行时候的容器，`--quiet` 静默模式

> 停止指定 `container`

1. `docker container stop <container_id>`

> 登录

1. `docker login`

> 运行 docker 同时 attach mod 同时做端口映射

1. `docker run -d -p <p1:p2> <username>/<repo>:<tag>`

> 查看容器存储层的变动

1. `docker diff`

> 构建镜像

1. `docker build -t <tag> <path|URL>`

   如果使用 `.` 则代表的是使用相对上下文目录下的

### containers

1. `Dockerfile` 用来定制镜像

   包含了一条条指令，每一条指令构建一层，所以每一条指令的内容描述了该层如何构建

   `COPY` 复制文件

   `ADD` 可以让原路径为一个 `url`，还能在有些时候自动解压，应尽可能多的使用 `COPY`

   `CMD` 和 `RUN` 很相似，支持两种参数格式，但是 `shell` 字符串形式其实本质上是 `CMD ["sh", "-c", "<cmd>"]`

   `ENTRYPOINT` 目的和 `CMD` 一样，都是在指定容器启动程序及参数。但是在某些方面不太一样

   `ENV` 设置环境变量，其他一些命令支持环境变量展开

   `ARG` 也是设置环境变量，有所不同的是构建时的环境变量，运行时是不能存在的

   `VOLUME` 定义匿名卷

   `EXPOSE` 声明容器内部使用的端口

   `WORKDIR` 指定工作目录

   `USER` 指定当前用户

   `HEALTHCHECK` 健康检查

### service

> a `docker-compose.yml` file is a YAML file that defines how Docker containers should behave in production.

1. `docker-compose.yml`

1. `docker swarm init`

1. `docker stack deploy`

1. `docker service (ls|ps)`

1. `docker stack rm <task>` take app down

1. `docker swarm leave --force` take down the swarm

1. `docker diff <container>` 比对容器存储层的变化

1. `docker commit <options> <image>` 改变容器存储区之后保存下来成为新的镜像，不应该用此来定制

1. `docker history <image>` 查看镜像内历史记录

### swarms

1. `docker swarm init` enable swarm mode and make your current machine a swarm manager

### stack

