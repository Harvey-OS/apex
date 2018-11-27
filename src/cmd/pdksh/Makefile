include $(APEX)/src/$(OS).inc

TARGET = pdksh
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}
CFLAGS += -I. -DHAVE_CONFIG_H -D_BSD_SOURCE

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(LD) -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) $(TARGET)
