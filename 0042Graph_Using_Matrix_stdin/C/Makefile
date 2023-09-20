vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

EXE: main.o
	$(CC) $< -o $@

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

include Dependency.mk

Dependency.mk: main.c
	$(CC) -M $< -I $(INCLUDE_MY_DIRS) > $@

.PHONY: clean cleanall
clean:
	rm EXE *.o Dependency.mk

cleanall:
	rm EXE *.o Dependency.mk
