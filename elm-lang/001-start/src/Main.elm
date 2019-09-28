module Main exposing (main)

import App.Messages exposing (Msg)
import App.Model exposing (Model, init)
import App.Update exposing (update)
import App.View exposing (view)
import Browser

main =
  Browser.sandbox { init = init, update = update, view = view}
