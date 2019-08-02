function Channel() {
  const taker = []
  function take(cb) {
    taker.push(cb)
  }

  function put(input) {
    taker.shift()(input)
  }

  return {
    take,
    put,
  }
}

function multicastChannel() {
  let currentTakers = []
  let nextTakers = currentTakers

  const ensureCanMutateNextTakers = () => {
    if (nextTakers !== currentTakers) {
      return
    }
    nextTakers = currentTakers.slice()
  }

  return {
    'MULTICAST': true,
    put(input) {
      const takers = currentTakers = nextTakers
      for (let i = 0, len = takers.length; i < len; ++i) {
        const taker = takers[i]

        if (taker['MATCH'](input)) {
          taker(input)
        }
      }
    },
    take(cb, matcher = _ => true) {
      cb['MATCH'] = matcher
      ensureCanMutateNextTakers()
      nextTakers.push(cb)
    }
  }
}

function stdChannel() {
}

function take(pattern = '*') {
  return {
    IO: true,
    payload: { pattern },
    combinator: false, // ALL
    type: patternOrChannel
  }
}

function fork(fn, ...args) {
  return {
    IO: true,
    payload: { fn, args }
  }
}

function matcher(pattern) {
  return input => input.type === pattern
}

function runTakeEffect(env,  { channel = env.channel, pattern }, cb) {
  channel.take(cb, pattern != undefined ? matcher(input) : null)
}

function runForkEffect(env, payload, next) {
  // TODO : run payload fn
  // newChildTask -> next -> main task run
}

const effectRunnerMap = {
  'TAKE': runTakeEffect,
}

function proc({ channel, iterator, dispatch }) {
  // main task

  // main task descriptor
  const task = null

  next()

  return task

  function next(arg) {
    let result = iterator.next(arg)

    if (!result.done) {
      runEffect(result.value, next)
    } else {
      // done!
    }
  }

  function runEffect(effect, cb) {
    if (effect instanceof Promise) {
      effect.then(cb)
    } else if (effect && effect['IO']) {
      const effectRunner = effectRunnerMap[effect.type]
      effectRunner(env, effect.payload, cb)
    } else {
      // TODO: iterator
      cb(effect)
    }
  }
}

function runSaga({ channel, dispatch, getState }, saga, ...args) {
  // get the iterator
  const it = saga(...args)
  // effectsMiddlewares
  let finalizeRunEffect
  if (false) {
    // middlewares
  } else {
    // identity
    finalizeRunEffect = v => v
  }
  const env = {
    channel,
    dispatch: dispatch => action => dispatch(Object.defineProperty(action, '@@SAGA_ACTION', { value: true })),
    getState,
    finalizeRunEffect
  }

  return proc({ channel, dispatch, iterator })
}

function sagaMiddlewareFactory() {
  const channel = Channel()
  let boundRunSaga

  const middleware = store => next => action => {
    boundRunSaga = runSaga.bind(undefined, { channel, ...store })
    const result = next()
    channel.put(action)
    return result
  }

  middleware.run = (...args) => {
    return boundRunSaga(...args)
  }

  return middleware
}

//
// curry hof hoc
// imutable
// 