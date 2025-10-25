#include <stdio.h>

int main() {
	char item, answer, exit;
	int itemCount;
	double price, total;
	price = 0.0;
	printf("=== Cashier Management ===\n");

	printf("Enter program?\n");
	printf("Press \'Enter/Return\' to enter program\nPress any key to exit\n");
	printf("=Enter=   =Exit=\n");
	answer = getchar();

	if (answer == '\n')
	{
		printf("Total Price: %lf \n", price);

		itemCount = 1;
		
		start:
		for (int i = 0; i < itemCount; ++i)
		{
			printf("\nEnter item count: ");
			scanf(" %d", &itemCount);
			printf("\nItem name: ");
			scanf(" %s", &item);
			printf("\nPrice: ");
			scanf("%lf", &price);

			
			total += price;

			printf("\nTotal price: %lf", total);
			printf("\n=Done(Enter)=  =Add(other key)=\n>>");
			
			exit = getchar();
			
			if (exit != '\n')
			{
				goto start;
			}
		}
		
	}

	printf("Exit Success\n");
	

	return 0;
}