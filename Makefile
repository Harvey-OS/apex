include $(OS).inc

all: lib cmd

dirs:
	mkdir -p $(APEXLIB)
	mkdir -p $(APEXBIN)

cmd: dirs lib
	$(MAKE) -C cmd
	$(MAKE) -C cmd install

lib: dirs
	@cd lib && $(MAKE)
	@echo "Done!"

# we clone into /tmp/harvey instead of . to make sure a HARVEY path that
# is out of tree will work.
travis:
	git clone https://github.com/Harvey-OS/harvey /tmp/harvey
	(cd /tmp/harvey && bash ./bootstrap.sh && ./util/build sys/src/libc/libc.json)
	mkdir -p $(APEXLIB)
	@cd lib && $(MAKE)
	@echo "Done!"
