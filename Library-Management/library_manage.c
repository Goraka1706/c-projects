#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

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

	printf("Enter book author:\n>>");
	fgets(book.author, sizeof(book.author), stdin);
	book.author[strcspn(book.author, "\n\r")] = '\0';

	printf("Enter book date:\n>>");
	fgets(book.date, sizeof(book.date), stdin);
	book.date[strcspn(book.date, "\n\r")] = '\0';

	printf("Enter book price:\n>>");
	fgets(book.price, sizeof(book.price), stdin);
	book.price[strcspn(book.price, "\n\r")] = '\0';


	cJSON *root = cJSON_CreateObject();
	cJSON_AddStringToObject(root, "name", book.name);
	cJSON_AddStringToObject(root, "author", book.author);
	cJSON_AddStringToObject(root, "date", book.date);
	cJSON_AddStringToObject(root, "price", book.price);

	FILE *addBook = fopen("bookData.json", "a");
	
	if (addBook == NULL)
	{
		addBook = fopen("bookData.json", "w");
		return;
	}

	char *str = cJSON_Print(root);
	fprintf(addBook, "%s\n", str);

	printf("Book successfully added\n");

	fclose(addBook);
	cJSON_Delete(root);
}


//linear search (masih belum jadi)
void searchBook()
{
	char search[SIZE];

	printf("Search >> ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n\r")] = '\0';

	FILE *list = fopen("bookData.json", "r");

	if (list == NULL)
	{
		printf("No data yet\n");
		return;
	}

	fseek(list, 0, SEEK_END);
	long size = ftell(list);
	
	fseek(list, 0, SEEK_SET);
	
	char *data = malloc(size);
	fread(data, 1, size, list);
	data[size] = '\0';
	fclose(list);

	cJSON *string = cJSON_Parse(data);
	if (!string)
	{
		printf("Error parsing data\n");
		free(data);
		return;
	}

	cJSON *item = cJSON_GetObjectItem(string, search);
	if (item != NULL)
	{
		char *str = cJSON_Print(item);
		printf("%s\n", str);
		free(str);
	}

	cJSON_Delete(string);
	free(data);
}


void deleteBook()
{

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
