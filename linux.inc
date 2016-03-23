# global include file for the APE environment

SHELL=/bin/bash

HARVEYBIN=${HARVEY}/${ARCH}/bin
HARVEYLIB=${HARVEY}/${ARCH}/lib
APEXLIB=${APEX}/${ARCH}/lib
APEXBIN=${APEX}/${ARCH}/bin
AS=as
CC=gcc
LD=ld

IDIR=${APEX}/include
IOBJDIR=${APEX}/${ARCH}/include

CFLAGS= -std=c99 -O0 -static -mno-red-zone -ffreestanding -nostdinc -nostdlib -fno-builtin -D_SUSV2_SOURCE -D_POSIX_SOURCE -D_LIMITS_EXTENSION ${WFLAGS} -g -I${IDIR} -I${IOBJDIR}

WFLAGS=-Wall -Wno-missing-braces -Wno-parentheses -Wno-unknown-pragmas -Wuninitialized -Wmaybe-uninitialized 

AR=ar				# manipulating libraries
RANLIB=echo			# for updating libraries
