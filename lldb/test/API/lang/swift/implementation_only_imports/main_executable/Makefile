SWIFT_SOURCES=main.swift
SWIFTFLAGS_EXTRAS= -I$(shell pwd)
MODULENAME=main
LD_EXTRAS=-L$(shell pwd)

all: clean SomeLibrary.swiftmodule a.out

include Makefile.rules

SomeLibrary.swiftmodule: SomeLibrary.swift
	$(MAKE) BASENAME=$(shell basename $@ .swiftmodule) \
		SWIFTFLAGS_EXTRAS=$(LIBRARY_SWIFTFLAGS_EXTRAS) \
		VPATH=$(SRCDIR) -f $(SRCDIR)/../dylib.mk all

clean::
	rm -rf *.o *.dylib *.so *.dll *.dSYM *.swiftdoc *.swiftmodule *.swiftinterface

