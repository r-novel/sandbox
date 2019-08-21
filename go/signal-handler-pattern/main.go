package main

import (
	"context"
	"fmt"
	"log"
	"net/http"
	"os"
	"os/signal"
	"syscall"

	color "github.com/NovelCorpse/go-color"
)

func helloWorld(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello world!")
}

func start() (outErr error) {
	// timeout := 5 * time.Second

	server := &http.Server{
		Addr:    "127.0.0.1:8080",
		Handler: nil,
	}

	serverErrChan := make(chan struct{})
	ctx, cancel := context.WithCancel(context.Background())

	go func() {
		signalChan := make(chan os.Signal, 1)
		signal.Notify(signalChan,
			syscall.SIGINT, os.Interrupt,
			syscall.SIGTERM,
			syscall.SIGQUIT,
		)

		select {
		case _, ok := <-signalChan:
			if ok {
				log.Printf("%s\n", color.SGreen("(SIGINT, SIGTERM, SIGQUIT) will shutdown;"))
			}
		case <-serverErrChan:
		}

		cancel()

	}()

	go func() {
		<-ctx.Done()

		if err := server.Shutdown(nil); err != nil {
			fmt.Printf("%s\n", color.SRed("server shutdown failed: %s", err))
		}
	}()

	log.Printf("%s", color.SGreen("application with pid", os.Getpid()))
	log.Printf("%s", color.SGreen("listening on", "127.0.0.1:8080"))

	http.HandleFunc("/", helloWorld)

	if err := server.ListenAndServe(); err != nil && err != http.ErrServerClosed {
		close(serverErrChan)
		outErr = err
	}

	return outErr
}

func main() {
	start()
}
