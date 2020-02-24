#make file to Queue

TARGET= a
CC=gcc
CFLAGS= -g -pedantic -Wall -I../include
OBJS= heapTest.o heap.o vectorGeneric.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm
 
heap.o: heap.c $(INCLUDE_PATH)heap.h 
	$(CC) $(CFLAGS) -c heap.c

heapTest.o: heapTest.c $(INCLUDE_PATH)heap.h
	$(CC) $(CFLAGS) -c heapTest.c

vectorGeneric.o: vectorGeneric.c $(INCLUDE_PATH)vectorGeneric.h
	$(CC) $(CFLAGS) -c vectorGeneric.c
		
clean:
	rm -f $(TARGET) $(OBJS)
