vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) $(OUTPUT_OPTION)

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
