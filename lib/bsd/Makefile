include ../../$(OS).inc

TARGET = libbsd.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I../ap/internal -D_BSD_EXTENSION -D_BSD_EXTENSION -D_PLAN9_SOURCE

.PHONY: clean all

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${LIB}/$@ $^

clean:
	rm -f $(OBJ)
