#make file to Queue

TARGET= a
CC=gcc
CFLAGS= -g -ansi -pedantic -Wall -I../include -I../../../DS/include
OBJS= doublelinked.o doublelinked_test.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

queue.o: doublelinked.c $(INCLUDE_PATH)list.h
	$(CC) $(CFLAGS) -c doublelinked.c
	
queue_test.o: doublelinked_test.c $(INCLUDE_PATH)list.h
	$(CC) $(CFLAGS) -c doublelinked_test.c
		
clean:
	rm -f $(TARGET) $(OBJS)
