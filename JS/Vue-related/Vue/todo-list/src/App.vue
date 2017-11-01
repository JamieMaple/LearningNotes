<template>
  <div id="app">
    <img src="./assets/logo.png" />
    <hello-world />
    <todo-list />
    <router-link :to="{name: 'Index'}">Index</router-link>
    <router-link to="/group">Group</router-link>
    <router-link to="/contact">Contact</router-link>
    <router-view></router-view>
  </div>
</template>

<script>
import HelloWorld from 'components/HelloWorld'
import TodoList from 'components/TodoList'

export default {
  name: 'app',
  components: {
    HelloWorld,
    TodoList
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
