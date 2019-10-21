package main

import (
	"io"
	"log"
	"net"
	"os"
	"strconv"

	flag "github.com/spf13/pflag"
)

func main() {
	cp := func(dst io.Writer, src io.Reader) {
		if _, e := io.Copy(dst, src); e != nil {
			log.Fatal(e)
		}
	}

	typeConn := flag.String("type", "tcp", "connection type")
	host := flag.String("host", "0.0.0.0", "server hostname")
	port := flag.Int("port", 8080, "server port")

	flag.Parse()

	addr := *(host) + ":" + strconv.Itoa(*port)

	conn, e := net.Dial(*typeConn, addr)
	if e != nil {
		log.Fatal(e)
	}
	defer conn.Close()
	cp(os.Stdout, conn)

}
