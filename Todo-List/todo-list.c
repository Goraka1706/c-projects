#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 1024



void add() {
	char add_list[STRING_SIZE];
	printf("\nEnter text:\n>>");
	scanf("%s", &add_list);

	FILE *list = fopen("TodoList.txt", "r");
	if (list == NULL)
	{
		fopen("TodoList.txt", "w");
	} else {
		fopen("TodoList.txt", "a");
	}
	fprintf(add_list, "%s\n", "TodoList.txt");

	fclose("TodoList.txt");
}

void del() {
	int delete_list;
}


int main() {
	int answer;

	printf("===== Todo List =====\n");
	printf("=== Presss number to select ===\n1. Add\n2. Delete\n3. Exit\n>>");
	scanf("%s", &answer);

	if(answer == 1) {
		add();

	}
	else if(answer == 2) {
		/* code */
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