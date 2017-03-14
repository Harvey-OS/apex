include $(APEX)/$(OS).inc

TARGET = sed
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

CFLAGS += -I.

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(LD) -static -nostdlib -o $(TARGET) $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) $(TARGET)
