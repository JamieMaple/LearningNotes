import React from 'react'
import './body.css'
import Footer from '../footer/footer'
import { TodoBodyHeader, TodoBodyRows } from '../rows/rows'

class Body extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      todos: this._init_todos(),
      chosen: 'All',
      options: ['All', 'Active', 'Completed']
    }

    this._save_storage()
    this.enterInput = this.enterInput.bind(this)
    this.toggleComplete = this.toggleComplete.bind(this)
    this.toggleAllComplete = this.toggleAllComplete.bind(this)
    this.deleteTodo = this.deleteTodo.bind(this)
    this.chosenChange = this.chosenChange.bind(this)
  }
  _init_todos() {
    if (!localStorage.todos) {
      return []
    } else {
      return JSON.parse(localStorage.todos)
    }
  }
  _save_storage() {
    localStorage.todos = JSON.stringify(this.state.todos);
  }
  enterInput(input) {
    if (input.value === '') {
      return
    }
    const todos = this.state.todos
    const todo = {
      content: input.value,
      isCompleted: false
    }
    todos.push(todo)
    input.value = ''

    this.setState({todos: todos})
  }
  toggleComplete(elem, index) {
    const todos = this.state.todos
    todos[index].isCompleted = !todos[index].isCompleted

    this.setState({
      todos: this.state.todos
    })
  }
  toggleAllComplete(e) {
    const todos = this.state.todos
    const allCompleted = !this.state.allCompleted

    for (let todo of todos) {
      todo.isCompleted = allCompleted
    }
    this.setState({todos: todos, allCompleted: allCompleted})
  }
  deleteTodo(index) {
    const todos = this.state.todos

    todos.splice(index, 1)

    this.setState({todos: todos})
  }
  chosenChange(e) {
    const chosen = e.target.innerHTML
    this.setState({
      chosen: chosen
    })
  }
  _todosLeft(){
    let length = 0
    this.state.todos.forEach((item) => {
      if (item.isCompleted === false) {
        length++
      }
    })
    return length
  }
  _allCompleted() {
    for (let todo of this.state.todos) {
      if (!todo.isCompleted) {
        return false
      }
    }
    return true
  }
  render() {
    this._save_storage()
    return (
      <div className="todo-body">
        <TodoBodyHeader
          allCompleted={this._allCompleted()}
          length={this.state.todos.length}
          toggleAllComplete={this.toggleAllComplete}
          enterInput={this.enterInput}
        />
        <TodoBodyRows
          {...this.state}
          toggleComplete={this.toggleComplete}
          deleteTodo={this.deleteTodo}
         />
        <Footer
          length={this._todosLeft()}
          chosen={this.state.chosen}
          options={this.state.options}
          chosenChange={this.chosenChange}
        />
      </div>
    )
  }
}

export default Body
