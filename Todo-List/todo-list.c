#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 1024


void add() {
	char add_list[STRING_SIZE], added[STRING_SIZE];

	printf("\nEnter text:\n>>");
	fgets(add_list, STRING_SIZE, stdin);
	
	FILE *list = fopen("TodoList.txt", "a");
		
	if (list == NULL)
	{
		list = fopen("TodoList.txt", "w");
	}

	fprintf(list, "%s", add_list);
	printf("List added: \n%s", add_list);

	fclose(list);

	FILE *show_list = fopen("TodoList.txt", "r");

	fgets(added, sizeof(added), list);
	printf(" %s", added);

	fclose(show_list);
}

void del() {
	int delete_list;
}


void buffer_clear() {
	int c;
	while((c = getchar()) != '\n' && c != EOF) {};
}


int main() {
	int answer;

	printf("===== Todo List =====\n");
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