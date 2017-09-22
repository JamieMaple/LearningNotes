import React from 'react'
import './rows.css'

class TodoBodyHeaderInput extends React.Component {
  constructor(props) {
    super(props)

    this.enterInput = this.enterInput.bind(this)
  }
  enterInput(e) {
    e.preventDefault()

    let input = e.target.getElementsByTagName('input')[0]

    this.props.enterInput(input)

  }
  render() {
    return (
      <form onSubmit={this.enterInput}>
        <input
          placeholder="What needs to be done?"
          className="todo-row todo-input"
          type="text"
        />
      </form>
    )
  }
}
class TodoBodyHeaderLeftBox extends React.Component {
  constructor(props) {
    super(props)

    this.toggleAllComplete = this.toggleAllComplete.bind(this)
  }
  toggleAllComplete(e) {
    this.props.toggleAllComplete(e)
  }
  render() {
    return (
      <span
        className={"toggle-all"+(this.props.allCompleted?" all-completed":"")}
        onClick={this.toggleAllComplete}
      ></span>
    )
  }
}
class TodoBodyRowsLeftBox extends React.Component {
  constructor(props) {
    super(props)

    this.toggleComplete = this.toggleComplete.bind(this)
  }
  toggleComplete(e) {
    this.props.toggleComplete(e.target)
  }
  render() {
    return (
      <span className="left-box">
        <input
          className="todo-checkbox checkbox-hook"
          type="checkbox"
          onChange={this.toggleComplete}
          checked={this.props.isCompleted}
        />
      </span>
    )
  }
}

class TodoBodyHeader extends React.Component{
  render() {
    return (
      <div className="todo-header">
        <TodoBodyHeaderLeftBox
          allCompleted={this.props.allCompleted}
          toggleAllComplete={this.props.toggleAllComplete}
        />
        <TodoBodyHeaderInput
          enterInput={this.props.enterInput}
        />
      </div>
    )
  }
}
class TodoBodyRows extends React.Component {
  constructor(props) {
    super(props)
  }
  render() {
    const todos = this.props.todos.map((todo, index) => {
        return (
          <li
            key={todo.content+index.toString()}
            className={
            "todo-row todo-item " + (todo.isCompleted?"todo-completed" : "")
          }>
            <TodoBodyRowsLeftBox
              isCompleted={todo.isCompleted}
              toggleComplete={this.props.toggleComplete}
            />
            {todo.content}
          </li>
        )
    })
    return (
      <ul className="todos-container">
        {todos}
      </ul>
    )
  }
}

export {TodoBodyHeader, TodoBodyRows}
