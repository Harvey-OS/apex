include $(OS).inc

DIRS=lib

all:
	mkdir -p $(APEXLIB)
	@cd $(DIRS) && $(MAKE)
	@echo "Done!"

# we clone into /tmp/harvey instead of . to make sure a HARVEY path that
# is out of tree will work.
travis:
	git clone https://github.com/Harvey-OS/harvey /tmp/harvey
	(cd /tmp/harvey && bash ./bootstrap.sh && ./util/build sys/src/libc/libc.json)
	mkdir -p $(APEXLIB)
	@cd $(DIRS) && $(MAKE)
	@cd cmd/pdksh && $(MAKE)
	@echo "Done!"
