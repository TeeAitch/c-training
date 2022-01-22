CC=clang  
CFLAGS= -g -Wall -std=gnu99

Target = main 

all: $(Target)

$(Target): main.c 
	$(CC) $(CFLAGS) -o $(Target) main.c 

clean: 
	$(RM) $(Target)