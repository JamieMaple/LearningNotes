const assert = require('assert')

function shouldRejected(promise) {
  return {
    'catch': function(fn) {
      return promise.then(function() {
        throw new Error('Expected promise to be rejected but it was fulfilled')
      }, function(reason) {
        fn.call(promise, reason)
      })
    }
  }
}

function shouldFullfilled(promise) {
  return {
    'then': function(fn) {
      return promise.then(function(v) {
        fn.call(promise, v)
      }, function(reason) {
        throw reason
      })
    }
  }
}

it('should be rejected', function() {
  var promise = Promise.reject(new Error('wowo'))
  return shouldRejected(promise).catch(function(err) {
    assert(err.message === 'wowo', 'Error message should be wowo')
  })
})

it('should be resolved', function() {
  var promise = Promise.resolve(123)
  return shouldFullfilled(promise).then(function(v) {
    assert(v === 123, "value should equals 123")
  })
})
