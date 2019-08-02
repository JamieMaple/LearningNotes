"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const redux_1 = require("./redux");
function counter(state = { count: 0 }, action) {
    switch (action.type) {
        case 'increment':
            return { count: state.count + 1 };
        case 'decrement':
            return { count: state.count - 1 };
        default:
            return { count: state.count };
    }
}
function greeting(state = { message: 'Hello' }, action) {
    switch (action.type) {
        case 'greet':
            return { message: action.payload || '' };
        default:
            return state;
    }
}
const rootReducer = redux_1.combineReducer({
    counter: counter,
    greeting: greeting
});
const enhancer = redux_1.applyMiddleware(store => next => action => {
    console.log('mid1 begin action: ', action.type);
    next(action);
    console.log('mid1 end action: ', action.type);
}, store => next => action => {
    console.log('mid2 begin action payload: ', action.payload);
    next(action);
    console.log('mid2 end action payload: ', action.payload);
});
const store = redux_1.createStoreWithMiddeware(rootReducer, enhancer);
store.dispatch({ type: 'increment' });
store.dispatch({ type: 'decrement' });
store.dispatch({ type: 'greet', payload: 'Hello World' });
//# sourceMappingURL=redux-mid-test.js.map