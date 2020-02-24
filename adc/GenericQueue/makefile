#make file to Queue

TARGET= a
CC=gcc
CFLAGS= -g -ansi -pedantic -Wall -I../include -I../../../DS/include
OBJS= queue.o queue_test.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

queue.o: queue.c $(INCLUDE_PATH)GenericQueue.h
	$(CC) $(CFLAGS) -c queue.c
	
queue_test.o: queue_test.c $(INCLUDE_PATH)GenericQueue.h
	$(CC) $(CFLAGS) -c queue_test.c
		
clean:
	rm -f $(TARGET) $(OBJS)
