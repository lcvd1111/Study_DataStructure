vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

EXE: object_main object_sub01 object_sub02
	$(CC) $^ -o $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

object_%:
	cp $< $@

object_main: main.o

object_sub01: mylib.o

object_sub02: test.o

include Dependency.mk

Dependency.mk: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* *.mk

cleanall:
	rm EXE *.o object_* *.mk
