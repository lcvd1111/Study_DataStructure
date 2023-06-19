vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

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

include dependent.mk

dependent.mk: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

.PHONY: cleanall clean
cleanall:
	rm EXE *.o object_* dependent.mk

clean:
	rm EXE *.o object_* dependent.mk
