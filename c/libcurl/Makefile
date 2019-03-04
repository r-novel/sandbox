SHELL := /bin/bash

CC := gcc

CFLAGS := -O1 -std=c99 -pipe
WFLAGS := -Wall
LDFLAGS := -lcurl

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: logo create-bin out

logo:
	@echo \
		-e \
		"\x1B[5;49;36m 														\\n" \
		"     ___ __                    __  			\\n" \
		"    / (_) /_  _______  _______/ /  			\\n" \
		"   / / / __ \/ ___/ / / / ___/ /   			\\n" \
		"  / / / /_/ / /__/ /_/ / /  / /    			\\n" \
		" /_/_/_.___/\___/\__,_/_/  /_/     __ 		\\n" \
		"  ___  _  ______ _____ ___  ____  / /__ 	\\n" \
		" / _ \| |/_/ __ \`/ __ \`__ \/ __ \/ / _ \ \\n" \
		"/  __/>  </ /_/ / / / / / / /_/ / /  __/ \\n" \
		"\___/_/|_|\__,_/_/ /_/ /_/ .___/_/\___/  \\n" \
		"                        /_/              \\n" \
		"\033[0m \\n"

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/main.o: $(PATH-PROJECT)/main.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

out: \
	$(PATH-OBJ)/main.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
