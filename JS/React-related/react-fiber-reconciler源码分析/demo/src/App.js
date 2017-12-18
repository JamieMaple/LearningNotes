import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

function Hello(props) {
  return (
    [
    <h1 key='1'>
      Hello World
    </h1>,
    <div key='2'>world</div>,
    'hello world',
    'hello world'
    ]
  )
}

class App extends Component {
  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h1 className="App-title">Welcome to React</h1>
        </header>
        <p className="App-intro">
          To get started, edit <code>src/App.js</code> and save to reload.
        </p>
        <Hello key="key" num={1} test={"test"} />
      </div>
    );
  }
}

export default App;
