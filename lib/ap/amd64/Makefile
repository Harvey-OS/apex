include ../../../Makefile.inc

TARGET = libap.a
SRCS =\
	notetramp.c \

SRCSS =\
	_dup.s \
	_pipe.s \

OBJ = ${SRCS:.c=.o}
OBJS = ${SRCSS:.s=.o}

CFLAGS += -I../internal -D_PLAN9_SOURCE

.PHONY: clean all

all: clean $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1
	$(CC) $(CFLAGS) -c $(SRCSS) || exit 1

$(TARGET): $(OBJ) $(OBJS)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)
