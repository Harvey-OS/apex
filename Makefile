include $(OS).inc

DIRS=lib

all:
	mkdir -p $(APEXLIB)
	@cd $(DIRS) && $(MAKE)
	@echo "Done!"

travis:
	mkdir -p $(APEXLIB)
	@cd $(DIRS) && $(MAKE)
	@echo "Done!"
