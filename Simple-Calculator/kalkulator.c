#include <stdio.h>


int main() {
	double n1, n2;
	char op;
	
	printf("========== Simple Calculator ==========\n");
	
	printf("Operators: +, -, x, /\n");
	
	printf("Enter Operation: ");
	scanf("%c", &op);

	printf("Enter First Number: ");
	scanf("%lf", &n1);

	printf("Enter Second Number: ");
	scanf("%lf", &n2);

	switch(op)
	{
		case '+':
			printf("Result: %.2lf\n", n1 + n2);
			break;
		case '-':
			printf("Result: %.2lf\n", n1 - n2);
			break;
		case 'x':
			printf("Result: %.2lf\n", n1 * n2);
			break;
		case '/':
			printf("Result: %.2lf\n", n1 / n2);
			break;
		default:
			printf("Unmatched Operator\n");

	}

	return 0;
}
