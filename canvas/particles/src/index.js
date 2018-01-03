/* eslint-disable */
import './style.scss'
import setParticles from './components/pixels'
import setImageParticles from './components/img'
import imgSrc from './asserts/bingyan.png'

// import './components/test'

let clientHeight = document.documentElement.clientHeight
let clientWidth = document.documentElement.clientWidth

const canvas = document.getElementById('mycanvas')
canvas.height = clientHeight
canvas.width = clientWidth

// setParticles(canvas, imgSrc)({
//   posX: 0.1479 * clientWidth,
//   posY: 0.295 * clientHeight,
//   imgW: 0.3645 * clientWidth,
//   imgH: 0.118 * clientHeight,
//   rect: 4,
//   delay: 1000,
//   duration: 80,
//   changeFuncName: 'Back',
//   mode: 'ease-in'
// })

setImageParticles(canvas, imgSrc)({
  posX: 0.1479 * clientWidth,
  posY: 0.295 * clientHeight,
  imgW: 0.3645 * clientWidth,
  imgH: 0.118 * clientHeight,
  rect: 10,
  speed: 0.07,
  delay: 500
})

if (module.hot) {
  module.hot.accept()
}
