const Application = require('./application')
const Router = require('./router')

function createApplication() {
  const app = new Application()
  return app
}

exports = module.exports = createApplication
exports.Router = Router
