include $(APEX)/src/$(OS).inc

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

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(TARGET): $(OBJ)
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $(TARGET) $(APEXLIB)/crt0.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(OBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

install:
	cp $(TARGET) $(APEXBIN)

clean:
	rm -f $(OBJ) $(TARGET)
