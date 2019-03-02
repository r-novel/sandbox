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
build: logo create-bin logger

logo: 
	@echo \
		-e \
		"\x1B[5;49;36m \\n" \
		"   __                          	 \\n" \
		"  / /  ___   __ _  __ _  ___ _ __ \\n" \
		" / /  / _ \ / _  |/ _  |/ _ \ '__|\\n" \
		"/ /__| (_) | (_| | (_| |  __/ |   \\n" \
		"\____/\___/ \__, |\__, |\___|_|   \\n" \
		"            |___/ |___/           \\n" \
		"\033[0m \\n"

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/main.o: $(PATH-PROJECT)/main.c
	$(CC) $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

logger: \
	$(PATH-OBJ)/main.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)