vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

object_%:
	cp $< $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: object_main object_sub
	$(CC) $^ -o $@

object_main: main.o

object_sub: mylib.o

include Dependency.mk

Dependency.mk: main.c mylib.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o object_* Dependency.mk

clanall:
	rm EXE *.o object_* Dependency.mk
