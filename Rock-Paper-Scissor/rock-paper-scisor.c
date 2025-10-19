#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void game() {
	int player_Choice;
	int computer;
	int min = 1;
	int max = 3;

	printf("Chose your optiion! \n1. Rock 2.Paper 3.Scissor\n>>");
	scanf("%d", &player_Choice);
	printf("Computer is Choosing.....\n");
	computer = rand() % (max - min + 1) + min;
	printf("Compter choose %d", computer);

	if(player_Choice > computer || player_Choice == 1 && computer == 3) {
		printf("\n=== You Win! ===\n");
	} else if (computer == player_Choice) {
		printf("\n### DRAW ###\n");
	} else {
		printf("\n--- Computer Win ---\n");
	}
	
}



int main() {
	char answer;
	printf("===== Welcome to Rock-Paper-Scissor Game! =====\n");
	printf("Want to Play? Y/n\n>>");
	scanf("%c", &answer);
		
	if(answer == 'Y' || answer == 'y') {
		int i = 0;
		for (int i = 0; i < 1; ++i)
		{
			game();

			while(1) {
			    printf("Rematch? Y/n\n>>");
			    scanf("%c", &answer);
			    if (answer != 'n' || answer != 'N') {
			    	game();
			    }
			}
		}
	} else {
		printf("Thank you for playing!");
		exit(0);
	}


	return 0;
}
