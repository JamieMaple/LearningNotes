const http = require('http')

function composeMiddleware(middlewares) {
  return ctx => {
    return middlewares.reduceRight((next, middleware) => middleware.bind(undefined, ctx, next), () => Promise.resolve())()
  }
}

class Context {
  constructor(req, res) {
    this.req = req
    this.res = res
  }

  send(data) {
    this.res.write(JSON.stringify(data))
    this.res.end()
  }
}

class Koa {
  constructor() {
    this.middleware = []
  }

  use(fn) {
    this.middleware.push(fn)
  }

  listen(...args) {
    const server = http.createServer(this.callback())
    return server.listen(...args)
  }

  callback() {
    return (req, res) => {
      const ctx = new Context(req, res)
      composeMiddleware(this.middleware)(ctx)
    }
  }
}

// test
const middleware1 = async (ctx, next) => {
  const data = await next()
  ctx.send(data)
}
const middleware2 = async (ctx, next) => {
  await next()
  return { data: 'foo data' }
}

const app = new Koa()
app.use(middleware1)
app.use(middleware2)
app.listen(8080, () => { console.log('listening on port 8080') })