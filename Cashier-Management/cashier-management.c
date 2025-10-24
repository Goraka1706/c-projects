#include <stdio.h>

int main() {
	char item, answer, exit;
	int itemCount, totalItem;
	double price, total;
	price = 0.0;
	printf("=== Cashier Management ===\n");

	printf("Enter program?\n");
	printf("Press \'Enter/Return\' to enter program\nPress any key to exit\n");
	printf("=Enter=   =Exit=\n");
	//scanf(" %c", &answer);
	answer = getchar();

	if (answer == '\n')
	{
		//printf("Total Price: %lf.2 \n", price);
		itemCount = 1;
		
		for (int i = 0; i < itemCount; ++i)
		{
			printf("\nEnter item count: ");
			scanf(" %d", &itemCount);
			printf("\nItem name: ");
			scanf(" %s", &item);
			printf("\nPrice: ");
			scanf("%lf", &price);

			totalItem += itemCount;
			total += price;

			printf("\nTotal item: %d \nTotal price: %lf", totalItem, total);

		}
		//printf("Success\n");
	} else {
		printf("Exit Success\n");
	}
	

	return 0;
}