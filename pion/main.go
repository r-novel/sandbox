package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

func NewRouter() *gin.Engine {
	gin.SetMode(gin.ReleaseMode)

	r := gin.Default()
	r.Static("/static", "./web")
	r.StaticFile("/", "./web/index.html")

	return r
}

func main() {
	router := NewRouter()

	server := &http.Server{
		Addr:    "127.0.0.1:8002",
		Handler: router,
	}

	if err := server.ListenAndServe(); err != nil && err != http.ErrServerClosed {
		log.Printf("error with serve: (%s)\n", err)
	}
}
