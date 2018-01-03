const setImageParticles = (canvas, imageSrc) => ({
  imgH,
  imgW,
  posX = 0,
  posY = 0,
  speed = 0.01,
  rect = 5,
  delay
  // duration = 20
}) => {
  const ctx = canvas.getContext('2d')
  // const durationTime = duration
  let speedTmpl = speed

  ctx.clearRect(0, 0, canvas.width, canvas.height)

  const image = new Image()
  image.width = imgW
  image.height = imgH

  function randomPos(length) {
    return Math.round(length * Math.random())
  }

  class Dot {
    constructor(x, y, img) {
      const startX = randomPos(document.body.clientWidth)
      const startY = randomPos(document.body.clientHeight)

      this.x = x
      this.y = y
      this.img = img
      this.startX = startX
      this.startY = startY
      this.dx = startX
      this.dy = startY
      this.dz = 0
    }

    getSteps (a, b) {
      return (a - b) * speedTmpl
    }

    update() {
      this.dx = this.dx + this.getSteps(this.x, this.dx)
      this.dy = this.dy + this.getSteps(this.y, this.dy)
      this.dz = 0
    }

    paint() {
      ctx.save()
      ctx.putImageData(this.img, canvas.width / 2 + (this.dx - canvas.width / 2), canvas.height / 2 + (this.dy - canvas.height / 2))
      ctx.restore()
    }
  }

  function cal() {
    ctx.drawImage(image, posX, posY, image.width, image.height)
    const imageData = ctx.getImageData(posX, posY, image.width, image.height)
    ctx.clearRect(0, 0, canvas.width, canvas.height)
    const arr = []
    const rows = imageData.height
    const cols = imageData.width

    for (let i = 0; i < cols; i += rect) {
      for (let j = 0; j < rows; j += rect) {
        /* eslint-disable */
        const posR = (j * cols + i) * 4
        const x = posX + image.x + i
        const y = posY + image.y + j
        arr.push(
          new Dot(
            x,
            y,
            ctx.getImageData(x, y, rect, rect)
          )
        )
      }
    }
    
    return arr
  }

  function draw(arr) {
    if (Array.isArray(arr)) {
      window.requestAnimationFrame(function animate() {
        let count = 0
        ctx.clearRect(0, 0, canvas.width, canvas.height)
        arr.forEach(item => {
          if (Math.abs(item.x - item.dx) < 0.1 && Math.abs(item.y - item.dy) < 0.1) {
            count += 1
          } else {
            item.update()
          }
          item.paint()
        })
        if (count < arr.length) {
          window.requestAnimationFrame(animate)
        }
      })
    }
  }

  image.src = imageSrc

  image.onload = function() {
    const arr = cal()
    console.log(arr)
    // if (typeof delay === 'number' && delay >= 0) {
    //   setTimeout(draw.bind(null, arr), delay)
    // } else {
    //   draw(arr)
    // }
    arr.forEach(item => {
      item.paint()
    })
    // console.log(arr)
  }
}

export default setImageParticles