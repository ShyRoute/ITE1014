#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAFE_FREE(ptr) \
	if (ptr) { \
		free(ptr); \
		ptr = 0; \
	}

const int NUM_SIZE = 6;
const int PRIZES[5] = { 2'000'000'000, 100'000'000, 2'000'000, 50'000, 5'000 };

int compare(const void *lhs, const void *rhs) {
	int A = *(int *)lhs;
	int B = *(int *)rhs;

	if (A < B) return -1;
	else if (A > B) return 1;
	else return 0;
}

void printMenu(void);

void printArray(int *arr, int len);
int *newTicket(void);
int *generateNumbers(int N);
int getRank(int *win, int *ticket);

int main(int argc, char **argv) {
	int totalTickets = 0;
	unsigned long long earned = 0;
	int **tickets = (int **)malloc(0);
	int *winTicket = generateNumbers(NUM_SIZE + 1);
	int choice = -1;

	qsort(winTicket, NUM_SIZE, sizeof(int), compare);

	srand(time(NULL));

	while (1) {
		printMenu();
		char tmp[256];
		scanf(" %[^\n]s", tmp);

		choice = atoi(tmp);

		if (choice == 0 && tmp[0] == '0') {
			break;

		} else if (choice == 1) {
			int numTickets;
			printf("How many lines will you buy? : ");
			scanf(" %d", &numTickets);

			for (register int i = 0; i < numTickets; ++i) {
				++totalTickets;
				tickets = (int **)realloc(tickets, totalTickets * sizeof(int *));

				tickets[totalTickets - 1] = newTicket();

				printArray(tickets[totalTickets - 1], NUM_SIZE);

				int rank = getRank(winTicket, tickets[totalTickets - 1]);

				if (rank) {
					earned += PRIZES[rank - 1];
					printf(" rank: %d", rank);
				}

				putchar('\n');
			}
		} else if (choice == 2) {
			printf("You bought %d tickets, and the total cost is %d won\n", totalTickets, totalTickets * 1000);
		} else if (choice == 3) {
			int wins = 0;

			for (int i = 0; i < totalTickets; ++i) {
				int rank;

				if ((rank = getRank(winTicket, tickets[i]))) {
					printArray(tickets[i], 6);
					printf(" rank: %d\n", rank);
					++wins;
				}
			}

			printf("You wins %d time(s) and earned %llu won\n", wins, earned);
		} else if (choice == 4) {
			char ans[256];
			printf("Are you sure? (y or n) : ");
			scanf(" %[^\n]s", ans);

			if (strcmp(ans, "y") == 0) {
				int n = 0, rank = 99;
				unsigned long long tmpEarned = 0;

				for (; rank > 4 || rank == 0; ++n) {
					++totalTickets;
					tickets = (int **)realloc(tickets, totalTickets * sizeof(int *));

					tickets[totalTickets - 1] = newTicket();
					rank = getRank(winTicket, tickets[totalTickets - 1]);

					rank && (earned += PRIZES[rank - 1]) && (tmpEarned += PRIZES[rank - 1]);
				}

				printf("total cost is %d won, and you earned %llu won\n", n * 1000, tmpEarned);
			}
		} else {
			printf("<ERROR> Wrong answer\n");
		}
	}

	SAFE_FREE(winTicket);

	for (int i = 0; i < totalTickets; ++i)
		SAFE_FREE(tickets[i]);

	SAFE_FREE(tickets);
}

void printMenu(void) {
	printf(
		"----------- Lottery  Ticket -----------\n"
		"---------------------------------------\n"
		"1. Buy tickets\n"
		"2. Spent money\n"
		"3. Earned money\n"
		"4. Buy until I get 4th or higher prize\n"
		"0. exit\n"
		"---------------------------------------\n"
		">>> ");
}

void printArray(int *arr, int len) {
	printf("[");

	for (register int i = 0; i < len; ++i) {
		i && printf(" ");

		printf("%d", arr[i]);
	}

	printf("]");
}

int *newTicket(void) {
	int *ret = generateNumbers(NUM_SIZE);

	qsort(ret, NUM_SIZE, sizeof(int), compare);
	return ret;
}

int *generateNumbers(int N) {
	char numbers[45] = { 0 };
	int *ret = (int *)malloc(N * sizeof(int));

	for (register int i = 0; i < N; ++i) {
		int num;

		do {
			num = rand() % 45;
		} while (numbers[num]);

		numbers[num] = 1;

		ret[i] = num + 1;
	}

	return ret;
}

int getRank(int *win, int *ticket) {
	int winCnt = 0, bonusCnt = 0;

	for (int i = 0; i < NUM_SIZE + 1; ++i)
		for (int j = 0; j < NUM_SIZE; ++j)
			(ticket[j] == win[i]) && ((i == NUM_SIZE) ? (++bonusCnt) : (++winCnt));

	if (winCnt == 6) return 1;
	else if (winCnt == 5 && bonusCnt == 1) return 2;
	else if (winCnt == 5 && bonusCnt == 0) return 3;
	else if (winCnt == 4) return 4;
	else if (winCnt == 3) return 5;
	else return 0;
}
