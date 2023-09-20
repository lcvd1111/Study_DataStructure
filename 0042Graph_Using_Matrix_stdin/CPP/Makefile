vpath %.cc src
vpath %.hh include

INCLUDE_MY_DIRS = ./include

EXE: main.o
	$(CXX) $< -o $@

%.o:
	$(COMPILE.cc) $< -I $(INCLUDE_MY_DIRS) -o $@

include Dependency.mk

Dependency.mk: main.cc
	$(CXX) -M $^ -I $(INCLUDE_MY_DIRS) -o $@

.PHONY: clean cleanall
clean:
	rm EXE *.o Dependency.mk

cleanall:
	rm EXE *.o Dependency.mk
