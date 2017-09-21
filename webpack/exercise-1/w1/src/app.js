import {sayName} from './test'

console.log(sayName())

;(() => {
  let a = ' !'
  const b = 'Hello World'
  console.log(b+a)
})()
