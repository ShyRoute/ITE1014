#include <stdio.h>
#include <string.h>

int main(void) {
	int in, check, count;
	char num[100];
	char *temp = NULL;
	while(1) {
		check = scanf("%d", &in);
		if(check != 1) {
			printf("<ERROR> scanf error\n");
			while(getchar() != '\n');
			continue;
		}
		sprintf(num, "%d", in);
		if(strlen(num) != 8) {	 
			printf("<ERROR> Wrong Input Length\n");
			while(getchar() != '\n');
			continue;
		} else break;
	}
	printf("0 1 2 3 4 5 6 7 8 9\n");
	printf("===================\n");
	for(int i = 0; i < 10; i++) {
		count = 0;
		temp = strchr(num, 48 + i);
		while(temp != NULL) {
			count++;
			temp = strchr(temp + 1, 48 + i);
		}
		printf("%d ", count);
	}
	return 0;
}
