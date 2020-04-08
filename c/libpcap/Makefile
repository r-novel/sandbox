PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJECTS := $(PATH-BIN)

CC := gcc

CFLAGS := -O0 -std=gnu99 -pipe
WFLAGS := -Wall -Werror
LDFLAGS := -lpcap

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: ensure-dirs pcap-01

clean:
	rm -rvf \
		$(PATH-OBJECTS)/*

ensure-dirs:
	mkdir -p $(PATH-BIN)

$(PATH-OBJECTS)/pcap-01.o: pcap-01.c
	$(CC) "-D__WFILE__=\"`basename $<`\"" $(CFLAGS) $(WFLAGS) -c -fPIC $< -o $@

pcap-01: \
	$(PATH-OBJECTS)/pcap-01.o
	$(CC) $(CFLAGS) $(WFLAGS) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
