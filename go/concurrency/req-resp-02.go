package main

import (
	"fmt"
	"time"
)

func main() {
	ReqResp := make(chan chan string)
	responseChan := make(chan string)

	go func(chan chan string) {
		responseChan := <-ReqResp
		responseChan <- "writed some response!!!"
	}(ReqResp)

	fmt.Printf("Waiting stop response goroutine...\n")
	time.Sleep(2 * time.Second)

	ReqResp <- responseChan
	msg := <-responseChan

	fmt.Printf("Response: %v\n", msg)
}
