const MPromise = require('./index')

// test-1
new MPromise((res, resj) => {
  setTimeout(res, 1000, "data")
}).then(value => {
  console.log(value)
  return "next value"
}).then(value => {
  console.log(value)
  return `next ${value}`
})

for (let i = 0; i < 10; ++i) {
  console.log(i)
}