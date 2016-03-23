# global include file for the APE environment

SHELL=/bin/bash

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))
HARVEY=$(current_dir)
ARCH=amd64

BIN=${HARVEY}/${ARCH}/bin
LIB=${HARVEY}/${ARCH}/lib
AS=as
CC=gcc
LD=ld

IDIR=${HARVEY}/include
IOBJDIR=${HARVEY}/${ARCH}/include

CFLAGS= -std=c99 -O0 -static -mno-red-zone -ffreestanding -nostdinc -D_SUSV2_SOURCE -D_POSIX_SOURCE -D_LIMITS_EXTENSION ${WFLAGS} -g -I${IDIR} -I${IOBJDIR}

WFLAGS=-Wall -Wno-missing-braces -Wno-parentheses -Wno-unknown-pragmas -Wuninitialized -Wmaybe-uninitialized 

AR=ar				# manipulating libraries
RANLIB=echo			# for updating libraries
