include ../../../Makefile.inc

TARGET = libap.a
SRCS =\
	notetramp.c \

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
