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
	Book book;

	FILE *addBook = fopen("bookData.json", "a");
	
	if (addBook == NULL)
	{
		addBook = fopen("bookData.json", "w");
		return;
	}

	printf("Enter book name:\n>>");
	fgets(book.name, sizeof(book.name), stdin);

	printf("Enter book name:\n>>");
	fgets(book.author, sizeof(book.author), stdin);

	printf("Enter book name:\n>>");
	fgets(book.date, sizeof(book.date), stdin);

	printf("Enter book name:\n>>");
	fgets(book.price, sizeof(book.price), stdin);

	fprintf(addBook, "{\n\"Name\": \"%s\",\n\"Author\": \"%s\",\n\"Date\": \"%s\",\n\"Price\": \"%s\"}", book.name, book.author, book.date, book.price);

	printf("Book successfully added\n");

	fclose(addBook);
}


void searchBook()
{

}


void deleteBook()
{
	
}

int main()
{
	int answer;

	printf("\n===== Library Management =====\n");
	printf("=== Please select the number to choose action ===\n");
	printf("1. Add Book\n2. Search Book\n 3. Delete Book\n4. Exit\n>>");
	scanf("%d", &answer);

	buffer_clear();

	switch(answer)
	{
	case 1:
		addBook();
		break;
	case 2:
		searchBook();
		break;
	case 3:
		deleteBook();
		break;
	case 4:
		printf("Exit program.....\n");
		exit(0);
		break;
	default:
		printf("\nWrong choose. Please select the right one.\n\n", );
		break;
	}

	return 0;
}
