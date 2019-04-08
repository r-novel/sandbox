SHELL := /bin/bash
AS := nasm
ASFLAGS := -f macho64
LDFLAGS := -macosx_version_min $(shell sw_vers | egrep -o '([0-9]{1,}\.)+[0-9]{1,}') -lSystem
LD := ld

PATH-PROJECT := $(shell pwd)
PATH-BIN := $(PATH-PROJECT)/bin
PATH-OBJ := $(PATH-BIN)

.DEFAULT: default
.PHONY: all default build
.PHONY: all clean

default: build
build: create-bin array

clean:
	rm -rvf \
		$(PATH-OBJ)/*

create-bin:
	mkdir -p $(PATH-BIN)

$(PATH-OBJ)/array.o: $(PATH-PROJECT)/array.asm
	$(AS) $(ASFLAGS) $< -o $@

array: $(PATH-OBJ)/array.o
	$(LD) -o $(PATH-BIN)/$@ $+ $(LDFLAGS)
