vpath %.cc ./src
vpath %.hh ./include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub01 object_sub02
	$(CXX) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.cc) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_sub01: mylib.o

object_sub02: test.o

include Dependency.mk

Dependency.mk: main.cc mylib.cc test.cc
	$(CXX) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONLY: clean cleanall
clean:
	rm EXE *.o object_* Dependency.mk

cleanall:
	rm EXE *.o object_* Dependency.mk
