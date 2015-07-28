
DIRS= ap bsd

all:
	@for a in $(DIRS); do \
		if [ -d $$a ]; then \
			echo "Making $$a"; \
			cd $$a && $(MAKE); \
		fi; \
	done;
	@echo "Done!"