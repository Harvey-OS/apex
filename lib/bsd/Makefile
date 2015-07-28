TARGET = libbsd.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

BSDFLAGS= $(CFLAGS) -D_BSD_EXTENSION

.PHONY: all

all: $(TARGET)

%.o: %.c
	$(CC) $(BSDFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm *.o