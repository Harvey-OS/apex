include $(APEX)/$(OS).inc

TARGET = libap.a
SRCS =\
	notetramp.c \

SRC =\
	sigsetjmp.s \

OBJS = ${SRC:.s=.o}
OBJ = ${SRCS:.c=.o}

CFLAGS += -I../internal -D_PLAN9_SOURCE -D_POSIX_SOURCE

.PHONY: all clean

all: $(TARGET) clean

%.o:
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1
	$(CC) $(CFLAGS) -c $(SRC) || exit 1

$(TARGET): $(OBJ) $(OBJS)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f *.o
