vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

%.o:
	$(CC) -c $< -I $(INCLUDE_MY_DIRS) -o $@

EXE: main.o test.o mylib.o
	$(CC) $^ -o $@

main.o: main.c mylib.h test.h

test.o: test.c test.h mylib.h

mylib.o: mylib.c mylib.h

.PHONY: clean
clean:
	rm -rf EXE *.o

.PHONY: cleanall
cleanall:
	rm -rf EXE *.o
