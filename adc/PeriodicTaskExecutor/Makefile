#make file to Queue

TARGET= a
CC=gcc
CFLAGS= -g -pedantic -Wall -I../include
OBJS= PeriodicTaskExecutor_test.o PeriodicTaskExecutor.o task.o myTime.o heap.o vectorGeneric.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm
 
PeriodicTaskExecutor.o: PeriodicTaskExecutor.c $(INCLUDE_PATH)PeriodicTaskExecutor.h $(INCLUDE_PATH)heap.h $(INCLUDE_PATH)vectorGeneric.h $(INCLUDE_PATH)task.h 
	$(CC) $(CFLAGS) -c PeriodicTaskExecutor.c

PeriodicTaskExecutor_test.o: PeriodicTaskExecutor_test.c $(INCLUDE_PATH)PeriodicTaskExecutor.h $(INCLUDE_PATH)heap.h $(INCLUDE_PATH)vectorGeneric.h $(INCLUDE_PATH)task.h 
	$(CC) $(CFLAGS) -c PeriodicTaskExecutor_test.c

task.o: task.c $(INCLUDE_PATH)task.h $(INCLUDE_PATH)PeriodicTaskExecutor.h
	$(CC) $(CFLAGS) -c task.c

myTime.o: myTime.c $(INCLUDE_PATH)myTime.h $(INCLUDE_PATH)PeriodicTaskExecutor.h
	$(CC) $(CFLAGS) -c myTime.c
	
heap.o: heap.c $(INCLUDE_PATH)heap.h
	$(CC) $(CFLAGS) -c heap.c

vectorGeneric.o: vectorGeneric.c $(INCLUDE_PATH)vectorGeneric.h
	$(CC) $(CFLAGS) -c vectorGeneric.c
		
clean:
	rm -f $(TARGET) $(OBJS)
