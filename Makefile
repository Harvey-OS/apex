# Global include file for the APE environment

SHELL=/bin/bash

HARVEY=$(CURDIR)
objtype=amd64

BIN=${HARVEY}/${objtype}/bin	# where installed ape binaries go
LIB=${HARVEY}/${objtype}/lib		# where helper programs go
AS=as
CC=gcc
LD=ld

IDIR=${HARVEY}/include

CFLAGS=-O0 -static -fplan9-extensions -mno-red-zone -ffreestanding -nostdinc ${WFLAGS} -g -I${IDIR}

WFLAGS=-Wall -Wno-missing-braces -Wno-parentheses -Wno-unknown-pragmas -Wuninitialized -Wmaybe-uninitialized 

AR=ar				# manipulating libraries
RANLIB=echo			# for updating libraries

export

DIRS=lib

all:
	@mkdir -p ${LIB}; \
	for a in $(DIRS); do \
		if [ -d $$a ]; then \
			echo "Making Libs"; \
			cd $$a && $(MAKE); \
		fi; \
	done;
	@echo "Done!"
