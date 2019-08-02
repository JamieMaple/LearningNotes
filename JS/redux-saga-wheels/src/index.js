const { createStore, applyMiddleware } = require('redux')

const reducer = (state = { data: 0 }, action) => {
  switch (action.type) {
    case 'test':
      return { data: state.data + 1 }
    default:
      return state
  }
}
const enhancer = applyMiddleware(store => next => action => {
  console.log('mid1 begin action: ', action.type)
  next(action)
  console.log('mid1 end action: ', action.type)
}, store => next => action => {
  console.log('mid2 begin action payload: ', action.payload)
  next(action)
  console.log('mid2 end action payload: ', action.payload)
})

console.log('====Demo-1====')
const store = createStore(reducer, enhancer)
console.log(store.getState())
store.dispatch({ type: 'test' })
console.log(store.getState())










