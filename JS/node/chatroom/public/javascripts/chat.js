var Chat = function(socket) {
  this.socket = socket
}
// send message method
Chat.prototype.sendMessage = function(room, text) {
  var message = {
    room: room,
    text: text
  }
  this.socket.emit('message', message)
}
// change room method
Chat.prototype.changeRoom = function(room) {
  this.socket.emit('join', {
    newRoom: room
  })
}
// process command
Chat.prototype.processCommand = function(command) {
  var words = command.split(' ')
  var message = false
  
  command = words[0].substring(1, words[0].length).toLowerCase()

  switch (command) {
    case 'join':
      words.shift()
      var room = words.join(' ')
      this.changeRoom(room)
      break
    case 'nick':
      words.shift()
      var name = words.join(' ')
      this.socket.emit('nameAttempt', name)
      break
    default:
      message = 'Unrecognized command.'
      break
  }

  return message
}
