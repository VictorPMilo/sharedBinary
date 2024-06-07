 
CC = gcc
CFLAGS = -std=c99 -Wall -g -I ./include  
LDFLAGS =  

 
check-syntax: src/binary_search_tree_int.c src/app-bst-int.c
	$(CC) $(CFLAGS) -c $^

app-bst-int: src/binary_search_tree_int.c src/app-bst-int.c
	$(CC) $(CFLAGS) -o $@ $^

run: app-bst-int
	./app-bst-int

valgrind: app-bst-int
	valgrind --leak-check=full ./app-bst-int

 
clean:
	rm -Rf *.o ./app-bst-int ./tests-bst

 