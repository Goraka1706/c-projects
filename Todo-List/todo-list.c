#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 1024


void buffer_clear() {
	int c;
	while((c = getchar()) != '\n' && c != EOF) {};
}


void showList() {
	char todoList[STRING_SIZE];

	FILE *listed = fopen("TodoList.txt","r");

	if (listed == NULL)
	{
		printf("No list yet. Add some.\n");
		return;
	}

	fgets(todoList, STRING_SIZE, listed);
	printf("%s\n", todoList);

	fclose(listed);
}


void add() {
	char add_list[STRING_SIZE], added[STRING_SIZE];

	printf("\nEnter text:\n>>");
	fgets(add_list, STRING_SIZE, stdin);
	
	FILE *list = fopen("TodoList.txt", "a");
		
	if (list == NULL)
	{
		list = fopen("TodoList.txt", "w");
		return;
	}

	fprintf(list, "%s", add_list);
	printf("List added:\n");

	fclose(list);

	FILE *show_list = fopen("TodoList.txt", "r");

	fgets(added, sizeof(added), show_list);
	printf(" %s", added);

	fclose(show_list);
}

void del() {
	char delete_list[STRING_SIZE];
	int lineToDelete, currentLine = 1;

	printf("Enter number ofline to delete\n>>");
	scanf("%d", &lineToDelete);

	buffer_clear();


	FILE *delFile = fopen("TodoList.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	if (delFile == NULL || temp == NULL)
	{
		printf("No list yet. Add some.");
		return;
	}

	while(fgets(delete_list, sizeof(delete_list), delFile)) {
		if (currentLine != lineToDelete)
		{
			fputs(delete_list, temp);
		}
		currentLine++;
	}
	
	
	fclose(delFile);
	fclose(temp);
	rename("temp.txt", "TodoList.txt");
}


int main() {
	int answer;
	
	printf("===== Todo List =====\n");

	showList();

	printf("=== Presss number to select ===\n1. Add\n2. Delete\n3. Exit\n>>");
	scanf("%d", &answer);

	buffer_clear();


	if(answer == 1) {
		add();
	}
	else if(answer == 2) {
		del();
	}
	else if (answer == 3)
	{
		printf("\nExit the program...");
		exit(1);
	}
	else{
		printf("\nWrong option! Please select the right one!\n");
	}

	return 0;
}