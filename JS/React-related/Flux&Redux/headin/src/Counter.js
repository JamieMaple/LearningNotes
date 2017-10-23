import React, {Component} from 'react'
import PropTypes from 'prop-types'

const buttonStyle = {
  margin: '10px'
}

class Counter extends Component {
  constructor(props) {
    super(props)

    this.onClickIncrementButton = this.onClickIncrementButton.bind(this)
    this.onClickDecrementButton = this.onClickDecrementButton.bind(this)

    // default state
    this.state = {
      count: props.initValue
    }
  }
  onClickIncrementButton() {
    this.updateCount(true)
  }
  onClickDecrementButton() {
    this.updateCount(false)
  }

  updateCount(isIncrement) {
    const previousValue = this.state.count
    const newValue = isIncrement ? previousValue + 1 : previousValue - 1

    this.setState({count: newValue})
    this.props.onUpdate(newValue, previousValue)
  }
  render() {
    const {caption} = this.props
    return (
      <div>
        <button style={buttonStyle} type="button" onClick={this.onClickIncrementButton}>+</button>
        <button style={buttonStyle} type="button" onClick={this.onClickDecrementButton}>-</button>
        <span>{caption} count: {this.state.count}</span>
      </div>
    )
  }
}
// props check
Counter.propTypes = {
  caption: PropTypes.string.isRequired,
  initValue: PropTypes.number,
  onUpdate: PropTypes.func
}
// default props
Counter.defaultProps = {
  initValue: 0,
  onUpdate: f => f
}

export default Counter
