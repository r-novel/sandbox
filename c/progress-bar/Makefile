SHELL := /bin/bash

CC := gcc

CFLAGS := -O1 -std=c99 -pipe
WFLAGS := -Wall -Werror
LDFLAGS :=

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: create-bin progress-bar

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/main.o: $(PATH-PROJECT)/main.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

progress-bar: \
	$(PATH-OBJ)/main.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
