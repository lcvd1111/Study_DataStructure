vpath %.c ./src 
vpath %.c ./
vpath %.h ./include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_hashmap object_test
	$(CC) $^ -o $@

object_%:
	cp $< $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

object_main: main.o

object_hashmap: hashmap.o

object_test: test.o

include Dependency.mk

Dependency.mk: main.c hashmap.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* Dependency.mk

cleanall:
	rm EXE *.o object_* Dependency.mk
