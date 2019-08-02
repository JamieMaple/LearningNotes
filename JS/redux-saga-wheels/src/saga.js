const reduxSaga = require('redux-saga')
const { createStore, applyMiddleware } = require('redux')
const { call, take, fork } = require('redux-saga/effects')
const reducer = require('./reducer')

console.log('====Demo-2-saga====')

function fetchMockData(time = 1000) {
  return new Promise(res => {
    setTimeout(function() {
      res({ data: ['this', 'is', 'test', 'data'] })
    }, time)
  })
}

function *sagaWithData() {
  yield take('data')
  const data = yield call(fetchMockData)
  console.log(data)
}
function *saga() {
  yield take('test')
  console.log('in test saga')
}

function *sagaWithFork() {
  yield fork(sagaWithData)
  yield fork(saga)
}

const createSagaMiddleware = reduxSaga['default']
const sagaMiddleware = createSagaMiddleware()
const store2 = createStore(reducer, applyMiddleware(sagaMiddleware))

// sagaMiddleware.run(saga)
sagaMiddleware.run(sagaWithFork)

store2.dispatch({ type: 'test' })
store2.dispatch({ type: 'data' })
