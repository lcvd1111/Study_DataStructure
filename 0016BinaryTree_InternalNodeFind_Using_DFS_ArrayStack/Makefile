vpath %.c ./src
vpath %.h ./include

INCLUDE_MY_DIRS = ./include

object_%:
	cp $< $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: object_main object_sub01 object_sub02
	$(CC) $^ -o $@

object_main: main.o

object_sub01: mylib.o

object_sub02: test.o

include dependency.mk

dependency.mk: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE object_* *.o dependency.mk 

cleanall:
	rm EXE object_* *.o dependency.mk 
