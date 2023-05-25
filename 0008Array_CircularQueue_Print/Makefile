vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: object_main.o object_sub1.o object_sub2.o
	$(CC) $^ -o $@ 

object_main.o: main.c mylib.h test.h

object_sub1.o: mylib.c mylib.h

object_sub2.o: test.c test.h mylib.h

.PHONLY: clean cleanall
clean:
	rm EXE *.o

cleanall:
	rm EXE *.o
