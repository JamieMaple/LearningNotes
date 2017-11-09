import foo from './other'

const world = () => {
  console.log(132323)
}

world()

foo()

// for hot reload
if (module.hot) {
  module.hot.accept()
}
// @plugin
