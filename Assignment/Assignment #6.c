#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

void printMenu(void) {	// �޴��� ����ϴ� �Լ��Դϴ�. 
	printf("======== Lottery Ticket ========\n");
	printf("================================\n");
	printf("1. Buy tickets\n");
	printf("2. Spent money\n");
	printf("3. Earned money\n");
	printf("4. Buy until I get 4th or higher\n");
	printf("0. exit\n");
	printf("================================\n");
}

int *newTicket(void) {			// ���ο� �ζ� �� ���� ����� �Լ��Դϴ�. 
	int *newT;					// ���ο� �ζ� �� �� 
	int i, j, check = 0, temp = 0, number = 0;
	newT = (int *)malloc(6 * sizeof(int));		// ������, 6ĭ¥�� �迭�� ���� �Ҵ� 
	while(number < 6) {
		check = 0;				// �ߺ� ������ ���� 
		newT[number] = rand() % 45 + 1;			// 1 ~ 45 �� �ϳ��� ���� �̽��ϴ�. 
		for(i = 0; i < number; i++) {
			if(newT[number] == newT[i]) {
				check = 1;		// �ߺ��� ���ڰ� ������ check�� 1�� ����ϴ�. 
				break;
			}
		}
		if(check == 0) {		// �ߺ��� ���ڰ� ���� �� check�� 0�� �ǰ�, ���� ĭ���� �ѱ�ϴ�.
			number++;	 		// check�� 1�� ��(�ߺ��� �߻�)�� ���� ĭ���� �Ѿ�� �ʰ�, �ٽ� �̰� �˴ϴ�. 
		}
	}
	for(i = 0; i < 5; i++) {	// ���� ��Ʈ�� �������� ���� �Ͽ����ϴ�. 
		for(j = 0; j < 5 - i; j++) {
			if(newT[j] > newT[j + 1]) {
				temp = newT[j];
				newT[j] = newT[j + 1];
				newT[j + 1] = temp;
			}
		}
	}
	return newT;	// 6ĭ¥�� ������ �迭�� ��ȯ�մϴ�. 
}

int main(void) {
	int i, j, k, select, temp = 0, count = 0, n, prize = 0, number = 0;
	int target, moneyt, countt;
	char ask;
	unsigned long long money = 0;	// int�� �� �� 1���� �� �� ������ �����÷ο찡 �߻��ϰ� �˴ϴ�. 
	int rank[4] = { 0, };
	srand(time(NULL));
	int *win = NULL;				// ��÷ ��ȣ �迭�Դϴ�. 
	win = (int *)malloc(7 * sizeof(int));	// 6���� ��÷ ��ȣ�� 1���� ���ʽ� ��ȣ�� �̱� ������ 7ĭ�Դϴ�. 
	int check = 0;
	while(number < 7) {				// �迭�� �ߺ� ���� 7���� ���ڸ� �ֽ��ϴ�. ����� newTicket �Լ��� �����մϴ�. 
		check = 0;
		win[number] = rand() % 45 + 1;
		for(i = 0; i < number; i++) {
			if(win[number] == win[i]) {
				check = 1;
				break;
			}
		}
		if(check == 0) {
			number++;
		}
	}
	int **buylist = malloc(0);		// ������ �ζǸ� �����ϴ� 2���� �迭�Դϴ�. 
	while(1) {
		printMenu();
		printf(">>> ");
		scanf("%d", &select);
		switch(select) {			// �޴��� �Է¹ް�, �� case���� �ٸ� �޴��� �����մϴ�. 
			case 1:
				printf("How many lines will you buy? : ");
				scanf("%d", &n);	// �ζǸ� � �� �� �Է¹޽��ϴ�. 
				for(int i = 0; i < n; i++) {
					prize = 0;		// ��÷ Ȯ���� ���� �����Դϴ�. 
					count++;		// �ѹ� �� ������ ���� Ƚ���� 1�� �ø��ϴ�. 
					buylist = (int **)realloc(buylist, count * sizeof(int *));	// �ζǸ� 1ȸ ������ ������ ���� �Ҵ��� ũ�⸦ �����մϴ�. 
					buylist[count - 1] = newTicket();	// ���ο� �ζǸ� �����Ͽ� ���� 
					printf("Case #%d / ", count);
					for(j = 0; j < 6; j++) {
						printf("%d ", buylist[count - 1][j]);	// ���� �� �ζǸ� �ϳ��� ��� �մϴ�. 
						for(k = 0; k < 6; k++) {
							if(buylist[count - 1][j] == win[k]) {
								prize++;	// ��÷ ��ȣ�� �´��� üũ�մϴ�. �ϳ��� ���� ������ 1���� ����ϴ�. 
							}
						}
						if(buylist[count - 1][j] == win[6]) {	
							prize += 10;	// ���ʽ� ��ȣ�� �´��� üũ�մϴ�. �Ϲ� ��ȣ�� �ٸ��� 10���� ����ϴ�. 
						}
					}
					switch(prize) {	// ��÷ ���̽��Դϴ�. ���ڰ� Ŀ�� 1000���� ������ ���߿� 1000�� �ٽ� ���մϴ�. 
						case 6:		// 1��(���� 6�� ��ġ) 
							printf("/ 1st Prize - 2,000,000,000 won\n");
							money += 2000000;
							rank[0]++;	// rank �迭�� 4�� �޴�(4�� �̻� ��÷�ɋ� ���� ����)�� ���� �����Դϴ�. 
							break;

						case 15:	// 2��(���� 5�� + ���ʽ� 1�� ��ġ) = 5 + 10 
							printf("/ 2nd Prize - 100,000,000 won\n");
							money += 100000;
							rank[1]++;
							break;

						case 5:		// 3��(���� 5�� ��ġ) 
							printf("/ 3rd Prize - 2,000,000 won\n");
							money += 2000;
							rank[2]++;
							break;

						case 4:		// 4��(���� 4�� ��ġ) 
							printf("/ 4th Prize - 50,000 won\n");
							money += 50;
							rank[3]++;
							break;
						
						case 3:		// 3��(���� 3�� ��ġ) 
							printf("/ 5th Prize - 5,000 won\n");
							money += 5;
							break;

						default:	// ������(��) 
							printf("/ You lose\n");
							break;
					}
				}
				printf("\n");
				break;

			case 2:		// �� �ζ��� ������ ����մϴ�. �׸��� ���� ���(count * 1000��)�� ����մϴ�. 
				printf("You bought %d tickets, and the total cost is %d won\n\n", count, count * 1000);
				break;

			case 3:		// ��÷���� �հ踦 ����մϴ�. �տ��� 1000���� �������� ������ 1000�� �ٽ� �����ݴϴ�. 
				printf("Yon won %llu won\n\n", money * 1000);
				break;

			case 4:		// 4�� �̻��� �ɸ��� ���� �����մϴ�. 
				target = rank[0] + rank[1] + rank[2] + rank[3];		// ó��(����) ��÷ Ƚ���� �����մϴ�. 
				countt = count;		// ó��(����) ���� Ƚ���� �����մϴ�. 
				moneyt = money;		// ó��(����) ��÷���� �����մϴ�. 
				printf("Are you sure? (y or n) : ");
				scanf(" %c", &ask);
				if(ask == 'y') {
					while(rank[0] + rank[1] + rank[2] + rank[3] == target) {	// 4�� �̻� ��÷�Ǹ� ������ 1 �����ϸ鼭 while���� �ڵ����� �������ɴϴ�. 
						prize = 0;		// ���� �ڵ�� 1�� �޴��� �����մϴ�. 
						count++;
						buylist = (int **)realloc(buylist, count * sizeof(int *));
						buylist[count - 1] = newTicket();
						printf("Case #%d / ", count);
						for(j = 0; j < 6; j++) {
							printf("%d ", buylist[count - 1][j]);
							for(k = 0; k < 6; k++) {
								if(buylist[count - 1][j] == win[k]) {
									prize++;
								}
							}
							if(buylist[count - 1][j] == win[6]) {
								prize += 10;
							}
						}
						switch(prize) {
							case 6:
								printf("/ 1st Prize - 2,000,000,000 won\n");
								money += 2000000;
								rank[0]++;
								break;

							case 15:
								printf("/ 2nd Prize - 100,000,000 won\n");
								money += 100000;
								rank[1]++;
								break;

							case 5:
								printf("/ 3rd Prize - 2,000,000 won\n");
								money += 2000;
								rank[2]++;
								break;

							case 4:
								printf("/ 4th Prize - 50,000 won\n");
								money += 50;
								rank[3]++;
								break;

							case 3:
								printf("/ 5th Prize - 5,000 won\n");
								money += 5;
								break;

							default:
								printf("/ You lose\n");
								break;
						}
					}
					printf("Cost : %d won, Money : %llu won\n\n", (count - countt) * 1000, (money - moneyt) * 1000);
					break;		// ���� Ƚ�� - ó�� Ƚ��, ���� ��÷�� - ó�� ��÷���� ����Ͽ� �󸶳� ���, ��÷�Ǵ��� ��Ÿ���ϴ�. 
				} else if(ask == 'n') {
					printf("\n");
					break;
				}	

			case 0:		// Exit �޴��Դϴ�. 
				printf("Good bye!\n");
				break;

			default:	// 0~4 �̿��� ���ڰ� �ԷµǾ��� �� ����մϴ�. 
				printf("Input correct menu\n\n");
				break;
		}
		if(select == 0) {
			break;		// 0�� �޴��� ����Ͽ��� �� ���α׷��� �����մϴ�. 
		}
	}

	for(int i = 0; i < count; i++) {
		free(buylist[i]);	// ������ �ζǸ� �����ϴ� 2���� �迭�� �� 1���� �迭�� �����մϴ�. 
	}
	free(buylist); 			// 1���� �迭���� ���� 2���� �迭�� �����մϴ�. 
	free(win);				// ��÷ ��ȣ �迭�� �����մϴ�. 
	buylist = NULL;			// �迭�� ����ߴ� �����Ϳ� NULL�� �Ҵ��մϴ�.
	win = NULL;				// �迭�� ����ߴ� �����Ϳ� NULL�� �Ҵ��մϴ�.
	return 0;
}
