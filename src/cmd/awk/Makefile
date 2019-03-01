include $(APEX)/src/$(OS).inc

TARGET = awk
SRCS = b.c main.c parse.c proctab.c tran.c lib.c run.c lex.c
OBJ = ${SRCS:.c=.o}

CFLAGS += -I. -DHAVE_CONFIG_H -D_BSD_SOURCE 

.PHONY: all clean

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

ytab.o:	awk.h proto.h awkgram.y
	$(YACC) -d awkgram.y
	mv y.tab.c ytab.c
	mv y.tab.h ytab.h
	$(CC) $(CFLAGS) -c ytab.c

proctab.c:	maketab
	./maketab >proctab.c

maketab:	ytab.h maketab.c
	$(CC) -I. maketab.c -o maketab

$(OBJ):	awk.h ytab.h proto.h

$(TARGET): ytab.o proctab.c $(OBJ)
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt0.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) ytab.o -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) ytab.o maketab proctab.c $(TARGET)
