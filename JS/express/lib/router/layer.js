/*
 ** both layer and item(route) objects use this class
 */
class Layer {
  constructor(path, fn) {
    this.handle = fn
    this.name = fn.name || '<anonymous>'
    this.path = undefined
    this.fast_star = (path === '*' ? true : false)

    if (!this.fast_star) {
      this.path = path
    }
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
    // 如果 *，匹配
    if (this.fast_star) {
      this.path = ''
      return true
    }

    // 如果是普通路由，从后匹配
    if (this.route && this.path === path.slice(-this.path.length)) {
      return true
    }

    if (!this.route) {
      // middlewares
      if (this.path === '/') {
        this.path = ''
        return true
      }
      // route middlewares
      if (this.path === path.slice(0, this.path.length)) {
        return true
      }
    }

    return false
  }
}

module.exports = Layer