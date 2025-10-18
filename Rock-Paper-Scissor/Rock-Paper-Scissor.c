#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int game(int p, int co){
	printf("Option: \n 1. Rock\n 2. Paper\n 3. Scissor\n");
	printf("Enter your option: ");
	scanf("%d", &p);
	printf("Computer choosing...\n");
	srandom(time(0));
	co = (random() % 3) + 1;
	printf("Computer choose: %d\n", co);
	char ans;
	if(p < co) {
		printf("==Computer Win!==\n Rematch?\n -Y -n: ");
		scanf("%s", &ans);
		if(ans == 'Y' || ans == 'y') {
			return game(p, co);
		} else {
			return;
		}
	} else if(co == 1 && p == 3) {
		printf("==Computer Win!==\n Rematch?\n -Y -n: ");
		scanf("%s", &ans);
		if(ans == 'Y' || ans == 'y') {
			return game(p, co);
		} else {
			return;
		}
	} else if(p > co) {
		printf("==You Win!==\n Play again?\n -Y -n: ");
		scanf("%s", &ans);
		if(ans == 'Y' || ans == 'y') {
			return game(p, co);
		} else {
			return;
		}
	} else if(p == 1 && co == 3) {
		printf("==You Win!==\n Play again?\n -Y -n: ");
		scanf("%s", &ans);
		if(ans == 'Y' || ans == 'y') {
			return game(p, co);
		} else {
			return;
		}
	} else if(p == co) {
		printf("===DRAW!===\n Rematch?\n -Y -n: ");
		scanf("%s", &ans);
		if(ans == 'Y' || ans == 'y') {
			return game(p, co);
		} else {
			return;
		}
	} else {
		printf("=Error: Wrong Option=\n");
	}
}


int main() {
	int player;
	int computer;
	int menu;
	printf("====Welcome to Rock-Paper-Scissor Game====\n");
	printf("==Main Menu==\n 1. Play\n 2. Exit\n (Choose 1 or 2)\n >");
	scanf("%d", &menu);
	if(menu == 1) {
		game(player, computer);
	} else if(menu == 2) {
		exit(0);
	} else {
		printf("=Error: Wrong Option, choose 1 or 2");
	}
	return 0;
}
