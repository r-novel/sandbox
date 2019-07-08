package main

import (
	"log"
	"os"
)

func tmpDirs() (out []string) {
	out = append(out, "tmp-01")
	out = append(out, "tmp-02")
	out = append(out, "tmp-03")

	return
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

	log.Println("directories have created;")

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
