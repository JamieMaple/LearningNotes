"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// 低配版 redux(其实我觉得这就是 redux 的核心了)
function createStore(reducer, preloadState) {
    let currentState = preloadState;
    function dispatch(action) {
        currentState = reducer(currentState, action);
        return action;
    }
    function getState() {
        return currentState;
    }
    return { dispatch, getState };
}
exports.createStore = createStore;
function createStoreWithMiddeware(reducer, preloadState, enhancer) {
    let currentState;
    if (preloadState != null && typeof preloadState === 'object') {
        currentState = preloadState;
    }
    else if (typeof enhancer !== 'function' && typeof preloadState === 'function') {
        enhancer = preloadState;
        preloadState = undefined;
    }
    if (typeof enhancer === 'function') {
        return enhancer(createStoreWithMiddeware)(reducer, preloadState);
    }
    function dispatch(action) {
        currentState = reducer(currentState, action);
        return action;
    }
    function getState() {
        return currentState;
    }
    return { dispatch, getState };
}
exports.createStoreWithMiddeware = createStoreWithMiddeware;
// combine
function combineReducer(reducerMap) {
    return (state, action) => Object.keys(reducerMap).reduce((reducer, key) => (Object.assign({}, reducer, { [key]: reducerMap[key](state ? state[key] : undefined, action) })), {});
}
exports.combineReducer = combineReducer;
function applyMiddleware(...middlewares) {
    return (storeCreator) => (reducer, preloadState) => {
        let dispatch;
        const store = storeCreator(reducer, preloadState);
        const middlewaresWithStore = middlewares.map(middleware => middleware({ getState: store.getState, dispatch: dispatch }));
        dispatch = compose(...middlewaresWithStore)(store.dispatch);
        return Object.assign({}, store, { dispatch });
    };
}
exports.applyMiddleware = applyMiddleware;
function compose(...fg) {
    return (v) => fg.reduceRight((r, f) => f(r), v);
}
//# sourceMappingURL=redux.js.map