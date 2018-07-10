const http = require('http')
const url = require('url')
const Route = require('./route')
const Layer = require('./layer')

const proto = {}
proto.handle = function(req, res, done) {
  var self = this,
    method = req.method,
    idx = 0, stack = self.stack,
    removed = '', slashAdded = false

    // 获取当前父路径
    var parentUrl = req.baseUrl || ''
    // 保存父路径
    req.baseUrl = parentUrl
    // 保存原始路径
    req.originalUrl = req.originalUrl || req.url

  function next(err) {
    const layerError = (err === 'route' ? null : err)

    // 如果移除，复原原有路径
    if (slashAdded) {
      req.url = ''
      slashAdded = false
    }

    // 如果有移除，复原原有路径信息
    if (removed.length !== 0) {
      req.baseUrl = parentUrl
      req.url = removed + req.url
      removed = ''
    }

    if (layerError === 'router') {
      return done(null)
    }
    
    if (idx >= stack.length) {
      return done(layerError)
    }

    const path = url.parse(req.url).pathname

    const layer = stack[idx++]

    if (layer.match(path)) {
      
      // handle middlewares
      if (!layer.route) {
        // 要移除的部分路径
        removed = layer.path
        
        // 设置当前路径
        req.url = req.url.substr(removed.length)
        if (req.url === '') {
          req.url = '/' + req.url
          slashAdded = true
        }

        // 设置当前路径的父路径
        req.baseUrl = parentUrl + removed

        // call handler
        layer.handle_request(req, res, next)
      } else if (layer.route._handles_method(method)) {
        // handle routes
        layer.handle_request(req, res, next)
      }
    } else {
      layer.handle_error(layerError, req, res, next)
    }
  }
  
  next()
}

proto.route = function(path) {
  const route = new Route(path)
  const layer = new Layer(path, route.dispatch.bind(route))

  layer.route = route
  this.stack.push(layer)

  return route
}

proto.use = function(fn) {
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

http.METHODS.forEach(method => {
  method = method.toLowerCase()
  proto[method] = function(path, fn) {
    const route = this.route(path)
    route[method].call(route, fn)

    return this
  }
})

module.exports = function() {
  function router(req, res, next) {
    router.handle(req, res, next)
  }
  Object.setPrototypeOf(router, proto)
   
  router.stack = []

  return router
}

