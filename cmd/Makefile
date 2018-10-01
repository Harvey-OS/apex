include $(APEX)/$(OS).inc

DIRS = troff awk sed pdksh
BUILDDIRS=$(DIRS:%=build-%)
INSTALLDIRS=$(DIRS:%=install-%)
CLEANDIRS=$(DIRS:%=clean-%)

NIDIR = ${HARVEY}/sys/include
NIOBJDIR = ${HARVEY}/${ARCH}/include
NCFLAGS += -O0 -static -mno-red-zone -ffreestanding -fno-builtin -fno-omit-frame-pointer -I$(NIDIR) -I$(NIOBJDIR)

PROGRAMS = expr uname kill basename dirname compress
MVANDCP = mv cp

.PHONY: $(DIRS) $(PROGRAMS)

all: $(DIRS) $(PROGRAMS) $(MVANDCP)

$(DIRS):
	$(MAKE) -C $@ $(MFLAGS) $(MAKECMDGOALS)

clean: $(DIRS)

install: $(DIRS)

$(PROGRAMS):
	$(CC) $(CFLAGS) -c $@.c
	$(LD) -static -nostdlib -z noseparated-code -z max-page-size=0x200000 -o $@ $(APEXLIB)/crt1.o $(APEXLIB)/crti.o $(APEXLIB)/crtn.o $@.o -L$(APEXLIB) -L$(HARVEYLIB) -lap -lc
	cp $@ $(APEXBIN)
	rm -f $@.o $@
$(MVANDCP):
	$(CC) $(NCFLAGS) -c $@.c
	$(LD) -static -nostdlib -e_main -z noseparated-code -z max-page-size=0x200000 -o $@ $@.o -L$(HARVEYLIB) -lc
	cp $@ $(APEXBIN)
	rm -f $@.o $@
