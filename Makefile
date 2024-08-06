CC = gcc
CFLAGS = -Wall -g

LDLIBS = 

SRC = dict1.c data.c

OBJ = $(SRC:.c=.o)
 

EXE = dict1

$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LDLIBS)

clean:
	rm -f $(OBJ) $(EXE)