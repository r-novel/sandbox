SHELL := /bin/bash

CC := gcc

CFLAGS := -O0 -std=gnu99
WFLAGS := -Wall -Werror
LDFLAGS :=

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: create-bin epoll-sample

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/main.o: $(PATH-PROJECT)/main.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

epoll-sample: \
	$(PATH-OBJ)/main.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
