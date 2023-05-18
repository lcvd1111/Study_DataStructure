vpath %.c src
vpath %.h include

EXE: main.o mylib.o
	$(CC) $^ -o $@

main.o: main.c mylib.h #testprint_a
	$(CC) -c $< -o $@ -I./include/

mylib.o: mylib.c mylib.h #testprint_b
	$(CC) -c $< -o $@ -I./include/

.PHONY: clean
clean:
	@$(MAKE) cleanall

.PHONY: cleanll
cleanall:
	rm EXE *.o

.PHONY: showdir
showdir:
	ls -alih

.PHONY: testprint_a
testprint_a:
	@printf "This is a test string A.\n"

.PHONY: testprint_b
testprint_b:
	@printf "This is a test string B.\n"
