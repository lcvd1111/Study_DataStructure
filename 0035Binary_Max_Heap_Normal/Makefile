vpath %.cc src
vpath %.cpp src
vpath %.h include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub1 object_sub2
	$(CXX) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.cc) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_sub1: mylib.o

object_sub2: test.o

include Dependency.mk #Compile '.cc' c++ source code to object file.

Dependency.mk: main.cc mylib.cc test.cc #Creating 'Dependency.mk' file.
	$(CXX) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE object_* *.o *.mk

cleanall:
	rm EXE object_* *.o *.mk
