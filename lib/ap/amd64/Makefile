include $(APEX)/$(OS).inc

TARGET = libap.a
SRCS =\
	notetramp.c \


OBJ = ${SRCS:.c=.o}

CFLAGS += -I../internal -D_PLAN9_SOURCE -D_POSIX_SOURCE

.PHONY: all clean

all: $(TARGET) clean

%.o:
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1

$(TARGET): $(OBJ)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f *.o
