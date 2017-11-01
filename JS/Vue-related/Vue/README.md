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

   doesnt support `template`

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

   Use `Vue.set({target, key, value})` to change Array

   Or use `splice`

3. Object change detection

   `this.$set === Vue.set`

4. `v-for` has a higher priority than `v-if`

5. `v-for` with components

### Event Handling

1. `v-on` listening to events

2. 各种 `v-on` 里面的写法

3. `$event` 在方法中传入

4. Events Modifiers

   -  `.stop`


   -  `.prevent`


   -  `.capture`


   -  `.self`


   -  `.once`

   Also can be chained

   **order matters**

5. Key Modifiers

   -  `.exact`
   -  Mouse Button Modifiers

### Form Input Binding

1. `v-model`

   >  `v-model` is essentially syntax sugar for updating data on user input events, plus special care for some edge cases.

   -  Text
   -  Multiple Text
   -  Checkbox
   -  Radio
   -  Select
   -  Multiple Select

2. Modifiers

   -  `.lazy`
   -  `.number`
   -  `.trim`

3. With Components

### Components

1. Using

   -  Global Registration

      >  Make sure the component is registered **before** you instantiate the root Vue instance.

      ```vue
      <div id="example">
        <my-component></my-component>
      </div>

      // register
      Vue.component('my-component', {
        template: '<div>A custom component!</div>'
      })
      // create a root instance
      new Vue({
        el: '#example'
      })
      ```

   -  Local Registration

      ```javascript
      var Child = {
        template: '<div>A custom component!</div>'
      }
      new Vue({
        // ...
        components: {
          // <my-component> will only be available in parent's template
          'my-component': Child
        }
      })
      ```

   -  DOM Template Parsing Caveats

      DOM has some restriction

      ```vue
      <table>
        <my-row>...</my-row>s
      </table>
      ```
      has changed to 

      ```vue
      <table>
        <tr is="my-row"></tr>
      </table>
      ```

   -  `data` must be a function

      **it is very similar to functional programming**

      to solve share data problem

   -  Composing Components

      *parent* with *child*

      ![](https://vuejs.org/images/props-events.png)

2. Props

   -  parent down to child

      ```javascript
      Vue.component('child', {
        // declare the props
        props: ['message'],
        // like data, the prop can be used inside templates and
        // is also made available in the vm as this.message
        template: '<span>{{ message }}</span>'
      })
      ```

   -  camelCase and kebab-case

      ```javascript
      Vue.component('child', {
        // camelCase in JavaScript
        props: ['myMessage'],
        template: '<span>{{ myMessage }}</span>'
      })

      <!-- kebab-case in HTML -->
      <child my-message="hello!"></child>
      ```

   -  Dynamic Props

      use `v-bind` to props

      `v-bind` instead of `v-bind:prop-name` for object props

   -  One-Way data flow

      刚开始感觉这个就很不函数式了....不过 `vue` 的整体感觉确实像是指令式编程

      不过的话他也是和 `React` 差不多利用了父组件的函数更新状态

   -  Prop Validation

3. Non-Prop Attribute

   - Replacing/Merging with Existing Attributes

4. Custom Events

   -  using `v-on` with custom events
   -  binding native events to components
   -  `.sync` Modifier
   -  form input

5. Content Distribution with Slots

   -  Compilation Scope
   -  Single Slot
   -  Named Slots
   -  Scope Slots
   -  template


### Transition / Animation

1. Transition Single Elements / Components

   `<transition`> warpper

   transition classes

   css transitions

   explicit transition durations

   javascript hooks

2. `appear` attribute

3. Transition between elements

   `transition` mode

4. Transition between components

5. List transition




### State Transition

1. Animating state with watchers
2. Dynamic State Transitions
3. Organizing Transitions into Components



### Mixins

1. 栗子

   ```javascript
   // define a mixin object
   var myMixin = {
     created: function () {
       this.hello()
     },
     methods: {
       hello: function () {
         console.log('hello from mixin!')
       }
     }
   }
   // define a component that uses this mixin
   var Component = Vue.extend({
     mixins: [myMixin]
   })
   var component = new Component() // => "hello from mixin!"
   ```

2. merge to array and objectpal



















