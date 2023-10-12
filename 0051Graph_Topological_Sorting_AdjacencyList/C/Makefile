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

object_sub01: lib_queue.o 

object_sub02: lib_graph.o 

object_sub03: test.o

include Dependency.mk

Dependency.mk: main.c lib_queue.c lib_graph.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* Dependency.mk

cleanall:
	rm EXE *.o object_* Dependency.mk
