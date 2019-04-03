SHELL := /bin/bash
AS := nasm
ASFLAGS := -f macho64
LDFLAGS := -macosx_version_min 10.12 -lSystem
LD := ld

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: create-bin hello-world

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/hello-world.o: $(PATH-PROJECT)/hello-world.asm
	$(AS) $(ASFLAGS) $< -o $@

hello-world: $(PATH-OBJ)/hello-world.o
	$(LD) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
