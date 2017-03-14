include $(APEX)/$(OS).inc

DIRS = troff awk sed pdksh
BUILDDIRS=$(DIRS:%=build-%)
INSTALLDIRS=$(DIRS:%=install-%)
CLEANDIRS=$(DIRS:%=clean-%)

PROGRAMS = expr uname kill basename dirname

.PHONY: $(DIRS) $(PROGRAMS)

all: $(DIRS) $(PROGRAMS)

$(DIRS):
	$(MAKE) -C $@ $(MFLAGS) $(MAKECMDGOALS)

clean: $(DIRS)

install: $(DIRS)

$(PROGRAMS):
	$(CC) $(CFLAGS) -c $@.c
	$(LD) -static -nostdlib -o $@ $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $@.o -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc
	cp $@ $(APEXBIN)
	rm -f $@.o $@
