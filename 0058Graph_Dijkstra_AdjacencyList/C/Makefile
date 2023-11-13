vpath %.c ./src
vpath %.h ./include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub01 object_sub02 object_sub03
	$(CC) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_sub01: lib_graph.o

object_sub02: lib_heap.o

object_sub03: test.o

include Dependency.mk

Dependency.mk: main.c lib_graph.c lib_heap.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE object_* *.o Dependency.mk

cleanall:
	rm EXE object_* *.o Dependency.mk
