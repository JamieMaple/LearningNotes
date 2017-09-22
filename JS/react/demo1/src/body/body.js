import React from 'react'
import './body.css'
import Footer from '../footer/footer'
import { TodoBodyHeader, TodoBodyRows } from '../rows/rows'

const todos = [
  {
    content: "content",
    isCompleted: false
  },
  {
    content: "content",
    isCompleted: true
  }
]

class Body extends React.Component {
  constructor(props) {
    super(props)
    this.state = {todos: todos, option: '', allCompleted: false}

    this.enterInput = this.enterInput.bind(this)
    this.toggleComplete = this.toggleComplete.bind(this)
    this.toggleAllComplete = this.toggleAllComplete.bind(this)
  }
  enterInput(input) {
    const todos = this.state.todos
    const todo = {
      content: input.value,
      isCompleted: false
    }
    todos.push(todo)
    input.value = ''

    this.setState({todos: todos})
  }
  toggleComplete(elem) {
    let boxs = Array.from(document.getElementsByClassName('checkbox-hook'))
    const no = boxs.indexOf(elem)
    const todos = this.state.todos
    todos[no].isCompleted = !todos[no].isCompleted

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
  _todosLeft(){
    let length = 0
    this.state.todos.forEach((item) => {
      if (item.isCompleted === false) {
        length++
      }
    })
    return length
  }
  render() {
    return (
      <div className="todo-body">
        <TodoBodyHeader
          allCompleted={this.state.allCompleted}
          toggleAllComplete={this.toggleAllComplete}
          enterInput={this.enterInput} />
        <TodoBodyRows
          todos={todos}
          toggleComplete={this.toggleComplete}
         />
        <Footer length={this._todosLeft()} />
      </div>
    )
  }
}

export default Body
