
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

.PHONY: all

all: libap.a

%.o: %.c
	$(CC) $(CFLAGS) $(SRCS)

libap.a: $(OBJ)
	ar -rcs ${LIB}/libap.a $(OBJ)

clean:
	rm *.o