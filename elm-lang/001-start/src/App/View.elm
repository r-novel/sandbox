module App.View exposing (view)

import App.Messages exposing (..)
import App.Model exposing (Model)
import Html exposing (Html, div, text, button)
import Html.Events exposing(onClick)

view : Model -> Html Msg
view model =
    div []
      [ button [ onClick Decrement ] [text "-"]
      , div [] [ text (String.fromInt model) ]
      , button [ onClick Increment ] [text "+"]
      ]

