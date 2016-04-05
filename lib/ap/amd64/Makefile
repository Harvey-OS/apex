include $(APEX)/$(OS).inc

TARGET = libap.a
SRCS =\
	notetramp.c \

SRCSS =\
	_chdir.s \
	_dup.s \
	_pipe.s \
	_stat.s \
	_fstat.s \
	_wstat.s \
	_open.s \
	_close.s \
	sigsetjmp.s \

OBJ = ${SRCS:.c=.o}
OBJS = ${SRCSS:.s=.o}

CFLAGS += -I../internal -D_PLAN9_SOURCE -D_POSIX_SOURCE

.PHONY: all clean

all: $(TARGET) clean

%.o:
	$(CC) $(CFLAGS) -c $(SRCS) || exit 1
	$(CC) $(CFLAGS) -c $(SRCSS) || exit 1

$(TARGET): $(OBJ) $(OBJS) $(OBJSS)
	ar rcs ${APEXLIB}/$@ $^

clean:
	rm -f *.o
