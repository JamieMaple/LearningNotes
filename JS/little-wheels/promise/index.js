const PENDING = 'PENDING'
const FULFILLED = 'FULFILLED'
const REJECTED = 'REJECTED'

function triggerPromiseReactions(promise, nextPromiseCapability, reactionFn) {
  const nextPromise = nextPromiseCapability.promise

  setTimeout(() => {
    try {
      nextPromise.value = reactionFn.call(undefined, promise.value)
      nextPromiseCapability.resolve.call(nextPromise, nextPromise.value)
    } catch(err) {
      nextPromise.value = err
      nextPromiseCapability.reject.call(nextPromise, nextPromise.value)
    }
  }) 
}

function createResolvingFunction(promise) {
    function resolve(value) {
      setTimeout(() => {
        if (promise.status === PENDING) {
          promise.value = value
          promise.status = FULFILLED
          promise.fulfillReactions.forEach(reaction => triggerPromiseReactions(promise, reaction.promiseCapability, reaction.callback))
          promise.fulfillReactions = []
          promise.rejectReactions = []
        }
      })
    }

    function reject(reason) {
      setTimeout(() => {
        if (promise.status === PENDING) {
          promise.value = reason
          promise.status = REJECTED
          promise.rejectReactions.forEach(reaction => triggerPromiseReactions(promise, reaction.promiseCapability, reaction.rejectCallback))
          promise.fulfillReactions = []
          promise.rejectReactions = []
        } 
      })
    }

    return { resolve, reject }
}

module.exports = class MPromise {
  constructor(excutor) {
    this.value = undefined
    this.status = PENDING
    this.fulfillReactions = []
    this.rejectReactions = []

    const promise = this

    const { resolve, reject } = createResolvingFunction(promise)

    excutor.call(undefined, resolve, reject)

  }

  then(fulfillFn, rejectFn) {
    const promise = this
    const promiseCapability = {
      promise: undefined,
      resolve: undefined,
      reject: undefined,
    }
    const nextPromise = new Promise(function(res, rej) {
      promiseCapability.resolve = res
      promiseCapability.reject = rej      
    })
    const reaction = {
      callback: fulfillFn,
      rejectCallback: rejectFn,
      promiseCapability,
    }

    promiseCapability.promise = nextPromise

    if (promise.status === PENDING) {
      promise.fulfillReactions.push(reaction)
    } else if (promise.status === FULFILLED) {
      triggerPromiseReactions(promise, promiseCapability, fulfillFn)
    } else {
      triggerPromiseReactions(promise, promiseCapability, rejectFn)
    }

    return nextPromise
  }
}