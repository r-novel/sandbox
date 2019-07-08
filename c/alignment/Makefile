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
build: create-bin packing alignof alignment offsetof

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/packing-example.o: $(PATH-PROJECT)/packing-example.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

$(PATH-OBJ)/alignment-example.o: $(PATH-PROJECT)/alignment-example.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

$(PATH-OBJ)/offsetof-example.o: $(PATH-PROJECT)/offsetof-example.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

$(PATH-OBJ)/alignof-example.o: $(PATH-PROJECT)/alignof-example.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

packing: \
	$(PATH-OBJ)/packing-example.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)

alignof: \
	$(PATH-OBJ)/alignof-example.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)

alignment: \
	$(PATH-OBJ)/alignment-example.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)

offsetof: \
	$(PATH-OBJ)/offsetof-example.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
