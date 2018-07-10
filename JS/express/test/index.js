const expross = require('../')
const app = expross()
const router = expross.Router()

router.use('/1', function(req, res, next) {
  res.send('first user')
})

router.use('/2', function(req, res, next) {
  res.send('second user')
})

app.use('/users', router)

app.use(function(req, res, next) {
  console.log('Time: ', Date.now())
  next()
})

app.get('/', function(req, res, next) {
  res.send('get /')
})

// console.log(app._router)
app.listen(8080, function() {
  console.log('> Server listening at port 8080')
})
