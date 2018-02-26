const { ifFunc } = require('./utils/utils')
/*
 *  promise constructor
*/

const PENDING  = 'pending'
const RESOLVED = 'resolved'
const REJECTED  = 'rejected'

function TPromise(fn) {
  if (typeof fn !== 'function') {
    throw TypeError('Promise resolver ' + fn + ' is not a function')
  }
}

TPromise.prototype.then = function() {

}

TPromise.prototype.catch = function() {

}

