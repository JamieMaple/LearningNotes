const reducer = (state = { data: 0 }, action) => {
  switch (action.type) {
    case 'test':
      return { data: state.data + 1 }
    default:
      return state
  }
}

module.exports = reducer
exports['default'] = reducer