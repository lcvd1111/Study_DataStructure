vpath %.c src
vpath %.h include

EXE: main.o mylib.o
	gcc $^ -o $@

main.o: main.c mylib.h
	gcc -c $< -o $@

mylib.o: mylib.c mylib.h
	gcc -c $< -o $@

.PHONY: celanall clean
cleanall:
	rm EXE *.o

clean:
	rm EXE *.o
