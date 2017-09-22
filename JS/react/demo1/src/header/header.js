import React from 'react'
import './header.css'

function Title(props) {
  return <h1 className="title">{props.title}</h1>
}
class Header extends React.Component {
  render() {
    return (
      <div className="header">
        <Title title={this.props.title} />
      </div>
    )
  }
}

export default Header
