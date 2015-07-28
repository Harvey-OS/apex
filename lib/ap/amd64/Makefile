include ../../../Makefile.inc

TARGET = libap.a
SRCS =\
	notetramp.c \

OBJ = ${SRCS:.c=.o}

PCFLAGS= $(CFLAGS) -D_PLAN9_SOURCE

.PHONY: clean all

all: clean $(TARGET)

%.o: %.c
	$(CC) $(PCFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)