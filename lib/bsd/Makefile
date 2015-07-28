SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

.PHONY: all

all: libbsd.a

OBJ:
	$(CC) $(CFLAGS)

libap.a: $(OBJ)
	ar -rcs ${LIB}/libbsd.a $(OBJ)

clean:
	rm *.o