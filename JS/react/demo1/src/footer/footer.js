import React from 'react'
import './footer.css'

function ItemLeftPart(props) {
  return (
    <span className="left">{props.length} items left</span>
  )
}

class Filters extends React.Component {
  constructor(props) {
    super(props)
  }
  render() {
    return (
      <ul className="filters">
        <li className="filters-item selected"><a>All</a></li>
        <li className="filters-item"><a>Active</a></li>
        <li className="filters-item"><a>Completed</a></li>
      </ul>
    )
  }
}

class Footer extends React.Component {
  render() {
    return (
      <div className="footer">
        <ItemLeftPart length={this.props.length} />
        <Filters />
      </div>
    )
  }
}

export default Footer
