package main

import (
	"fmt"
	"time"
)

type Client struct{ Request string }
type Server struct{ Response string }

func main() {
	conn := make(chan string, 1)
	defer close(conn)
	done := make(chan struct{})
	defer close(done)

	client := &Client{"request message"}
	server := &Server{"respose message"}

	conn <- client.Request
	fmt.Println("client sent ", client.Request)

	go func(in chan string) {
		/*get data from conn channel;*/
		req := <-conn

		fmt.Println("server received: ", req)
		fmt.Println("server sending resp...")

		/*simulate delay; */
		time.Sleep(5 * time.Second)

		conn <- server.Response
		fmt.Println("server sent: ", server.Response)

		/*emitted done signal to done channel;*/
		done <- struct{}{}

	}(conn)

	fmt.Println("client waiting...")
	/*block until got value from done channel;*/
	<-done

	resp := <-conn
	fmt.Println("client received: ", resp)

}
