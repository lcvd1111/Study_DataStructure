vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: obj_main obj_sub01 obj_sub02
	$(CC) $^ -o $@

obj_main: main.o
	cp $^ $@

obj_sub01: mylib.o
	cp $^ $@

obj_sub02: test.o
	cp $^ $@

dependant: main.c mylib.c test.c
	$(CC) -M $^ -I $(INCLUDE_MY_DIRS) > $@

include dependant

.PHONY: clean cleanall
clean:
	rm EXE *.o dependant obj_*

cleanall:
	rm EXE *.o dependant obj_*
