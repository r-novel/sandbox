SHELL := /bin/bash

CC := gcc

CFLAGS := -O0 -std=gnu99
WFLAGS := -Wall
LDFLAGS :=

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: create-bin hide-if

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/hide-if.o: $(PATH-PROJECT)/hide-if.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

hide-if: \
	$(PATH-OBJ)/hide-if.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
