/*
 * check if func
 * param {any} fn
 * return {boolean}
*/
function ifFunc(fn) {
  return typeof fn === 'function'
}

module.exports = {
  ifFunc
}
