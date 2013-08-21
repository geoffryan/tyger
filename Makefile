MAKEFILE_IN = $(PWD)/Makefile.in
include $(MAKEFILE_IN)

CFLAGS ?= -Wall
CURL ?= curl
UNTAR ?= tar -xvf
CD ?= cd
RM ?= rm -f
OS ?= MacOSX10.6.8

LIBS = -lhdf5 -L$(HDF_HOME)/lib
LOCLIBS = cow/libcow.a

default: tyger

tyger: tyger.c tyger.h $(LOCLIBS)
	$(CC) $(CFLAGS) -o $@ $^ -I./cow/ $(LIBS)
	
cow/libcow.a: .FORCE
	$(MAKE) -C cow libcow.a MAKEFILE_IN=$(MAKEFILE_IN)
	
clean:
	$(MAKE) -C cow clean MAKEFILE_IN=$(MAKEFILE_IN)
	$(RM) tyger
	
.FORCE:

