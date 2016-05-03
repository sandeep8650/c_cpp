test: test.o quicksort.o mergesort.o countingsort.o is_sorted.o
	gcc $(CFLAGS) -o test test.o mergesort.o countingsort.o quicksort.o is_sorted.o
	
test.o: test.c sort.h
	gcc -c test.c
	
quicksort.o: quicksort.c
	gcc -c quicksort.c

mergesort.o: mergesort.c sort.h
	gcc -c mergesort.c

countingsort.o: countingsort.c sort.h
	gcc -c countingsort.c
	
is_sorted.o: is_sorted.c
	gcc -c is_sorted.c
	
random: random.o
	gcc $(CFLAGS) -o random random.o
	
random.o: random.c
	gcc -c random.c 
