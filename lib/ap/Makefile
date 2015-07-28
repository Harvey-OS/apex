
DIRS=gen math plan9 posix stdio

.PHONY: all

all:
	@for a in $(DIRS); do \
		if [ -d $$a ]; then \
			echo "Making $$a"; \
			$(MAKE) -C $$a || exit 1; \
		fi; \
	done;
	@echo "Done!"
