include ../../$(OS).inc

TARGET = pdksh
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I. -DHAVE_CONFIG_H -D_BSD_SOURCE

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(CC) -nostdlib -o $(TARGET) $(LIB)/crt1.o $(LIB)/crti.o $(LIB)/crtn.o $(OBJ) -L$(LIB) -L../../$(ARCH)/lib -lbsd -lap -lc

clean:
	rm -f $(OBJ)
