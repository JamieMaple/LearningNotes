export interface IAction<T> {
  type: string;
  payload?: T;
}

export interface IReducer<S> {
  <T>(state: S, action: IAction<T>): S;
}

// 低配版 redux(其实我觉得这就是 redux 的核心了)
export function createStore<S>(reducer: IReducer<S>, preloadState?: S): IStore<S> {
  let currentState: S = preloadState!

  function dispatch<T>(action: IAction<T>) {
    currentState = reducer(currentState, action)

    return action;
  }

  function getState() {
    return currentState
  }

  return { dispatch, getState }
}

type EnhancerType<S, R> = ReturnType<typeof applyMiddleware>
export function createStoreWithMiddeware<S>(reducer: IReducer<S>, preloadState?: S, enhancer?: EnhancerType<S, any>): IStore<S> {
  let currentState: S
  if (preloadState != null&& typeof preloadState === 'object') {
    currentState = preloadState
  } else if (typeof enhancer !== 'function' && typeof preloadState === 'function') {
    enhancer = preloadState as any
    preloadState = undefined
  }

  if (typeof enhancer === 'function') {
    return enhancer(createStoreWithMiddeware)(reducer, preloadState)
  }


  function dispatch<T>(action: IAction<T>) {
    currentState = reducer(currentState, action)

    return action;
  }

  function getState() {
    return currentState
  }

  return { dispatch, getState }
}

export interface IReducerMap<S> {
  [propName: string]: IReducer<S>;
}

interface IState extends Object {
  [propName: string]: any;
}

// combine
export function combineReducer<S extends IState>(reducerMap: IReducerMap<S>): IReducer<S> {
  return <T>(state: S, action: IAction<T>) => Object.keys(reducerMap).reduce((reducer, key) => 
    ({ ...reducer, [key]: reducerMap[key](state ? state[key] : undefined, action) })
    , {} as S)
}

// middlewares
interface IStore<S> {
  dispatch<T>(action: IAction<T>): any;
  getState(): S;
}
interface INextType<T, R> {
  (action: IAction<T>): R;
}
interface IMiddleware<S, T, R> {
  (store: IStore<S>): <RR>(next: INextType<T, RR>) => (action: IAction<T>) => R;
}
export function applyMiddleware<S extends any, T extends any, R extends any>(...middlewares: IMiddleware<S, T, R>[]) {
  return (storeCreator: typeof createStore) => (reducer: IReducer<S>, preloadState?: S) => {
    let dispatch: <T>(action: IAction<T>) => any
    const store = storeCreator<S>(reducer, preloadState)
    const middlewaresWithStore = middlewares.map(middleware => middleware({ getState: store.getState, dispatch: dispatch }))
    dispatch = compose(...middlewaresWithStore)(store.dispatch)

    return {
      ...store,
      dispatch
    }
  }
}

function compose(...fg: any[]) {
  return (v: any) => fg.reduceRight((r, f) => f(r), v)
}

