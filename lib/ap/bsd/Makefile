include $(APEX)/$(OS).inc

TARGET = libapex.a
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I../internal -D_BSD_EXTENSION -D_BSD_EXTENSION -D_PLAN9_SOURCE

.PHONY: clean all

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f $(OBJ)
