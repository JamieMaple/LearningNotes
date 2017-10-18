# React Animation

### Some Exps

1. react-addons-css-transition

   ```jsx
   /* jsx */
   /* react-addons-css-transition */

   import ReactCSSTransitionGroup from 'react-addons-css-transition'

   const Hello = () => (

   	<ReactCSSTransitionGroup
     		transitionName='exp'
   		transitionAppear={true}
   		transitionAppearTimeout={500}
   		transitionEnter={false}
       	transitionLeave={false}
     	>
     		<h1>hello</h1>
     	</ReactCSSTransitionGroup>

   )
   ```

   ```css
   /* css */

   .exp-appear {

     opacity: 0;

   }

   .exp-appear.exp-appear-active {

     opacity: 1;

     transition: opacity .5s ease;

   }
   ```

2. react router HOC

   ```jsx
   const RouteWrapper = (Page) => {
     return (props) => (
       <ReactCSSTransitionGroup
         transitionName='exp'
         transitionAppear={true}
         transitionAppearTimeout={5000}
         transitionEnter={false}
         transitionLeave={false}
       >
         <Page {...props} />
       </ReactCSSTransitionGroup>
     )
   }
   ```

3. react transition goup

   - Transition
   - CSSTransition
   - TransitionGroup

### DOCS

1. Initial Mount

   `transitionAppear` and `transitionAppearTimeout`

   -  `transitionAppear` default value is false, while `transitionEnter` and `transitionLeave` default value are both true.
   -  During mounting, first get `transitionName-appear` and then add `transitionName-appear-active` in the next tick.
   -  However, all children add later will `enter` not `appear`

2. Custom Classes

   ```jsx
   <ReactTransitionGroup
     enter: 'enter',
     leave: 'leave',
     appear: 'appear'
   >
   	{items}
   </ReactTransitionGroup>
   ```

3. Some Low-level API

   lifecycle hooks

   -  [`componentWillAppear()`](https://reactjs.org/docs/animation.html#componentwillappear)
   -  [`componentDidAppear()`](https://reactjs.org/docs/animation.html#componentdidappear)
   -  [`componentWillEnter()`](https://reactjs.org/docs/animation.html#componentwillenter)
   -  [`componentDidEnter()`](https://reactjs.org/docs/animation.html#componentdidenter)
   -  [`componentWillLeave()`](https://reactjs.org/docs/animation.html#componentwillleave)
   -  [`componentDidLeave()`](https://reactjs.org/docs/animation.html#componentdidleave)

   Renderning a component

   `ReactCSSTransitionGroup` defualt renders `span`, providng a component prop to it and then will change the element.

   ​

### Reference

1. Official docs

   >  https://reactjs.org/docs/animation.html

2. blog

   >  https://blog.logrocket.com/routes-animation-transitions-in-react-router-v4-9f4788deb964

3. ​