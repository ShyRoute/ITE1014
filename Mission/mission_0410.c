#include <stdio.h>

int main(void) {
	while (1) {
		int n, w, i, j, k;
		printf("==== Calculator ==== \n");
		printf("1. Square            \n");
		printf("2. Reversed triangle \n");
		printf("0. Exit              \n");
		printf("==================== \n");
		scanf("%d", &w);
		
		switch (w) {
			case 0 :
				break;
			
			case 1 :
				scanf("%d", &n);
				for (i=0; i<n; i++) {
					printf("*");
				}
				printf("\n");	
				i = 0;		
				do {
					printf("*");
					for (j=0; j<(n-2); j++) {
						printf(" ");
					}
					printf("*");
					printf("\n");
					i++;
				}	while (i<(n-2));
				for (i=0; i<n; i++) {
					printf("*");
				}
				printf("\n");
				continue;		
				
			case 2 :
				scanf("%d", &n);
				for (i=0; i<n; i++) {
					printf("*");
				}
				printf("\n");	
				i = 1;
				do {
					for (j=0; j<i; j++) {
						printf(" ");
					}
					printf("*");
					for (k=0; k<((n-1)/2-i); k++) {
						printf(" ");
					}
					for (k=0; k<((n-3)/2-i); k++) {
						printf(" ");
					}
					if (n%2 == 0) {
						printf(" ");
					}
					printf("*");
					printf("\n");
					i++;
				} while (i<(n-1)/2);
				for (j=0; j<(n-1)/2; j++) {
						printf(" ");
					}
				if (n%2 == 1) {
					printf("* \n");
				} else if (n%2 == 0) {
					printf("** \n");
				}
				printf("\n");
				continue;
			
			default :
				printf("Wrong command \n");
				printf("\n");
				continue;
		}
	return 0;
	}
}
