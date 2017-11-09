import _ from 'lodash'
import printMe from './print'
import './style.css'

function component() {
  var element = document.createElement('div')
  var button = document.createElement('button')

  // button
  button.innerHTML = "click me and console"
  button.onclick = printMe

  // lodash
  element.innerHTML = _.join(['Hello', 'webpack'], ' ')
  element.classList.add('hello')

  element.appendChild(button)

  return element
}

document.body.appendChild(component())


if(module.hot) {
  module.hot.accept('./print', function() {
    console.log('Accepting the updated printMe module!')
  })
  printMe()
}
