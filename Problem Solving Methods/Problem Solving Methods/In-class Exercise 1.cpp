#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAR 1
#define BELL 2
#define LEMON 3
#define CHERRY 4
#define RMAX 4

void print_slot_result(int s) {
	switch (s){
	case BAR:
		printf("BAR\n");
		break;
	case BELL:
		printf("BELL\n");
		break;
	case LEMON:
		printf("LEMON\n");
		break;
	case CHERRY:
		printf("CHERRY\n");
		break;
	}
}

int main() {
	int slot1, slot2, slot3;
	char anykey;

	while (1) {
		printf("Welcome to JW Land\n");
		printf("Please pull the slot machine !!");

		scanf_s("%c", &anykey, 4);
		printf("\n");

		srand((unsigned int)time(NULL));

		slot1 = 1 + (int)rand() % RMAX;
		slot2 = 1 + (int)rand() % RMAX;
		slot3 = 1 + (int)rand() % RMAX;
		
		printf("First is "); print_slot_result(slot1);
		printf("Second is "); print_slot_result(slot2);
		printf("Third is "); print_slot_result(slot3);
		printf("\n");

		if (slot1 == slot2 && slot2 == slot3 && slot1 == CHERRY)
			printf("Congratulations On A JACKPOT");
		else if (slot1 == CHERRY || slot2 == CHERRY || slot3 == CHERRY)
			printf("Paid Out : One DIME");
		else if (slot1 == slot2 && slot2 == slot3)
			printf("Paid Out : One Nickel");
		else
			printf("Sorry. Better Luck Next Time");

		printf("\n\n");
	}
}