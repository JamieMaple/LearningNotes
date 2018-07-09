const http = require('http')

/*
 ** both layer and item(route) objects use this class
 */
class Layer {
  constructor(path, fn) {
    this.handle = fn
    this.name = fn.name || '<anonymous>'
    this.path = path

    // if Layer class use for route
    // there have to be `method`
  }

  handle_request(req, res, next) {
    var fn = this.handle
    try {
      fn(req, res, next)
    } catch(err) {
      next(err)
    }
  }

  handle_error(error, req, res, next) {
    const fn = this.handle

    if (fn.length !== 4) {
      return next(error)
    }

    try {
      fn(error, req, res, next)
    } catch(err) {
      next(err)
    }
  }

  match(path) {
    if (path === this.path || path === '*') {
      return true
    }
    return false
  }
}

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

class Router {
  constructor() {
    this.stack = []
  }

  handle(req, res, done) {
    var self = this,
      method = req.method,
      idx = 0, stack = self.stack
    
    function next(err) {
      const layerError = (err === 'route' ? null : err)

      if (layerError === 'route') {
        return done(null)
      }
      
      if (idx >= stack.length || layerError) {
        return done(layerError)
      }

      let layer = stack[idx++]
      if (layer.match(req.url) && layer.route && layer.route._handles_method(method)) {
        return layer.handle_request(req, res, next)
      } else {
        next(layerError)
      }
    }
    
    next()
  }

  route(path) {
    const route = new Route(path)
    const layer = new Layer(path, route.dispatch.bind(route))

    layer.route = route
    this.stack.push(layer)

    return route
  }

  use(fn) {
    let path = '/'
    if (typeof fn !== 'function') {
      path = fn
      fn = arguments[1]
    }

    var layer = new Layer(path, fn)
    layer.route = undefined
    this.stack.push(layer)

    return this
  }
}

http.METHODS.forEach(method => {
  method = method.toLowerCase()
  Router.prototype[method] = function(path, fn) {
    const route = this.route(path)
    route[method].call(route, fn)

    return this
  }
})

module.exports = Router

