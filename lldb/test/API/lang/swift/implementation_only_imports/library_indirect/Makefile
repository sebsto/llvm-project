SWIFT_SOURCES=main.swift
SWIFTFLAGS_EXTRAS= -I.
LD_EXTRAS=-L.

all: clean SomeLibraryCore.swiftmodule SomeLibrary.swiftmodule a.out

include Makefile.rules

SomeLibraryCore.swiftmodule: SomeLibraryCore.swift
	$(MAKE) BASENAME=$(shell basename $@ .swiftmodule) \
		VPATH=$(SRCDIR) -f $(SRCDIR)/../dylib.mk all

SomeLibrary.swiftmodule: SomeLibrary.swift SomeLibraryCore.swiftmodule
	$(MAKE) BASENAME=$(shell basename $@ .swiftmodule) \
		VPATH=$(SRCDIR) -f $(SRCDIR)/../dylib.mk all

clean::
	rm -rf *.o *.dylib *.so *.dll *.dSYM *.swiftdoc *.swiftmodule *.swiftinterface

