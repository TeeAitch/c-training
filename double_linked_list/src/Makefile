# the compiler:  
CC=clang 

# compiler flags: 
CFLAGS= -g -Wall 

# the build target executable: 
TARGET = main 

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c 

clean: 
	$(RM) $(TARGET)