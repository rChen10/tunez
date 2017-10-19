all: main.c list.h list.c library.h library.c
	gcc main.c list.c library.c -o tunez_test
run: all
	./tunez_test
	rm *.o *~ tunez_test -f
