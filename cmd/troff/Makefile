include $(APEX)/$(OS).inc

TARGET = troff
SRCS = $(wildcard *.c)
OBJ = ${SRCS:.c=.o}

TMACDIR='"sys/lib/tmac/tmac."'
FONTDIR='"sys/lib/troff/font"'
NTERMDIR='"sys/lib/troff/term/tab."'
TEXHYPHENS='"/sys/lib/texmf/tex/generic/hyphen/hyphen.tex"'
DWBHOME='"/"'
TDEVNAME='"utf"'
NDEVNAME='"utf"'

CFLAGS += -I. -DHAVE_CONFIG_H -D_BSD_SOURCE -DTMACDIR=$(TMACDIR) -DTDEVNAME=$(TDEVNAME) -DFONTDIR=$(FONTDIR) -DNTERMDIR=$(NTERMDIR) -DTEXHYPHENS=$(TEXHYPHENS) -DDWBHOME=$(DWBHOME) -DNDEVNAME=$(NDEVNAME)

.PHONY: all clean

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(CC) -nostdlib -o $(TARGET) $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ)
