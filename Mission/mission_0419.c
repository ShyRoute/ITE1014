#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define percent(a,b) (a)/(b)*100

int main(void) {
	int N, i;
	float total, count, avg;
	int numArr[100];
	printf("�л� ���� �Է��ϰ�, ������ �Է��ϼ���. : ");
	scanf("%d", &N);
	printf("");	
	for (i=0 ; i<N ; i++) {
		scanf("%d", &numArr[i]);
		total += numArr[i];
	}
	avg = total / N;
	for (i=0 ; i<N ; i++) {
		if (numArr[i] > avg) {
			count += 1;
		}
	}
	printf("����� �Ѵ� �л��� ������..\n");
	Sleep(1000);
	printf("3\n");
	Sleep(1000);
	printf("2\n");
	Sleep(1000);
	printf("1\n");
	Sleep(1000);
	printf("%.3f%% �Դϴ�.", percent(count, N));
	return 0;
}
