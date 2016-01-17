
TARGET = libap.a
DIRS = amd64 crt gen locale math multibyte plan9 posix stdio stdlib string

.PHONY: all

all: $(TARGET) $(DIRS)

$(TARGET):
	cd amd64; $(MAKE) $(MFLAGS)
	cd crt; $(MAKE) $(MFLAGS)
	cd gen; $(MAKE) $(MFLAGS)
	cd locale; $(MAKE) $(MFLAGS)
	cd math; $(MAKE) $(MFLAGS)
	cd multibyte; $(MAKE) $(MFLAGS)
	cd plan9; $(MAKE) $(MFLAGS)
	cd posix; $(MAKE) $(MFLAGS)
	cd stdio; $(MAKE) $(MFLAGS)
	cd stdlib; $(MAKE) $(MFLAGS)
	cd string; $(MAKE) $(MFLAGS)
