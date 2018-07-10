const http = require('http')
const Router = require('./router')
const request = require('./request')
const response = require('./response')
const middleware = require('./middleware/init')

class Application {
  lazyrouter() {
    if (!this._router) {
      this._router = new Router()
      this._router.use(middleware.init(this))
    }
  }

  listen(port, callback) {
    var server = http.createServer((req, res) => {
      this.handle(req, res)
    })

    return server.listen.apply(server, arguments)
  }

  handle(req, res) {
    const done = function finalhandler(err) {
      res.writeHead(404, {
        'Content-Type': 'text/plan',
      })

      if (err) {
        res.end('404: ' + err)
      } else {
        var msg = 'Cannot ' + req.method + ' ' + req.url
        res.end(msg)
      }
    }

    // 这里无需调用lazyrouter，因为listen前一定调用了.use或者.METHODS方法。
    // 如果二者都没有调用，没有必要创建路由系统。this._router为undefined
    const router = this._router
    if (router) {
      router.handle(req, res, done)
    } else {
      done()
    }
  }

  use(fn) {
    this.lazyrouter()
    var path = '/',
      router = this._router
    
    if (typeof fn !== 'function') {
      path = fn
      fn = arguments[1]
    }

    router.use(path, fn)

    return this
  }
}

http.METHODS.forEach(method => {
  method = method.toLowerCase()
  Application.prototype[method] = function(path, fn) {
    this.lazyrouter()
    this._router[method].apply(this._router, arguments)
    return this
  }
})

module.exports = Application

exports.Router = Router
