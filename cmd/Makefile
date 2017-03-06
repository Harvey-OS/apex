DIRS=troff awk
BUILDDIRS=$(DIRS:%=build-%)
INSTALLDIRS=$(DIRS:%=install-%)
CLEANDIRS=$(DIRS:%=clean-%)

.PHONY: $(DIRS)

all: $(DIRS)

clean: $(DIRS)

install: $(DIRS)

$(DIRS):
	$(MAKE) -C $@ $(MFLAGS) $(MAKECMDGOALS)
