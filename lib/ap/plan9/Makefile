include ../../../Makefile.inc

TARGET = libap.a
SRCS =\
	convM2D.c \
	dirread.c \
	_envsetup.c \
	_errno.c \
	_exit.c \
	_fdinfo.c \
	getpgrp.c \
	isatty.c \
	kill.c \
	lseek.c \
	setpgid.c \
	signal.c \
	sigprocmask.c \

OBJ = ${SRCS:.c=.o}

CFLAGS += -I../internal -D_PLAN9_SOURCE

.PHONY: clean all

all: clean $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)
