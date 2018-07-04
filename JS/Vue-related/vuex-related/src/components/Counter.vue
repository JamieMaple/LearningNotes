<template>
  <div>
    <h3>Counter</h3>
    <p>{{ count }}</p>
    <button @click="increment">+</button>
    <button @click="decrement">-</button>
  </div>
</template>

<script>
import { mapState, mapMutations } from 'vuex'

export default {
  name: 'Counter',
  methods: mapMutations([
    'increment',
    'decrement',
  ]),
  computed: mapState({
    count: state => state.count,
  })
}
</script>
