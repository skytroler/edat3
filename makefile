CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
LIBS = -lm
EXES = p3_e1 p3_e2 p3_e1s p3_e2s
OBJS = maze.o p3_e1.o p3_e2.o queue.o list.o

all: $(EXES)

p3_e1: p3_e1.o maze.o elements.o sorted_queue.o libqueue.a
	$(CC) -o $@ $^ $(LIBS)

p3_e2: p3_e2.o maze.o elements.o sorted_queue.o libqueue.a search.o libstack.a
	$(CC) -o $@ $^ $(LIBS)

p3_e1s: p3_e1s.o maze.o elements.o sorted_queue.o queue.h queue_list.c list.o
	$(CC) -o $@ $^ $(LIBS)

p3_e2s: p3_e2s.o maze.o elements.o sorted_queue.o queue.h queue_list.c list.o search.o libstack.a
	$(CC) -o $@ $^ $(LIBS)

p3_e1.o: p3_e1.c elements.h maze.h
	$(CC) $(CFLAGS) -c $<

p3_e2.o: p3_e2.c elements.h maze.h search.h
	$(CC) $(CFLAGS) -c $<

p3_e1s.o: p3_e1s.c elements.h maze.h
	$(CC) $(CFLAGS) -c $<

p3_e2s.o: p3_e2s.c elements.h maze.h search.h
	$(CC) $(CFLAGS) -c $<

maze.o: maze.c maze.h types.h
	$(CC) $(CFLAGS) -c $<

search.o: search.c maze.h types.h queue.h
	$(CC) $(CFLAGS) -c $<

elements.o: elements.c maze.h types.h elements.h
	$(CC) $(CFLAGS) -c $<

sorted_queue.o: sorted_queue.c elements.h types.h sorted_queue.h queue.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c elements.h types.h list.h
	$(CC) $(CFLAGS) -c $<

clean_objects:
	@echo "Cleaning objects..." 
	@rm -f *.o $<

clean_program:
	@echo "Cleaning program..."
	@rm -f $(EXES)

clean: clean_objects clean_program