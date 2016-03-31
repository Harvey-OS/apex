include $(APEX)/$(OS).inc

TARGET = apextest
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I. -DHAVE_CONFIG_H -D_BSD_SOURCE

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(CC) --verbose -nostdlib -o $(TARGET) $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lbsd -lap -lc

clean:
	rm -f $(OBJ)
