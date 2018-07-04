<template>
  <div>
    <h1>Demos with Vuex</h1>
    <div>
      <h3>Todo list</h3>
      <ul>
        <li></li>
      </ul>
    </div>
    <counter />
  </div>
</template>

<script>
import Counter from './Counter'

export default {
  name: 'TodoApp',
  data () {
    return {}
  },
  components: {
    Counter,
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h1, h2 {
  font-weight: normal;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
