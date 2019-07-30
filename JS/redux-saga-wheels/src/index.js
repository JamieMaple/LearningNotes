const { createStore } = require('redux')

const reducer = (state = { data: 0 }, action) => {
  switch (action.type) {
    case 'test':
      return { data: state.data + 1 }
    default:
      return state
  }
}

console.log('====Demo-1====')
const store = createStore(reducer)
console.log(store.getState())
store.dispatch({ type: 'test' })
console.log(store.getState())










