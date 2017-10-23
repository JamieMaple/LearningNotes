import React, { Component } from 'react'
import Header from './header/header'
import Body from './body/body'

import './app.css'

class App extends Component {
  render() {
    return (
      <div className="wrapper">
        <Header title={"todos"} />
        <Body />
      </div>
    )
  }
}

export default App
