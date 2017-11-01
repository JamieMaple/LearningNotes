import Vue from 'vue'
import Router from 'vue-router'

import Index from 'views/Index'
import Group from 'views/Group'
import Contact from 'views/Contact'

Vue.use(Router)

const routes = [
  {
    path: '/',
    name: 'Index',
    component: Index
  },
  {
    path: '/group',
    component: Group
  },
  {
    path: '/contact',
    component: Contact
  }
]

export default new Router({
  routes
})
