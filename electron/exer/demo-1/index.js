const { app, BrowserWindow } = require('electron')
const path = require('path')
const url = require('url')

let win

function createWindow() {
  win = new BrowserWindow({minWidth: 800, minHeight: 600})

  win.loadURL(url.format({
    pathname: path.join(__dirname, 'index.html'),
    protocol: 'file:',
    slashes: true
  }))

  win.webContents.openDevTools()

  win.on('closed', () => {
    win = null
  })
}

app.on('ready', createWindow)

app.on('window-all-closed', () => {
  if (process.platform !== 'drawin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (win === null) {
    createWindow()
    let myNo = new Notification('Title', {
      body: 'Lorem Ipsum Dolor Sit Amet'
    })
  }
})