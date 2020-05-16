package main

import (
	"fmt"
	"log"
	"math/rand"
	"net/http"

	"encoding/base64"

	"github.com/gorilla/mux"
	webrtc "github.com/pion/webrtc/v2"
)

var (
	srcVideo = "uridecodebin uri=file:///opt/sintel2.mkv ! videoscale ! video/x-raw, width=320, height=240 ! queue"
	srcAudio = "uridecodebin uri=file:///opt/sintel2.mkv ! queue ! audioconvert"
)

func StartHTTPServer() {
	r := mux.NewRouter()
	r.HandleFunc("/recive", HTTPHome)
	r.PathPrefix("/").Handler(http.StripPrefix("/", http.FileServer(http.Dir("static/"))))

	go func() {
		err := http.ListenAndServe(":8080", r)
		if err != nil {
		}
	}()
	select {}
}
func HTTPHome(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Access-Control-Allow-Origin", "*")
	data := r.FormValue("data")
	sd, err := base64.StdEncoding.DecodeString(data)
	if err != nil {
		log.Println(err)
		return
	}

	peerConnection, err := webrtc.NewPeerConnection(webrtc.Configuration{
		ICEServers: []webrtc.ICEServer{
			{
				URLs: []string{"stun:stun.l.google.com:19302"},
			},
		},
	})
	if err != nil {
		panic(err)
	}

	peerConnection.OnICEConnectionStateChange(func(connectionState webrtc.ICEConnectionState) {
		fmt.Printf("Connection State has changed %s \n", connectionState.String())
	})

	audioTrack, err := peerConnection.NewTrack(webrtc.DefaultPayloadTypeOpus, rand.Uint32(), "audio", "pion1")
	if err != nil {
		panic(err)
	}
	_, err = peerConnection.AddTrack(audioTrack)
	if err != nil {
		panic(err)
	}

	// Create a video track
	firstVideoTrack, err := peerConnection.NewTrack(webrtc.DefaultPayloadTypeVP8, rand.Uint32(), "video", "pion2")
	if err != nil {
		panic(err)
	}
	_, err = peerConnection.AddTrack(firstVideoTrack)
	if err != nil {
		panic(err)
	}

	// Create a second video track
	secondVideoTrack, err := peerConnection.NewTrack(webrtc.DefaultPayloadTypeVP8, rand.Uint32(), "video", "pion3")
	if err != nil {
		panic(err)
	}
	_, err = peerConnection.AddTrack(secondVideoTrack)
	if err != nil {
		panic(err)
	}

	offer := webrtc.SessionDescription{
		Type: webrtc.SDPTypeOffer,
		SDP:  string(sd),
	}
	// signal.Decode(signal.MustReadStdin(), &offer)

	if err := peerConnection.SetRemoteDescription(offer); err != nil {
		fmt.Printf("~~~> ERROR IS Set Remote SDP: %v\n", err)
		log.Println(err)
		return
	}

	answer, err := peerConnection.CreateAnswer(nil)
	if err != nil {
		fmt.Printf("~~~> ERROR IS CREATE A: %v\n", err)
		log.Println(err)
		return
	}

	err = peerConnection.SetLocalDescription(answer)
	if err != nil {
		panic(err)
	}

	w.Write([]byte(base64.StdEncoding.EncodeToString([]byte(answer.SDP))))

	fmt.Printf("~~~~> Write resp%v\n")

}
