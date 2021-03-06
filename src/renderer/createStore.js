// @flow

import type { RouterHistory } from 'react-router-dom'

import { createStore, applyMiddleware, compose } from 'redux'
import { routerMiddleware } from 'react-router-redux'
import thunk from 'redux-thunk'

import db from 'middlewares/db'

import reducers from 'reducers'

export default (history: RouterHistory) => {
  const middlewares = [routerMiddleware(history), thunk, db]
  const enhancers = compose(
    applyMiddleware(...middlewares),
    window.devToolsExtension ? window.devToolsExtension() : f => f, // eslint-disable-line
  )
  return createStore(reducers, undefined, enhancers)
}
