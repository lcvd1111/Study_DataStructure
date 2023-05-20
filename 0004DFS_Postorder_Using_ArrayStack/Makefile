vpath %.c src
vpath %.h include

EXE: main.o mylib.o test.o
	$(CC) $^ -o $@

main.o: main.c mylib.h test.h
	$(COMPILE.c) $< -I ./include -o $@

mylib.o: mylib.c mylib.h
	$(COMPILE.c) $< -I ./include -o $@

test.o: test.c mylib.h test.h
	$(COMPILE.c) $< -I ./include -o $@

.PHONY: clean
clean:
	rm *.o EXE

.PHONY: cleanall
cleanall:
	rm *.o EXE
