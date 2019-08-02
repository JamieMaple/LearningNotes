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
const store = redux_1.createStore(rootReducer);
const getState = function () {
    console.log(store.getState());
};
store.dispatch({ type: 'increment' });
getState();
store.dispatch({ type: 'decrement' });
getState();
store.dispatch({ type: 'greet', payload: 'Hello World' });
getState();
//# sourceMappingURL=redux-test.js.map