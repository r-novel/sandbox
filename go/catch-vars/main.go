package main

import (
	"log"
	"os"
)

func tempDirs() (out []string) {
	return append(out, "tmp-01", "tmp-02", "tmp-03")
}

func good() {
	var rmdirs []func()
	for _, dir := range tempDirs() {
		dir := dir
		os.MkdirAll(dir, 0755)
		rmdirs = append(rmdirs, func() {
			log.Printf("dir name is %s has removed;\n", dir)
			os.RemoveAll(dir)
		})
	}

	log.Println("directories have created;")

	for _, rmdir := range rmdirs {
		rmdir()
	}
}

func bad() {
	var rmdirs []func()

	for _, dir := range tempDirs() {
		os.MkdirAll(dir, 0755)
		rmdirs = append(rmdirs, func() {
			log.Printf("dir name is %s has removed;\n", dir)
			os.RemoveAll(dir)
		})
	}

	log.Println("directories have removed;")

	for _, rmdir := range rmdirs {
		rmdir()
	}
}

func main() {
	if len(os.Args) < 2 {
		log.Println("choose variant: good, bad;")
	}

	for _, arg := range os.Args {
		if arg == "bad" {
			bad()
		}

		if arg == "good" {
			good()
		}
	}

}
