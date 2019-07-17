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
build: create-bin reader writer

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/writer.o: $(PATH-PROJECT)/writer.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

writer: \
	$(PATH-OBJ)/writer.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)

$(PATH-OBJ)/reader.o: $(PATH-PROJECT)/reader.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

reader: \
	$(PATH-OBJ)/reader.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
