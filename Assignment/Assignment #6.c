#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

void printMenu(void) {	// 메뉴를 출력하는 함수입니다. 
	printf("======== Lottery Ticket ========\n");
	printf("================================\n");
	printf("1. Buy tickets\n");
	printf("2. Spent money\n");
	printf("3. Earned money\n");
	printf("4. Buy until I get 4th or higher\n");
	printf("0. exit\n");
	printf("================================\n");
}

int *newTicket(void) {			// 새로운 로또 한 장을 만드는 함수입니다. 
	int *newT;					// 새로운 로또 한 장 
	int i, j, check = 0, temp = 0, number = 0;
	newT = (int *)malloc(6 * sizeof(int));		// 일차원, 6칸짜리 배열의 동적 할당 
	while(number < 6) {
		check = 0;				// 중복 방지용 변수 
		newT[number] = rand() % 45 + 1;			// 1 ~ 45 중 하나의 수를 뽑습니다. 
		for(i = 0; i < number; i++) {
			if(newT[number] == newT[i]) {
				check = 1;		// 중복된 숫자가 있으면 check를 1로 만듭니다. 
				break;
			}
		}
		if(check == 0) {		// 중복된 숫자가 없을 때 check가 0이 되고, 다음 칸으로 넘깁니다.
			number++;	 		// check가 1일 때(중복이 발생)는 다음 칸으로 넘어가지 않고, 다시 뽑게 됩니다. 
		}
	}
	for(i = 0; i < 5; i++) {	// 버블 소트로 오름차순 정렬 하였습니다. 
		for(j = 0; j < 5 - i; j++) {
			if(newT[j] > newT[j + 1]) {
				temp = newT[j];
				newT[j] = newT[j + 1];
				newT[j + 1] = temp;
			}
		}
	}
	return newT;	// 6칸짜리 일차원 배열을 반환합니다. 
}

int main(void) {
	int i, j, k, select, temp = 0, count = 0, n, prize = 0, number = 0;
	int target, moneyt, countt;
	char ask;
	unsigned long long money = 0;	// int로 할 시 1등이 두 번 나오면 오버플로우가 발생하게 됩니다. 
	int rank[4] = { 0, };
	srand(time(NULL));
	int *win = NULL;				// 당첨 번호 배열입니다. 
	win = (int *)malloc(7 * sizeof(int));	// 6개의 당첨 번호와 1개의 보너스 번호를 뽑기 때문에 7칸입니다. 
	int check = 0;
	while(number < 7) {				// 배열에 중복 없이 7개의 숫자를 넣습니다. 방식은 newTicket 함수와 동일합니다. 
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
	int **buylist = malloc(0);		// 구매한 로또를 저장하는 2차원 배열입니다. 
	while(1) {
		printMenu();
		printf(">>> ");
		scanf("%d", &select);
		switch(select) {			// 메뉴를 입력받고, 각 case마다 다른 메뉴를 실행합니다. 
			case 1:
				printf("How many lines will you buy? : ");
				scanf("%d", &n);	// 로또를 몇개 살 지 입력받습니다. 
				for(int i = 0; i < n; i++) {
					prize = 0;		// 당첨 확인을 위한 변수입니다. 
					count++;		// 한번 살 때마다 구매 횟수를 1씩 늘립니다. 
					buylist = (int **)realloc(buylist, count * sizeof(int *));	// 로또를 1회 구매할 때마다 동적 할당의 크기를 변경합니다. 
					buylist[count - 1] = newTicket();	// 새로운 로또를 구매하여 저장 
					printf("Case #%d / ", count);
					for(j = 0; j < 6; j++) {
						printf("%d ", buylist[count - 1][j]);	// 새로 산 로또를 하나씩 출력 합니다. 
						for(k = 0; k < 6; k++) {
							if(buylist[count - 1][j] == win[k]) {
								prize++;	// 당첨 번호와 맞는지 체크합니다. 하나가 맞을 때마다 1점을 얻습니다. 
							}
						}
						if(buylist[count - 1][j] == win[6]) {	
							prize += 10;	// 보너스 번호가 맞는지 체크합니다. 일반 번호와 다르게 10점을 얻습니다. 
						}
					}
					switch(prize) {	// 당첨 케이스입니다. 숫자가 커서 1000으로 나누고 나중에 1000을 다시 곱합니다. 
						case 6:		// 1등(숫자 6개 일치) 
							printf("/ 1st Prize - 2,000,000,000 won\n");
							money += 2000000;
							rank[0]++;	// rank 배열은 4번 메뉴(4등 이상 당첨될떄 까지 구매)를 위한 변수입니다. 
							break;

						case 15:	// 2등(숫자 5개 + 보너스 1개 일치) = 5 + 10 
							printf("/ 2nd Prize - 100,000,000 won\n");
							money += 100000;
							rank[1]++;
							break;

						case 5:		// 3등(숫자 5개 일치) 
							printf("/ 3rd Prize - 2,000,000 won\n");
							money += 2000;
							rank[2]++;
							break;

						case 4:		// 4등(숫자 4개 일치) 
							printf("/ 4th Prize - 50,000 won\n");
							money += 50;
							rank[3]++;
							break;
						
						case 3:		// 3등(숫자 3개 일치) 
							printf("/ 5th Prize - 5,000 won\n");
							money += 5;
							break;

						default:	// 나머지(꽝) 
							printf("/ You lose\n");
							break;
					}
				}
				printf("\n");
				break;

			case 2:		// 산 로또의 개수를 출력합니다. 그리고 구매 비용(count * 1000원)을 출력합니다. 
				printf("You bought %d tickets, and the total cost is %d won\n\n", count, count * 1000);
				break;

			case 3:		// 당첨금의 합계를 출력합니다. 앞에서 1000으로 나누었기 때문에 1000을 다시 곱해줍니다. 
				printf("Yon won %llu won\n\n", money * 1000);
				break;

			case 4:		// 4등 이상이 걸릴때 까지 구매합니다. 
				target = rank[0] + rank[1] + rank[2] + rank[3];		// 처음(현재) 당첨 횟수를 저장합니다. 
				countt = count;		// 처음(현재) 구매 횟수를 저장합니다. 
				moneyt = money;		// 처음(현재) 당첨금을 저장합니다. 
				printf("Are you sure? (y or n) : ");
				scanf(" %c", &ask);
				if(ask == 'y') {
					while(rank[0] + rank[1] + rank[2] + rank[3] == target) {	// 4등 이상 당첨되면 좌항이 1 증가하면서 while문을 자동으로 빠져나옵니다. 
						prize = 0;		// 구매 코드는 1번 메뉴와 동일합니다. 
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
					break;		// 나중 횟수 - 처음 횟수, 나중 당첨금 - 처음 당첨금을 계산하여 얼마나 샀고, 당첨되는지 나타냅니다. 
				} else if(ask == 'n') {
					printf("\n");
					break;
				}	

			case 0:		// Exit 메뉴입니다. 
				printf("Good bye!\n");
				break;

			default:	// 0~4 이외의 문자가 입력되었을 때 출력합니다. 
				printf("Input correct menu\n\n");
				break;
		}
		if(select == 0) {
			break;		// 0번 메뉴를 출력하였을 때 프로그램을 종료합니다. 
		}
	}

	for(int i = 0; i < count; i++) {
		free(buylist[i]);	// 구매한 로또를 저장하는 2차원 배열의 각 1차원 배열을 정리합니다. 
	}
	free(buylist); 			// 1차원 배열들이 담겼던 2차원 배열을 정리합니다. 
	free(win);				// 당첨 번호 배열을 정리합니다. 
	buylist = NULL;			// 배열의 사용했던 포인터에 NULL을 할당합니다.
	win = NULL;				// 배열의 사용했던 포인터에 NULL을 할당합니다.
	return 0;
}
