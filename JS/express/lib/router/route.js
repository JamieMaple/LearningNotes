const http = require('http')
const Layer = require('./layer')

class Route {
  constructor(path) {
    this.path = path
    // route items(layers) stack
    this.stack = []

    this.methods = {}
  }

  _handles_method(method) {
    const methodName = method.toLowerCase()
    return Boolean(this.methods[methodName])
  }

  dispatch(req, res, done) {
    var self = this,
      method = req.method.toLowerCase(),
      idx = 0, stack = self.stack
    
    function next(err) {
      if (err && err === 'route') {
        return done()
      }
      
      if (err && err === 'router') {
        return done(err)
      }

      if (idx >= stack.length) {
        return done(err)
      }

      const layer = stack[idx++]
      if (method != layer.method) {
        return next(err)
      }

      if (err) {
        layer.handle_error(err, req, res, next)
      } else {
        layer.handle_request(req, res, next)
      }
    }
    
    next()
  }
}

// not only `get` but also all methods
http.METHODS.forEach(method => {
  method = method.toLowerCase()
  Route.prototype[method] = function(fn) {
    const layer = new Layer('/', fn)
    layer.method = method

    this.methods[method] = true
    this.stack.push(layer)

    return this
  }
})

module.exports = Route
