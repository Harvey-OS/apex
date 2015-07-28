include ../../Makefile.inc

TARGET = libbsd.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

BSDFLAGS= $(CFLAGS) -D_BSD_EXTENSION -D_PLAN9_SOURCE

.PHONY: clean all

all: clean $(TARGET)

%.o: %.c
	$(CC) $(BSDFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)