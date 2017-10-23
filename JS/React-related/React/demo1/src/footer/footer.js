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

    this.optionChange = this.optionChange.bind(this)
  }
  optionChange(e) {
    this.props.chosenChange(e)
  }
  render() {
    const options = this.props.options.map(option => {
      let optionElem
      if (option === this.props.chosen) {
        optionElem = (
          <a
            className="selected"
            onClick={this.optionChange}
          >
            {option}
          </a>
        )
      } else {
        optionElem = (
          <a
            onClick={this.optionChange}
            value={option}
          >
            {option}
          </a>
        )
      }
      return (
        <li
          key={option}
          className="filters-item"
        >
          {optionElem}
        </li>
      )
    })
    return (
      <ul className="filters">
        {options}
      </ul>
    )
  }
}

class Footer extends React.Component {
  render() {
    return (
      <div className="footer">
        <ItemLeftPart length={this.props.length} />
        <Filters
          options={this.props.options}
          chosen={this.props.chosen}
          chosenChange={this.props.chosenChange}
        />
      </div>
    )
  }
}

export default Footer
