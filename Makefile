CFLAGS = -Wall -pedantic -ansi -g
CC=gcc
CLIB=-L -lqueue
LIBS= -lm
EXES= p3_e1 
OBJS= maze.o p3_e1.o 




all: $(EXES)

#######################################################

p3_e1: p3_e1.o maze.o elements.o sorted_queue.o queue.h libqueue.a
	$(CC) -o $@ $^ 

p3_e1.o: p3_e1.c elements.h maze.h
	$(CC) $(CFLAGS) -c $<

maze.o: maze.c maze.h types.h
	$(CC) $(CFLAGS) -c $<

search.o: search.c maze.h types.h queue.h
	$(CC) $(CFLAGS) -c $<

elements.o: elements.c maze.h types.h elements.h
	$(CC) $(CFLAGS) -c $<

sorted_queue.o: sorted_queue.c elements.h types.h sorted_queue.h queue.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue_list.c elements.h types.h queue.h list.h
	$(CC) $(CFLAGS) -c $<

#######################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f $(EXES)
	
	
clean: clean_objects clean_program