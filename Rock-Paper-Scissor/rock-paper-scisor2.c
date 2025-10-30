#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This rock-paper-scissor game code use loop flag to return to main menu, instead of goto statement. The other line are the same as version 1
void game() {
	int player_Choice;
	int computer;
	int min = 1, max = 3;

	printf("Chose your optiion! \n1. Rock 2.Paper 3.Scissor\n>>");
	scanf(" %d", &player_Choice);
	printf("Computer is Choosing.....");
	computer = rand() % (max - min + 1) + min;	
	printf("\nComputer choose %d", computer);

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
	int repeat = 1;
	//start:
	
	while(repeat) {
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
		//goto start;
		} else {
			printf("Thank you for playing!");
			break;
		}
		switch(answer){
		case 'n' | 'N':
			continue;
		}
	}

	return 0;
}
