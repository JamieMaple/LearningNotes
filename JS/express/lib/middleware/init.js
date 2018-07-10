var request = require('../request')
var response  = require('../response')

exports.init = function(app) {
  return function expressInit(req, res, next) {
    req.res = res
    res.req = req
  
    Object.setPrototypeOf(req, request)
    Object.setPrototypeOf(res, response)
  
    next()
  }
}