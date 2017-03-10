include $(APEX)/$(OS).inc

DIRS=troff awk
BUILDDIRS=$(DIRS:%=build-%)
INSTALLDIRS=$(DIRS:%=install-%)
CLEANDIRS=$(DIRS:%=clean-%)

EXPROBJ = expr.o
UNAMEOBJ = uname.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean

all: $(DIRS) expr uname clean

clean: $(DIRS)
	rm -f *.o expr uname

install: $(DIRS)
	cp expr $(APEXBIN)
	cp uname $(APEXBIN)

$(DIRS):
	$(MAKE) -C $@ $(MFLAGS) $(MAKECMDGOALS)

expr: $(EXPROBJ)
	$(LD) -static -nostdlib -o expr $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(EXPROBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

uname: $(UNAMEOBJ)
	$(LD) -static -nostdlib -o uname $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $(UNAMEOBJ) -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc

%.o: %.c
	$(CC) $(CFLAGS) -c $<