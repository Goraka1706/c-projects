#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void game() {
	int player_Choice;
	int computer;
	int min = 1, max = 3;

	printf("Chose your optiion! \n1. Rock 2.Paper 3.Scissor\n>>");
	scanf(" %d", &player_Choice);
	printf("Computer is Choosing.....\n");
	computer = rand() % (max - min + 1) + min;
	

	if(
		(player_Choice == 1 && computer == 2) ||
		(player_Choice == 2 && computer == 3) ||
		(player_Choice == 3 && computer == 1)) {
		printf("\n=== You Win! ===\n");
	} else if (player_Choice == computer) {
		printf("\n### DRAW ###\n");
	} else {
		printf("\n--- Computer Win ---\n");
	}
	
}



int main() {
	char answer;

	srand(time(0));

	printf("===== Welcome to Rock-Paper-Scissor Game! =====\n");
	printf("Want to Play? Y/n\n>>");
	scanf(" %c", &answer);
		
	if(answer == 'Y' || answer == 'y') {
		do{
			game ();
				
			printf("Rematch? Y/n\n>>");
			scanf(" %c", &answer);

		} while(answer == 'Y' || answer == 'y');
	}
	
	printf("Thank you for playing!");


	return 0;
}
