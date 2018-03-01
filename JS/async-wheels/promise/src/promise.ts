// <reference path="type.ts" />
namespace promise {
  export class TPromise implements IPromise {
    public state: state
    public value: any
    fulfillReactions: Array<PromiseReaction>
    rejctReactions: Array<PromiseReaction>
    promiseIsHandlerd: boolean
    constructor(executor: Function) {
      if (!new.target) {
        throw new TypeError()
      }
      if (!isCallable(executor)) {
        throw new TypeError()
      }
      let promise = this
      promise.state = state.PENDING
      promise.fulfillReactions = []
      promise.rejctReactions = []
      promise.promiseIsHandlerd = false
      let resolvingFunctions = createResolvingFunctions(promise)

      try {
        executor.call(undefined, resolvingFunctions.resolve, resolvingFunctions.reject)
      } catch (reason) {
        resolvingFunctions.reject.call(undefined, reason)
      }
    }
    public then(onFulfilled: Function, onRejected: Function): IPromise {
      let promise = this
      if (!isPromise(promise)) {
        throw new TypeError()
      }
      let speciesConstructor: Function = TPromise
      let resultCapability = newPromiseCapability(speciesConstructor)
      return performPromiseThen(promise, onFulfilled, onRejected, resultCapability)
    }
    public catch(onRejected: Function): IPromise {
      return this.then(undefined, onRejected)
    }
  }
  /*
   * some Promise Abstract Operations
   */

  /*
   * CreateResolvingFunctions
   * param {promise} promise
   * return {TRecord}
   */
  function createResolvingFunctions(promise: TPromise): {resolve: Function, reject: Function} {
    let alreadyResolved: {value: boolean} = {value: false}

    /* Build-in
     * Promise Reject Functions
     */
    let reject: any = function(reason: any) {
      if (!isObject(reject.promise)) {
        throw new TypeError()
      }

      reject.promise = promise
      reject.alreadyResolved = alreadyResolved

      if (alreadyResolved.value) {
        return undefined
      }

      alreadyResolved.value = true

      return rejectPromise(promise, reason)
    }
    reject.promise = promise
    reject.alreadyResolved = alreadyResolved

    /* Build-in
     * Promise Resolve Functions
     */
    let resolve: any = function(resolution: any) {
      if (!isObject(reject.promise)) {
        throw new TypeError()
      }

      resolve.promise = promise
      resolve.alreadyResolved = alreadyResolved

      if (alreadyResolved.value) {
        return
      }
      
      alreadyResolved.value = true

      if (sameValue(resolution, promise)) {
        let selfResolutionError = new TypeError('self resolution error')
        return rejectPromise(promise, selfResolutionError)
      }

      if (!isObject(resolution)) {
        return fulfillPromise(promise, resolution)
      }

      let then = getObjectProp(resolution, 'then')

      if (isCompletionRecord(then)) {
        return rejectPromise(promise, then.value)
      }

      let thenAction = then
      if (isCallable(thenAction)) {
        return fulfillPromise(promise, resolution)
      }

      enqueueJob("PromiseJobs", promiseResolveThanableJob, [promise, resolution, thenAction])
    }
    resolve.promise = promise
    resolve.alreadyResolved = alreadyResolved
    // no why
    resolve.length = 1

    return {
      resolve,
      reject,
    }
  }

  /*
   * NewPromiseCapability
   */
  function newPromiseCapability(C: any): PromiseCability {
    if (!isConstructor(C)) {
      throw TypeError()
    }

    let promiseCapability: PromiseCability = {
      promise: undefined,
      resolve: undefined,
      reject: undefined,
    }

    let executor: any = function() {
      if (executor.capability) {
        // TODO
      }
      let promiseCapability = executor.capability
      if (!promiseCapability.resolve || !promiseCapability.reject) {
        throw new TypeError()
      }
    }
    promiseCapability = executor.capability
    let promise = new C(executor)
    promiseCapability.promise = promise

    return promiseCapability
  }
  /*
   * GetCapabilitiesExecutor Functions
   */

  function rejectPromise(promise: TPromise, reason: any) {
    if (promise.state === state.PENDING) {
      let reactions = promise.rejctReactions
      promise.value = reason
      promise.fulfillReactions = promise.rejctReactions = undefined
      promise.state = state.REJECTED
      return triggerPromiseReactions(reactions, reason)
    }
  }

  function fulfillPromise(promise: TPromise, value: any) {
    if (promise.state === state.PENDING) {
      let reactions: Array<PromiseReaction> = promise.fulfillReactions
      promise.value = value
      promise.fulfillReactions = promise.rejctReactions = undefined
      promise.state = state.FULFILLED
      return triggerPromiseReactions(reactions, value)
    }
  }

  function triggerPromiseReactions(reactions: Array<PromiseReaction>, ...argument: List) {
    reactions.forEach(reaction => enqueueJob('promiseJobs', promiseReactionJob, [reaction, argument]))    
  }

  function isPromise(x: any): boolean {
    if (!isObject(x)) {
      return false
    }

    if (x.state) {
      return true
    } else {
      return false
    }
  }

  // promise job
  function promiseReactionJob(reaction: PromiseReaction, ...argument: List) {
    let promiseCapability = reaction.capability
    let type = reaction.type
    let handler = reaction.handler
    let handlerResult: completionRecord
    let status

    if (handler == undefined) {
      if (type === state.FULFILLED) {
        handlerResult = normalCompletion(argument)
      } else if (type === state.REJECTED) {
        handlerResult = {
          type: 'throw',
          value: argument,
          target: null,
        }
      }
    } else {
      reaction.handler.call(undefined, ...argument)
    }
    try {
      promiseCapability.resolve.call(undefined, handlerResult.value)
    } catch (reason) {
      promiseCapability.reject.call(undefined, handlerResult.value)
    }
  }

  function promiseResolveThanableJob(promiseToResolve: TPromise, thenable: any, then: Function) {
    let resolvingFunctions = createResolvingFunctions(promiseToResolve)
    try {
      then.call(thenable, [resolvingFunctions.resolve, resolvingFunctions.reject])
    } catch (reason) {
      resolvingFunctions.reject.call(undefined, [reason])
    }
  }
  // promise
  function performPromiseThen(promise: TPromise, onFulfilled: Function, onRejected: Function, resultCapability): TPromise {
    // TODO
    return new TPromise(() => {})
  }
}
/*
  * IsPromise
  */
/*
  * GetCapabilitiesExecutor Functions
  */
/*
  * promiseReactionJob
  */
/* 
 * Promise constructor
 */

