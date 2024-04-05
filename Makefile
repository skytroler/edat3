CFLAGS = -Wall -ggdb
CC = gcc
IFLAGS = -I./
LDFLAGS = -L./
CLIB = -lstack -L.
LIBS = -lm

all: p2_e1 p2_e2 p2_e3

#######################################################

p2_e1: p2_e1.o maze.o stack.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e1.o: p2_e1.c stack.h maze.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

p2_e2: p2_e2.o stack.o maze.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e2.o: p2_e2.c stack.h maze.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

p2_e3: p2_e3.o stack.o maze.o search.o libstack.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p2_e3.o: p2_e3.c stack.h maze.h search.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

search.o: search.c search.h maze.h stack.h
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

#######################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f p2_e1
	@rm -f p2_e2
	@rm -f p2_e3

clean: clean_objects clean_program
