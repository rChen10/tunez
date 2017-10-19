all: main.c list.h list.c
	gcc main.c -o tunez_test
run: all
	./tunez_test
	rm *.o *~ tunez_test -f
