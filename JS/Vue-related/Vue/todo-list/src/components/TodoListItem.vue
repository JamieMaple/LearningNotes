<template>
  <li>
    <input 
      type="checkbox" 
      :checked="isCompleted"
      @click="toggleComplete"
    />
    <span :class="{completed: isCompleted}">
      {{ text }}
    </span>
    <button @click="removeSelf">X</button>
  </li>
</template>

<script>
export default {
  name: 'todoitem',
  props: {
    id: Number,
    text: String,
    isCompleted: Boolean
  },
  methods: {
    removeSelf() {
      this.$emit('remove', this.id)
    },
    toggleComplete() {
      this.$emit('toggle', this.id)
    }
  }
}
</script>

<style lang="stylus" scoped>
  li
    text-align left
    span
      padding 5px
    .completed
      text-decoration line-through
</style>