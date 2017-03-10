include $(APEX)/$(OS).inc

DIRS=troff awk
BUILDDIRS=$(DIRS:%=build-%)
INSTALLDIRS=$(DIRS:%=install-%)
CLEANDIRS=$(DIRS:%=clean-%)

EXPROBJ = expr.o
UNAMEOBJ = uname.o
KILLOBJ = kill.o
BASENAMEOBJ = basename.o
DIRNAMEOBJ = dirname.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean

all: $(DIRS) expr uname kill basename dirname clean

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean: $(DIRS)
	rm -f *.o expr uname kill basename dirname

install: $(DIRS)
	cp expr $(APEXBIN)
	cp uname $(APEXBIN)
	cp kill $(APEXBIN)
	cp basename $(APEXBIN)
	cp dirname $(APEXBIN)

$(DIRS):
	$(MAKE) -C $@ $(MFLAGS) $(MAKECMDGOALS)

expr: $(EXPROBJ)
	$(LD) -static -nostdlib -o expr $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(EXPROBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

uname: $(UNAMEOBJ)
	$(LD) -static -nostdlib -o uname $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(UNAMEOBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

kill: $(KILLOBJ)
	$(LD) -static -nostdlib -o kill $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(KILLOBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

basename: $(BASENAMEOBJ)
	$(LD) -static -nostdlib -o basename $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(BASENAMEOBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

dirname: $(DIRNAMEOBJ)
	$(LD) -static -nostdlib -o dirname $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(DIRNAMEOBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc
