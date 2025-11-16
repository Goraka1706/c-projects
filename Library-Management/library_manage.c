#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

typedef struct {
	char name[SIZE];
	char author[SIZE];
	char date[SIZE];
	char price[SIZE];
} Book;


void buffer_clear() 
{
	int c;
	while((c = getchar()) != '\n' && c != EOF) {};
}


void add()
{
	
}


int main()
{

	return 0;
}
