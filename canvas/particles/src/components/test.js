/* eslint-disable */
import Tween from './tween'
const canvas = document.getElementsByTagName('canvas')[0]
canvas.height = 1000
canvas.width = 1000
const ctx = canvas.getContext('2d')
ctx.clearRect(0, 0, canvas.width, canvas.height)

class Dot {
  constructor (x, y, rect) {
    this.x = x
    this.y = y
    // test
    this.dx = 200
    this.dy = 200
    this.startX = this.dx
    this.startY = this.dy
    this.rect = rect
  }

  update(dx, dy) {
    this.dx = dx
    this.dy = dy
  }

  paint() {
    ctx.fillRect(this.dx, this.dy, this.rect, this.rect)
  }
}

const testDot = new Dot(140, 800, 100)

testDot.paint()

const testImg = ctx.getImageData(250, 200, 10, 10)


ctx.putImageData(testImg, 200, 100)

// const duration = 50
// let count = 0

// const changeFunc = Tween.Elastic.easeOut

// window.requestAnimationFrame(function animation() {
//   const dx = changeFunc(count, testDot.startX, testDot.x - testDot.startX, duration)
//   const dy = changeFunc(count, testDot.startY, testDot.y - testDot.startY, duration)
//   testDot.update(dx, dy)
//   ctx.clearRect(0, 0, canvas.width, canvas.height)
//   testDot.paint()
//   count += 1
//   if (count < duration) {
//     window.requestAnimationFrame(animation)
//   }
// })
