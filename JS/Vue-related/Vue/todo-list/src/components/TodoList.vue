<template>
  <div>
    <input 
      placeholder="add new"
      v-model="newItem"
      @keydown.enter="addItem"
    />
    <ol v-if="items.length">
      <todo-list-item
      v-for="item in items"
      :key="item.id"
      :id="item.id"
      :isCompleted="item.isCompleted"
      :text="item.text"
      @remove="removeItem"
      @toggle="toggleItem"
    />
    </ol>
    <p v-else>
      no more todos!
    </p>
    <button
      @click="completeAll"
    >completed all</button>
    <button
      @click="cleanCompleted"
    >clean completed</button>
  </div>
</template>

<script>
import TodoListItem from './TodoListItem'

let itemId = 0

export default {
  name: 'todolist',
  data() {
    return {
      allCompleted: false,
      newItem: '',
      items: []
    }
  },
  methods: {
    addItem() {
      const text = this.newItem.trim()
      if (text !== '') {
        this.items.push({
          text: text,
          id: itemId++,
          isCompleted: false
        })
        this.newItem = ''
      }
    },
    removeItem(id) {
      this.items = this.items.filter(item => item.id !== id)
    },
    toggleItem(id) {
      this.items.forEach(item => {
        if (item.id === id) {
          item.isCompleted = !item.isCompleted
        }
      })
    },
    cleanCompleted() {
      this.items = this.items.filter(item => item.isCompleted === false)
    },
    completeAll() {
      if (this.allCompleted) {
        this.items = this.items.map(item => ({
          ...item,
          isCompleted: false
        }))
      } else {
        this.items = this.items.map(item => ({
          ...item,
          isCompleted: true
        }))
      }
      this.allCompleted = !this.allCompleted
    }
  },
  components: {
    TodoListItem
  }
}
</script>

<style lang="stylus" scoped>
  ol
    width 33%
    margin auto
</style>