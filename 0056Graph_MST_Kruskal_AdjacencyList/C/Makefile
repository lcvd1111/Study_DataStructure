vpath %.c ./src
vpath %.h ./include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub01 object_sub02 object_sub03 object_sub04
	$(CC) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_sub01: lib_unionfind.o

object_sub02: lib_heap.o

object_sub03: lib_graph.o

object_sub04: test.o

include Dependency.mk

Dependency.mk: main.c lib_unionfind.c lib_heap.c lib_graph.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm *.o object_* Dependency.mk EXE

cleanall:
	rm *.o object_* Dependency.mk EXE
