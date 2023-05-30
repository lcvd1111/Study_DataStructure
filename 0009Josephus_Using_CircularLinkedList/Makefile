vpath %.c src
vpath %.h include 

INCLUDE_OPTION = -I
INCLUDE_MY_DIR = ./include

%.o:
	$(COMPILE.c) $< $(INCLUDE_OPTION) $(INCLUDE_MY_DIR) $(OUTPUT_OPTION)

EXE: object_main.o object_sub_mylib.o object_sub_test.o
	$(CC) $^ -o $@

object_main.o: main.c mylib.h test.h

object_sub_test.o: test.c test.h mylib.h

object_sub_mylib.o: mylib.c mylib.h

.PHONY: cleanall
cleanall:
	rm EXE *.o

.PHONY: clean
clean:
	rm EXE *.o
