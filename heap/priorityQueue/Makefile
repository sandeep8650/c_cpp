priority_queue: priority_queue.o insert.o increase_key.o max.o pop_max.o print_heap.o max_heapify.o
	gcc $(CFLAGS) -o priority_queue priority_queue.o insert.o increase_key.o max.o pop_max.o print_heap.o max_heapify.o
	
priority_queue.o: priority_queue.c priority_queue.h
	gcc -c priority_queue.c
	
	
insert.o: insert.c priority_queue.h
	gcc -c insert.c
	

increase_key.o: increase_key.c priority_queue.h
	gcc -c increase_key.c
	
	
max.o: max.c priority_queue.h
	gcc -c max.c
	
	
pop_max.o: pop_max.c priority_queue.h
	gcc -c pop_max.c
	
	
print_heap.o: print_heap.c priority_queue.h
	gcc -c print_heap.c
	
	
max_heapify.o: max_heapify.c priority_queue.h
	gcc -c max_heapify.c
	
	
clean: 
	rm -f *.o priority_queue
