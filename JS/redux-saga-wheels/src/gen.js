function timer(time) {
  return new Promise(res => setTimeout(res, time, "data"))
}

function runGen(g) {
  const it = g()

  return new Promise(res => {
    function next(arg) {
      const result = it.next(arg)

      if (!result.done) {
        return Promise.resolve(result.value).then(next)
      } else {
        res(result.value)
      }
    }
    next()
  })
}

function *logic() {
  let data = yield timer(1000)
  console.log(data)
  data = yield timer(2000)
  console.log(data)
}

runGen(logic)

