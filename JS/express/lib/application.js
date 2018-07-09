const http = require('http')
const Router = require('./router')

class Application {
  constructor() {
    this._router = new Router()
  }

  listen(port, callback) {
    var server = http.createServer((req, res) => {
      this.handle(req, res)
    })

    return server.listen.apply(server, arguments)
  }

  handle(req, res) {
    if (!res.send) {
      res.send = function(body) {
        res.writeHead(200, { 'Content-Type': 'text/plain' })
        res.end(body)
      }
    }

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
    
    const router = this._router
    router.handle(req, res, done)
  }

  use(fn) {
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
    this._router[method].apply(this._router, arguments)
    return this
  }
})

module.exports = Application
