
DIRS=gen math posix stdio

.PHONY: all

all:
	@for a in $(DIRS); do \
		if [ -d $$a ]; then \
			echo "Making $$a"; \
			cd $$a && $(MAKE); \
		fi; \
	done;
	@echo "Done!"
