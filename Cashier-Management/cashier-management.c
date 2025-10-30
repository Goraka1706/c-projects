#include <stdio.h>


int item, total;
double price, totalPrice, itemPrice;

void calculate() {
	printf("How many items?: ");
	scanf(" %d", &item);

	printf("Enter price per item: ");
	scanf(" %lf", &itemPrice);

	price = itemPrice * item;
	totalPrice += price;
	total += item;

	printf("\nTotal Price: %.2lf", totalPrice);
	printf("\nTotal Item: %d", total);
}

void clear_buffer() {
	while(getchar() != '\n');
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
		printf("Total Price: %.1lf \n", firstPrice);

		do{
			//start:
			calculate();

			printf("\n=Done(Enter)=   =Add(other key)=\n>>");
			//scanf(" %c", &exit);
			clear_buffer();

			answer = getchar();
			if(answer == '\n')
			{
				printf("\nTotal item: %d\nTotal price: %.2lf", total, totalPrice);
				break;
			}	
		} while(answer != '\n');	
	}

	return 0;
}