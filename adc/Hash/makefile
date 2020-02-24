#make file to Queue

TARGET= a
CC=gcc
CFLAGS= -g -ansi -pedantic -Wall -I../include
OBJS= doublelinked.o Hash.o Hash_test.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm
 
doublelinked.o: doublelinked.c $(INCLUDE_PATH)list.h $(INCLUDE_PATH)list_itr.h
	$(CC) $(CFLAGS) -c doublelinked.c
	
Hash_test.o: Hash_test.c $(INCLUDE_PATH)mu_test.h $(INCLUDE_PATH)Hash.h
	$(CC) $(CFLAGS) -c Hash_test.c
		
Hash.o: Hash.c $(INCLUDE_PATH)Hash.h $(INCLUDE_PATH)list.h $(INCLUDE_PATH)list_itr.h
	$(CC) $(CFLAGS) -c Hash.c
		
clean:
	rm -f $(TARGET) $(OBJS)
