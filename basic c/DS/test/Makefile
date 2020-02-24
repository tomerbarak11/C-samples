
CC = gcc
SOURCES = test.c funcs.c
TARGET  = test

CFLAGS = -ansi -pedantic -Wall -Wconversion -Wextra
CFLAGS+= -Werror
CFLAGS+= -std=c89

CPPFLAGS = -I../include

$(TARGET): $(SOURCES)

.PHONY: run
run: $(TARGET)
	@./$(TARGET)

.PHONY: clean
clean:
	@rm -f ./$(TARGET)

