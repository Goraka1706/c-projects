#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("Enter book name:\n>>");
	fgets(book.name, sizeof(book.name), stdin);
	book.name[strcspn(book.name, "\n\r")] = '\0';

	printf("Enter author name:\n>>");
	fgets(book.author, sizeof(book.author), stdin);
	book.author[strcspn(book.author, "\n\r")] = '\0';

	printf("Enter date:\n>>");
	fgets(book.date, sizeof(book.date), stdin);
	book.date[strcspn(book.date, "\n\r")] = '\0';

	printf("Enter price:\n>>");
	fgets(book.price, sizeof(book.price), stdin);
	book.price[strcspn(book.price, "\n\r")] = '\0';

	FILE *addBook = fopen("bookData.csv", "a");

	if (!addBook)
	{
		addBook = fopen("bookData.csv", "w");
		return;
	}

	fprintf(addBook, "%s, %s, %s, %s\n", book.name, book.author, book.date, book.price);
	printf("Book successfully added\n");
	
	fclose(addBook);
}


//using linear search
void searchBook()
{
	char books[SIZE];
	char keyword[SIZE];

	printf("Search\n>>");
	fgets(keyword, sizeof(keyword), stdin);
	keyword[strcspn(keyword, "\n\r")] = '\0';

	FILE *list = fopen("bookData.csv", "r");

	if (!list)
	{
		printf("No book yet. Add some.\n");
		return;
	}

	while(fgets(books, sizeof(books), list))
	{
		if (strstr(books, keyword) != NULL)
		{
		  	printf("%s\n", books);
		 	return; 	
		}
	}

	if (strstr(books, keyword) == NULL)
	{
		printf("no such file in database\n");
		return;
	} //i don't put this statement in while loop, 'cause it will broke the linear function

	fclose(list);
}


void deleteBook()
{
	char del[SIZE];
	char key[SIZE];

	printf("Enter the book name to delete\n>>");
	fgets(key, sizeof(key), stdin);
	key[strcspn(key, "\n\r")] = '\0';

	FILE *bookData = fopen("bookData.csv", "r");
	FILE *temp = fopen("temp.csv", "w");
	
	if (!bookData || !temp)
	{
		printf("No data yet.\n");
		return;
	}

	while(fgets(del, sizeof(del), bookData)) {
	    if (strstr(del, key) == NULL)
	    {
	    	fputs(del, temp);
	    	del[strcspn(del, "\n\r")] = '\0';
	    }
	}

	fclose(bookData);
	fclose(temp);
	rename("temp.csv", "bookData.csv");
	printf("file deleted\n");
}


int main()
{
	int answer, repeat = 1;

	while(repeat) {
	    
		printf("\n===== Library Management =====\n");
		printf("=== Please select the number to choose action ===\n");
		printf("1. Add Book\n2. Search Book\n3. Delete Book\n4. Exit\n>>");
		scanf("%d", &answer);

		buffer_clear();

		if (answer == 1)
		{
			add();
		}
		else if (answer == 2)
		{
			searchBook();
		}
		else if (answer == 3)
		{
			deleteBook();
		}
		else if (answer == 4)
		{
			printf("Exit program....\n");
			exit(0);
		}
		else
		{
			printf("You choosing the wrong option! Please choose the correct one.\n");
		}
	}

	return 0;
}
