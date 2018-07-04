import Vue from 'vue'
import Vuex from 'vuex'
import * as types from './mutation-types'

Vue.use(Vuex)

const store = new Vuex.Store({
  state: {
    count: 0,
    todos: [
      { id: 1, text: 'first commit', done: true },
      { id: 2, text: 'second commit', done: false },
    ]
  },
  mutations: {
    [types.INCREMENT] (state) {
      state.count += 1
    },
    [types.DECREMENT] (state) {
      state.count -= 1
    }
  },
  getters: {
    doneTodos: state => state.todos.filter(todo => todo.done),
  }
})

export default store
