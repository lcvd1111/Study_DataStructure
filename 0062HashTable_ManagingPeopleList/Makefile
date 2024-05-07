vpath %c ./src
vpath %c ./
vpath %h ./include

INCLUDE_MY_DIRS=./include

EXE: object_main object_interface object_list object_hashmap object_test
	$(CC) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.cc) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_interface: interface.o

object_list: list.o

object_hashmap: hashmap.o

object_test: test.o

include Dependency.mk

Dependency.mk: main.c interface.c list.c hashmap.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* Dependency.mk

cleanall:
	rm EXE *.o object_* Dependency.mk
