include ../../../Makefile.inc

TARGET = libap.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I../internal -D_PLAN9_SOURCE -D_BSD_EXTENSION

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)
