#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>

void ispri(int *arr) {
	int *prime = NULL;
	prime = (int *)malloc(0);
	int p = 0;
	for(int i=0; i<_msize(arr) / sizeof(arr[0]); i++) {
		int count = 0;
		for(int j=2; j<arr[i]; j++) {
			if(arr[i] % j == 0) count++;
		}
		if(arr[i] != 1 && count == 0)  {
			p++;
			prime = (int *)realloc(prime, p * sizeof(int));
			prime[p-1] = arr[i];
		}
	}
	printf("In Array Primes : ");
	for(int i=0; i<p; i++) {
		printf("%d ", prime[i]);
	}
}

int *ranarr(int *size) {
	int *list = NULL;
	list = (int *)malloc(*size * sizeof(int));
	srand(time(NULL));
	printf("In Array Values : ");
	for(int i=0; i<*size; i++) {
		list[i] = rand() % 50 + 1;
		printf("%d ", list[i]);
	}
	printf("\n");
	return list;
}

int main(void) {
	int size;
	printf("Input Array size : ");
	scanf("%d", &size);
	ispri(ranarr(&size));
	return 0;
}
