include $(OS).inc

DIRS=lib

all:
	mkdir -p $(LIB)
	@cd $(DIRS) && $(MAKE)
	@echo "Done!"

travis:
	@echo "Done!"
