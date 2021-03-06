// @flow

import { combineReducers } from 'redux'
import { routerReducer as router } from 'react-router-redux'

import type { LocationShape } from 'react-router'

import application from './application'
import accounts from './accounts'
import devices from './devices'
import modals from './modals'
import settings from './settings'
import update from './update'

import type { ApplicationState } from './application'
import type { AccountsState } from './accounts'
import type { DevicesState } from './devices'
import type { ModalsState } from './modals'
import type { SettingsState } from './settings'
import type { UpdateState } from './update'

export type State = {
  application: ApplicationState,
  accounts: AccountsState,
  devices: DevicesState,
  modals: ModalsState,
  router: LocationShape,
  settings: SettingsState,
  update: UpdateState,
}

export default combineReducers({
  application,
  accounts,
  devices,
  modals,
  router,
  settings,
  update,
})
