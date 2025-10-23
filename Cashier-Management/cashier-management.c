#include <stdio.h>

int main() {
	char item, answer;
	int itemCount;
	double price, total;

	printf("=== Cashier Management ===\n");

	do{
		printf("Item name: ");
		scanf(" %s", &item);
		printf("Amount: ");
		scanf(" %d", &itemCount);
		printf("Price: ");
		scanf(" %lf", &price);
		printf("=Done=\n=Again=");
		scanf(" %s", &answer);
		if (asnwer != "Again" || answer != "again") {
			goto end;
		}

	} while(1);
	end:



	return 0;
}