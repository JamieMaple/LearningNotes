const assert = require('assert')

const {
  isPromise,
  TPromise,
} = require('./index')

describe('Promise async', function() {
  it('Promise should perform async correctly: timeout', function() {
    const testData = 'seconde inside'
    return new Promise((resolve, reject) => {
      setTimeout(resolve, 100, 'inside')
    })
    .then(data => console.log(data))
    .then(data => console.log(data))
    .then(() => {
      return new Promise((resolve, reject) => {
        setTimeout(resolve, 100, testData)
      })
    }).then((data) => {
      assert(data === testData)
    }).catch(() => {
      throw new Error('out!')
    })
  })
})
