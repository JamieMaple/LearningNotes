const reduxSaga = require('redux-saga')
const { createStore, applyMiddleware } = require('redux')
const { call, take } = require('redux-saga/effects')
const reducer = require('./reducer')

console.log('====Demo-2-saga====')

function fetchMockData(time = 1000) {
  return new Promise(res => {
    setTimeout(function() {
      res({ data: ['this', 'is', 'test', 'data'] })
    }, time)
  })
}

function *saga() {
  yield take('data')
  const data = yield call(fetchMockData)
  console.log(data)
}

const createSagaMiddleware = reduxSaga['default']
const sagaMiddleware = createSagaMiddleware()
const store2 = createStore(reducer, applyMiddleware(sagaMiddleware))

sagaMiddleware.run(saga)

store2.dispatch({ type: 'test' })
store2.dispatch({ type: 'data' })
