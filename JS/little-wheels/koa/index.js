const Koa = require('koa')

const app = new Koa()

const searchData = data => new Promise(res => res(data))

app.use(async (ctx, next) => {
  const data = await next()
  ctx.body = data
})

app.use(async (ctx, next) => {
  const data = await searchData({ data: 'test data' })
  return data
})

app.listen(8080, () => {
  console.log('listening on port 8080')
})