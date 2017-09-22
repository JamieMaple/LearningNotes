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
    if (this.props.length > 0) {
      return (
        <span
          className={"toggle-all"+(this.props.allCompleted?" all-completed":"")}
          onClick={this.toggleAllComplete}
        ></span>
      )
    }
    return null
  }
}

class TodoBodyRowsLeftBox extends React.Component {
  constructor(props) {
    super(props)

    this.toggleComplete = this.toggleComplete.bind(this)
  }
  toggleComplete(e) {
    this.props.toggleComplete(e.target, this.props.index)
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
class TodoBodyRowsMiddleText extends React.Component {
  render() {
    const todo = this.props.todo
    return (
      <a
        className={ todo.isCompleted?"todo-completed" : ""}
      >
        {todo.content}
      </a>
    )
  }
}
class TodoBodyRowsRightDel extends React.Component {
  constructor(props) {
    super(props)

    this.deleteTodo = this.deleteTodo.bind(this)
  }
  deleteTodo(e) {
    this.props.deleteTodo(this.props.index)
  }
  render() {
    return (
      <span
        className="todo-delete todo-hook"
        onClick={this.deleteTodo}
      >
      X
      </span>
    )
  }
}

class TodoBodyRowsEach extends React.Component {
  render() {
    const todo = this.props.todo
    const index= this.props.index

    return (
      <li
        className="todo-row todo-item "
      >
        <TodoBodyRowsLeftBox
          index = {index}
          isCompleted={todo.isCompleted}
          toggleComplete={this.props.toggleComplete}
        />
        <TodoBodyRowsMiddleText
          todo={todo}
        />
        <TodoBodyRowsRightDel
          deleteTodo={this.props.deleteTodo}
          index = {index}
        />
      </li>
    )
  }
}

class TodoBodyHeader extends React.Component{
  render() {
    return (
      <div className="todo-header">
        <TodoBodyHeaderLeftBox
          length={this.props.length}
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
  render() {
    const chosen = this.props.chosen
    const All = this.props.options[0]
    const Active = this.props.options[1]
    const filterCondition = this.props.chosen === Active ? false : true
    const todos = []
    this.props.todos.forEach((todo, index) => {
      if (
        chosen === All ||
        todo.isCompleted === filterCondition) {
        todos.push(
          <TodoBodyRowsEach
            key={"content "+index.toString()}
            index = {index}
            todo = {todo}
            toggleComplete={this.props.toggleComplete}
            deleteTodo={this.props.deleteTodo}
          />
        )
      }
    })
    return (
      <ul className="todos-container">
        {todos}
      </ul>
    )
  }
}

export {TodoBodyHeader, TodoBodyRows}
