const expross = require('../')
const app = expross()

app.put('/', function bar(req, res, next) {
  res.send('hello wolrd')
  next()
})

app.get('/', function foo(req, res, next) {
  next(new Error('Error'))
})

app.get('/', function(error, req, res, next) {
  res.send('error')
})

// console.log(app._router)
app.listen(8080, function() {
  console.log('> Server listening at port 8080')
})
