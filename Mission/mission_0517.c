#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

int main(void) {
	int r1, r2, c1, c2, i, j, k;
	srand(time(NULL));
	while(1) {
		printf("== Matrix 1 ==\n");
		printf("Row : ");
		scanf("%d", &r1);
		printf("Column : ");
		scanf("%d", &c1);
		printf("\n");
		printf("== Matrix 2 ==\n");
		printf("Row : ");
		scanf("%d", &r2);
		printf("Column : ");
		scanf("%d", &c2);
		if(r2 == c1) break;
		else printf("Cannot multiply\n");
	}
	printf("\n");
	
	int **m1 = NULL;
	m1 = (int **)malloc(r1 * sizeof(int *));
	for(i = 0; i < r1; i++) {
		m1[i] = (int *)malloc(c1 * sizeof(int));
		for(j = 0; j < c1; j++) {
			m1[i][j] = rand() % 10;	
		}
	}
	printf("<Matrix 1>\n");
	for(i = 0; i < r1; i++) {
		for(j = 0; j < c1; j++) {
			printf("%3d ", m1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	int **m2 = NULL;
	m2 = (int **)malloc(r2 * sizeof(int *));
	for(i = 0; i < r2; i++) {
		m2[i] = (int *)malloc(c2 * sizeof(int));
		for(j = 0; j < c2; j++) {
			m2[i][j] = rand() % 10;	
		}
	}
	printf("<Matrix 2>\n");
	for(i = 0; i < r2; i++) {
		for(j = 0; j < c2; j++) {
			printf("%3d ", m2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	int **r = NULL;
	r = (int **)malloc(r1 * sizeof(int *));
	int t = 0;
	for(i = 0; i < r1; i++) {
		r[i] = (int *)malloc(c2 * sizeof(int));
		for(j = 0; j < c2; j++) {
			t = 0;
			for(k = 0; k < r2; k++) {
				t += m1[i][k] * m2[k][j];
			}
			r[i][j] = t;
		}
	}
	printf("<Matrix 1 x 2>\n");
	for(i = 0; i < r1; i++) {
		for(j = 0; j < c2; j++) {
			printf("%3d ", r[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < r1; i++) {
		free(m1[i]);
		free(r[i]);
	}
	free(m1);
	m1 = NULL;
	free(r);
	r = NULL;
	for(i = 0; i < r2; i++) {
		free(m2[i]);
	}
	free(m2);
	m2 = NULL;
}
