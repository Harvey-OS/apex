
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

.PHONY: all

all: libap.a

OBJ:
	$(CC) $(CFLAGS)

libap.a: $(OBJ)
	ar -rcs ${LIB}/libap.a $(OBJ)

clean:
	rm *.o