vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub01 object_sub02
	$(CC) $^ -o $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

object%:
	cp $< $@

object_main: main.o

object_sub01: mylib.o

object_sub02: test.o

Makefile_Dependency: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

include Makefile_Dependency

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* Makefile_Dependency

cleanall:
	rm EXE *.o object_* Makefile_Dependency
