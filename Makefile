# Global include file for the APE environment

SHELL=/bin/bash

HARVEY=$(CURDIR)
objtype=amd64

BIN=${HARVEY}/${objtype}/bin
LIB=${HARVEY}/${objtype}/lib
AS=as
CC=gcc
LD=ld

IDIR=${HARVEY}/include
IOBJDIR=${HARVEY}/amd64/include

CFLAGS=-O0 -static -fplan9-extensions -mno-red-zone -ffreestanding -nostdinc -D_SUSV2_SOURCE -D_POSIX_SOURCE -D_LIMITS_EXTENSION ${WFLAGS} -g -I${IDIR} -I${IOBJDIR}

WFLAGS=-Wall -Wno-missing-braces -Wno-parentheses -Wno-unknown-pragmas -Wuninitialized -Wmaybe-uninitialized 

AR=ar				# manipulating libraries
RANLIB=echo			# for updating libraries

export

DIRS=lib

all:
	@cd $(DIRS) && $(MAKE)
	@echo "Done!"
