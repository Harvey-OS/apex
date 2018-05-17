# global include file for the APE environment

SHELL=/bin/bash

HARVEYBIN=${HARVEY}/${ARCH}/bin
HARVEYLIB=${HARVEY}/${ARCH}/lib
APEXLIB=${APEX}/${ARCH}/lib
APEXBIN=${APEX}/${ARCH}/bin
AS=as
ifndef CC
    CC=gcc
endif
LD=ld

IDIR=${APEX}/include
IOBJDIR=${APEX}/${ARCH}/include

CFLAGS= -std=c11 -O2 -static -mno-red-zone -ffreestanding -nostdinc -nostdlib -D_SUSV2_SOURCE -D_POSIX_SOURCE -D_LIMITS_EXTENSION -DHARVEY ${WFLAGS} -g -I${IDIR} -I${IOBJDIR}

WFLAGS=-Wall -Wno-missing-braces -Wno-parentheses -Wno-unknown-pragmas -Wuninitialized

AR=ar				# manipulating libraries
RANLIB=echo			# for updating libraries
