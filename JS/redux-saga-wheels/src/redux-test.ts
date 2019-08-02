import { combineReducer, IAction, createStore, IReducer } from './redux'

// reducer
interface ICounter {
  count: number;
}
function counter(state: ICounter = { count : 0 }, action: IAction<undefined>): ICounter {
  switch (action.type) {
    case 'increment':
      return { count: state.count + 1 }
    case 'decrement':
      return { count: state.count - 1 }
    default:
      return { count: state.count }
  } 
}

interface IMessage {
  message: string;
}
function greeting(state: IMessage = { message: 'Hello' }, action: IAction<string>): IMessage {
  switch (action.type) {
    case 'greet':
      return { message: action.payload || '' }
    default:
      return state
  }
}

type IRootReducer = ICounter|IMessage
const rootReducer = combineReducer<IRootReducer>({
  counter: counter as IReducer<IRootReducer>,
  greeting: greeting as IReducer<IRootReducer>
})
const store = createStore(rootReducer)

const getState = function() {
  console.log(store.getState())
}

store.dispatch({ type: 'increment' })
getState()
store.dispatch({ type: 'decrement' })
getState()
store.dispatch({ type: 'greet', payload: 'Hello World' })
getState()

