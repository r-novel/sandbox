module App.Update exposing (update)

import App.Messages exposing (..)
import App.Model exposing (Model)

update : Msg -> Model -> Model
update msg model =
  case msg of
    Increment ->
      model + 1
    Decrement ->
      model - 1
