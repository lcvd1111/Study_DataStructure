vpath %.c ./src
vpath %.h ./include

INCLUDE_MY_DIRS = "./include"

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: object_main object_sub01 object_sub02
	$(CC) $^ -o $@

object_main: main.o
	cp $< $@

object_sub01: mylib.o
	cp $< $@

object_sub02: test.o
	cp $< $@

include dependency.mk

dependency.mk: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanll
clean:
	rm -rf EXE *.o object_* dependency.mk

cleanall:
	rm -rf EXE *.o object_* dependency.mk
