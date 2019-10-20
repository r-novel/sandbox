package main

import (
	"io"
	"log"
	"net"
	"os"
)

func main() {
	cp := func(dst io.Writer, src io.Reader) {
		if _, e := io.Copy(dst, src); e != nil {
			log.Fatal(e)
		}
	}

	conn, e := net.Dial("tcp", "127.0.0.1:8080")
	if e != nil {
		log.Fatal(e)
	}
	defer conn.Close()
	cp(os.Stdout, conn)

}
