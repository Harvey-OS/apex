TARGET = libap.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

.PHONY: all

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm *.o
