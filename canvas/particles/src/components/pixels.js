import Tween from './tween'

const setParticles = (canvas, imageSrc) => ({
  imgH,
  imgW,
  posX = 0,
  posY = 0,
  speed = 0.08,
  rect = 5,
  delay,
  duration = 100,
  changeFuncName = 'Expo',
  mode = 'ease-in'
}) => {
  const ctx = canvas.getContext('2d')
  const durationTime = duration
  const MODE = mode

  ctx.clearRect(0, 0, canvas.width, canvas.height)

  const image = new Image()
  image.width = imgW
  image.height = imgH

  function randomPos(length) {
    return Math.round(length * Math.random())
  }

  class Dot {
    constructor(x, y, fillStyle) {
      const startX = randomPos(document.body.clientWidth)
      const startY = randomPos(document.body.clientHeight)

      this.x = x
      this.y = y
      this.dx = startX
      this.dy = startY
      this.startX = this.dx
      this.startY = this.dy
      this.fillStyle = fillStyle
    }

    init() {
      this.paint()
      this.update()
    }

    update(dx, dy) {
      this.dx = dx
      this.dy = dy
    }

    paint() {
      ctx.fillStyle = this.fillStyle
      ctx.fillRect(this.dx, this.dy, rect, rect)
    }
  }

  function cal() {
    ctx.drawImage(image, posX, posY, image.width, image.height)
    const imageData = ctx.getImageData(posX, posY, image.width, image.height)
    const arr = []
    const rows = imageData.height
    const cols = imageData.width

    for (let i = 0; i < cols; i += rect) {
      for (let j = 0; j < rows; j += rect) {
        /* eslint-disable */
        const posR = (j * cols + i) * 4
        if (imageData.data[posR + 3] > 150) {
          arr.push(
            new Dot(
              posX + image.x + i,
              posY + image.y + j,
              `rgba(${imageData.data[posR]}, ${imageData.data[posR + 1]}, ${imageData.data[posR + 2]}, ${imageData.data[posR + 3]})`
            )
          )
        }
      }
    }
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    
    return arr
  }

  function draw(arr) {
    if (Array.isArray(arr)) {
      let changeFunc = Tween.Expo
      if (Tween[changeFuncName]) {
        changeFunc = Tween[changeFuncName]
      }
      if (MODE === 'ease-out') {
        changeFunc = changeFunc.easeOut
      } else if (MODE === 'ease-in-out') {
        changeFunc = changeFunc.easeInOut
      } else {
        changeFunc = changeFunc.easeIn
      }
      let count = 0
      window.requestAnimationFrame(function animate() {
        ctx.clearRect(0, 0, canvas.width, canvas.height)
        arr.forEach(item => {
          const dx = changeFunc(count, item.startX, item.x - item.startX, durationTime)
          const dy = changeFunc(count, item.startY, item.y - item.startY, duration)
          item.update(dx, dy)
          item.paint()
        })
        count += 1
        if (count <= duration) {
          window.requestAnimationFrame(animate)
        }
      })
    }
  }

  function delayTime(callback, delay) {
    const prev = +new Date
    window.requestAnimationFrame(function timer() {
      const now = +new Date
      if (now - prev < delay) {
        window.requestAnimationFrame(timer)
      } else {
        callback()
      }
    })
  }

  image.src = imageSrc

  image.onload = function() {
    const arr = cal()
    if (typeof delay === 'number' && delay >= 0) {
      delayTime(() => {
        arr.forEach((item, index) => item.paint())
        draw(arr)
      }, delayTime)
    } else {
      draw(arr)
    }
  }
}

export default setParticles