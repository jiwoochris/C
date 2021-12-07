#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PLAYERS {
	int back_number;
	char name[25];
	int age;
	int a_matches;
	int goals;
	struct PLAYERS* next;
};

void create_node(struct PLAYERS* head, struct PLAYERS new_player) {
	struct PLAYERS* p = head->next, * prev = head;

	while (p) {
		if (new_player.back_number == p->back_number) {
			printf("Error : redundant back number");
			exit(1);
		}
		else if (new_player.back_number < p->back_number)
			break;
		else {
			prev = p;
			p = p->next;
		}
			
	}

	struct PLAYERS* players = (struct PLAYERS*)malloc(sizeof(struct PLAYERS));
	if (players == NULL) {
		printf("Error"); exit(1);
	}

	players->back_number = new_player.back_number;
	strcpy(players->name, new_player.name);
	players->age = new_player.age;
	players->a_matches = new_player.a_matches;
	players->goals = new_player.goals;

	players->next = p;
	prev->next = players;

}

void print_players(struct PLAYERS* head) {
	struct PLAYERS* p = head->next;

	while (p) {
		printf("%d %s %d %d %d\n", p->back_number, p->name, p->age, p->a_matches, p->goals);
		p = p->next;
	}
}

void search_players(struct PLAYERS* head) {
	struct PLAYERS* p = head->next;

	int min_age = p->age;
	int max_age = p->age;
	int min_goal = p->goals;
	int max_goal = p->goals;
	int min_a = p->a_matches;
	int max_a = p->a_matches;

	int min_age_i;
	int max_age_i;
	int min_goal_i;
	int max_goal_i;
	int min_a_i;
	int max_a_i;

	while (p) {
		if (p->age < min_age) {
			min_age = p->age;
			min_age_i = p->back_number;
		}

		if (p->age > max_age) {
			max_age = p->age;
			max_age_i = p->back_number;
		}

		if (p->goals < min_goal) {
			min_goal = p->goals;
			min_goal_i = p->back_number;
		}

		if (p->goals > max_goal) {
			max_goal = p->goals;
			max_goal_i = p->back_number;
		}

		if (p->a_matches < min_a) {
			min_a = p->a_matches;
			min_a_i = p->back_number;
		}

		if (p->a_matches > max_a) {
			max_a = p->a_matches;
			max_a_i = p->back_number;
		}

		p = p->next;
	}

	p = head->next;
	while (p) {
		printf("%d %s %d %d %d\n", p->back_number, p->name, p->age, p->a_matches, p->goals);
		p = p->next;
	}

}

int main() {

	struct PLAYERS* head = (struct PLAYERS*)malloc(sizeof(struct PLAYERS));
	if (head == NULL) {
		printf("Error"); exit(1);
	}
	head->next = NULL;

	struct PLAYERS test_set[7] = {
		{7, "Park Ji-Sung", 29, 94, 13},
		{10, "Park Chu-Young", 25, 47, 15},
		{1, "Jung Sung-Ryong", 25, 22, 0},
		{12, "Lee Young-Pyo", 33, 119, 5},
		{17, "Lee Chung-Yong", 22, 27, 4},
		{22, "Cha Du-Ri", 30, 51, 4},
		{16, "Ki Sung-Yueng", 21, 28, 4}
	};

	for (int i = 0; i < 7; i++) {
		create_node(head, test_set[i]);
	}

	print_players(head);


	return 0;
}