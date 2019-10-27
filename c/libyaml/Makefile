SHELL := /bin/bash

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJECTS := $(PATH-BIN)

CC := gcc

CFLAGS := -O0 -std=gnu99 -pipe
WFLAGS := -Wall -Werror
LDFLAGS := -lyaml

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: ensure-dirs yml-parser

clean:
	rm -rvf \
		$(PATH-OBJECTS)/*

ensure-dirs:
	mkdir -p $(PATH-BIN)

$(PATH-OBJECTS)/yml-parser.o: yml_parser.c
	$(CC) "-D__WFILE__=\"`basename $<`\"" $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

yml-parser: \
	$(PATH-OBJECTS)/yml-parser.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
