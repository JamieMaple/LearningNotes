import React, { render } from './react'

const title = <h1>Hello World</h1>

function Welcome({ name }) {
  return <h1>Hello, { name }</h1>
}

class Counter extends React.Component {
  constructor(props) {
    super(props)
    this.state = { count: 0 }
  }

  render() {
    return (
      <div>
        <h3>Counter: {this.state.count}</h3>
        <button onClick={ () => { this.setState({ count: this.state.count + 1 }) } }>Add</button>
      </div>
    )
  }
}

class App extends React.Component {
  render() {
    return (
      <div>
        <Welcome name={this.props.name} />
        <Counter />
      </div>
    )
  }
}

render(<App name="Maple" />, document.querySelector('#root'))


