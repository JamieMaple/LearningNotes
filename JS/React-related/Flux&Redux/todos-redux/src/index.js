import React from 'react'
import { render } from 'react-dom'
import { Provider } from 'react-redux'
import { createStore, compose } from 'redux'
import todoApp from './reducers'
import App from './components/App'

let store = createStore(todoApp, {}, compose(window.devToolsExtension ? window.devToolsExtension() : f => f))

render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById('root')
)
