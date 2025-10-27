#include <stdio.h>


void calculate() {
	int item, total;
	double price, totalPrice;

	printf("How many items?: ");
	scanf(" %d", &item);

	printf("Enter price: ");
	scanf(" %lf", &price);

	totalPrice += price;
	total += item;
}

int main() {
	char answer, exit;
	float firstPrice;
	printf("=== Cashier Management ===\n");

	printf("Enter program?\n");
	printf("Press \'Enter/Return\' to enter program\nPress any key to exit\n");
	printf("=Enter=   =Exit=\n");
	answer = getchar();

	if (answer == '\n')
	{
		printf("Total Price: %lf \n", firstPrice);

		do
		{
			start:
			calculate();

			printf("=Done(Enter)= =Exit(other key)= ");
			exit = getchar();

			if (exit != '\n')
			{
				goto start;
			}

		} while (answer == '\n');
		
	}

	printf("Exit Success\n");
	

	return 0;
}