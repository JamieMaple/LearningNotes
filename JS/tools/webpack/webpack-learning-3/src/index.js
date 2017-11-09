import _ from 'lodash'
// import print from './print'

function component() {
  var element = document.createElement('div')

  element.innerHTML = _.join(['Hello', 'webpack'], ' ')
  // element.onclick = print.bind(null, "Hello webpack!")

  return element
}

document.body.appendChild(component())
