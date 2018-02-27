// some helper

function isFunction(func) {
  return typeof func === 'function'
}

/*
 * Any Promise object is in one of three mutually exclusive states
 * fulfilled, rejected, and pending
*/
var PENDING = 'pending'
var FULFILLED = 'fulfilled'
var REJECTED = 'rejected'


