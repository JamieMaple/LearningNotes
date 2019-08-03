import { combineReducer, IAction, IReducer, applyMiddleware, createStoreWithMiddeware } from './redux'

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

const enhancer = applyMiddleware(store => next => action => {
  console.log('mid1 begin action: ', action.type)
  next(action)
  console.log('mid1 end action: ', action.type)
}, store => next => action => {
  console.log('mid2 begin action payload: ', action.payload)
  next(action)
  console.log('mid2 end action payload: ', action.payload)
})
const store = createStoreWithMiddeware(rootReducer, enhancer as any)

store.dispatch({ type: 'increment' })
store.dispatch({ type: 'decrement' })
store.dispatch({ type: 'greet', payload: 'Hello World' })