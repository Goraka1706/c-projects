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

	printf("\nTotal Price: %lf", totalPrice);
	printf("\nTotal Item: %d", total);
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

		int count = 1;
		for (int i = 0; i < count; ++i)
		{
			start:
			calculate();

			printf("\n=Done(Enter)=   =Add(other key)=\n>>");
			scanf(" %c", &exit);

			if (exit == 'Y' || exit == 'y')
			{
				goto end;
			} else {
				goto start;
			}
		}
	}

	end:
	printf("Exit Success\n");
	

	return 0;
}