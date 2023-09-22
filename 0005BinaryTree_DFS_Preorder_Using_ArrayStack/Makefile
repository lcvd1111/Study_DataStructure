vpath %.c src
vpath %.h include

COMPILE.c = $(CC) $(CFLAGS) $(INCLUDE) $(CPPFLAGS) $(TARGET_ARCH) -c
INCLUDE = -I $(INCLUDE_MY_DIRS)
INCLUDE_MY_DIRS = ./include

EXE: main.o mylib.o test.o
	$(CC) $^ -o $@

main.o: main.c mylib.h test.h

mylib.o: mylib.c mylib.h

test.o: test.c test.h mylib.h

.PHONY: clean cleanall
clean:
	rm EXE *.o

cleanall:
	rm EXE *.o
