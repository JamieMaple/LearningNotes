# Vue ReLearning

### Start

1. Declarative Render
   -  `{{}}`
   -  `v-bind`
2. Conditionals and Loop
   -  `v-if`
   -  `v-for` for Array
3. Handling some Event
   -  `v-on`
4. Component
   -  `Vue.component(options)`
   -  多个组件渲染同样得有 `key`，看来这是 `vitual DOM` 区分同一父级元素下的

### Vue Instance

1. Creating instance

   ```javascript
   var vm = new Vue({
     // options
   })
   ```

   usually one root instance

2. Data and Methods

   ```javascript
   var data = {a: 1}
   var vm = new Vue({
       el: '#emp',
     	data: data
   })

   vm.$data === data 
   // => true

   vm.$el === document.getElementById('emp') 
   // => true

   // $watch is an instance method
   vm.$watch('a', function (newValue, oldValue) {
     // This callback will be called when `vm.a` changes
   })
   ```

   ​

3. Instance lifecycle hooks

   such as `created`, `mounted`, `updated`, and `destroyed`

   ![pic Vue-lifecycle-hooks](https://vuejs.org/images/lifecycle.png)


### Template Syntax

1. Interpolations

   -  Text (plain text)

       “Mustache” syntax

      `{{ }}`

      `v-once`

   -  Raw HTML

      `v-html`

   -  Attributes

      >  Mustaches cannot be used inside HTML attributes, instead use a [v-bind directive](https://vuejs.org/v2/api/#v-bind)

   -  JavaScript Expresstions

      ```html
      <!-- good -->
      {{ number + 1 }}
      {{ ok ? 'YES' : 'NO' }}
      {{ message.split('').reverse().join('') }}

      <!-- bad -->
      <!-- this is a statement, not an expression: -->
      {{ var a = 1 }}
      <!-- flow control won't work either, use ternary expressions -->
      {{ if (ok) { return message } }}
      ```

2. Direactives

   `v-` prefix

   `v-on`/ `v-if` / `v-on`

   -  Arguments


   -  Modifiers

3. Shorthands
4. 
   `v-bind:href` => `:herf`

   `v-on:click="something"` =>  `@:click="something"`


### Computed Properties and Watchers

**make easy logic to read, and importantly it is default getter-only**

1. difference between `Computed Properties` and `methods`
2. difference between `Computed Propperties` and `watch`
3. `Computed setter` for `Computed properties`
4. Watchers

>   using the `watch` option allows us to perform an asynchronous operation (accessing an API), limit how often we perform that operation, and set intermediary states until we get a final answer. None of that would be possible with a computed property.

### Class and Style Bindings

>  Meddling with string concatenation is annoying and error-prone. For this reason, Vue provides special enhancements when `v-bind` is used with `class` and `style`. In addition to strings, the expressions can also evaluate to objects or arrays.

1. Binding HTML Classes
   -  Object
   -  Array
   -  with components
2. Binding HTML Style
   -  Object
   -  Array (multiple)
   -  auto-prefix
   -  multiple-value

### Conditional Rendering

1. `v-if` and `v-else`

2. `v-else-if`

3. group by `template`

4. use `key` to re-render

5. `v-show`

   just toggle `display`

   difference:

   -  prefer `v-show` if you need to toggle something very often
   -  prefer `v-if` if the condition is unlikely to change at runtime.

### List Rendering

1. `v-for`

   -  `v-for='(item, index) in items'`

      `v-for='item of items' `

   -  `v-for='value in object'`

      `v-for='(value, key) in object'`

      `v-for='(value, key, index) in object'`

2. Array change detection

   some Array methods

   pure function => just replace

   ​