#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int N, data, i;
	int numArr[100];
	int countArr[6] = { 0, };
	srand(time(NULL));
	scanf("%d", &N);
	Sleep(3000);
	for (i=0 ; i<N ; i++) {
		numArr[i] = (rand() % 6) + 1;
	}
	for (i=0 ; i<N ; i++) {
		printf("%d ", numArr[i]);
		countArr[int(numArr[i])-1] += 1;
	}
	printf("\n");
	for (i=0 ; i<6 ; i++) {
		printf("%d ", countArr[i]);
	}
	return 0;
}
