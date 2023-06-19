vpath %.c src
vpath %.h include

INCLUDE_MY_DIRS = ./include/

%.o:
	$(COMPILE.c) $< -I $(INCLUDE_MY_DIRS) $(OUTPUT_OPTION)

EXE: object_main.o object_sub01.o object_sub02.o
	$(CC) $^ $(OUTPUT_OPTION)

object_main.o: main.c mylib.h 
object_main.o: test.h

object_sub01.o: mylib.c mylib.h

object_sub02.o: test.c mylib.h test.h

.PHONY: clean
clean:
	rm EXE *.o

.PHONY: cleanall
cleanall:
	rm EXE *.o
