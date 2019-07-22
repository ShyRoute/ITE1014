#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int **rotate(int **m) {								// 이차원 배열의 포인터를 변수로 받아, 회전하는 함수입니다.  
	int **matR = NULL;								// 회전 결과인 새로운 배열(이중 포인터)을 생성합니다. 
	int r = _msize(m) / sizeof(int *);				// 입력받은 배열의 행을 나타냅니다. 
	int c = _msize(m[0]) / sizeof(int);				// 입력받은 배열의 열을 나타냅니다. 
	int i, j;
	matR = (int **)malloc(c * sizeof(int *));		// 새로운 배열(이중 포인터)에 row 수(=원래 배열의 column 수)만큼 * int 크기로 동적 할당 합니다. 
	for(i = 0; i < c; i++) {
		matR[i] = (int *)malloc(r * sizeof(int));	// 할당된 각 공간에 column 수(=원래 배열의 row 수)만큼 int 크기로 동적 할당 합니다. 
	}
	for(i = 0; i < r; i++) {						// 회전한 배열에 숫자를 채우는 과정입니다. 각 row마다 실행합니다. 
		for(j = 0; j < c; j++) {
			matR[j][r - i - 1] = m[i][j];			// 원래 배열의 하나의 row에 담긴 수들을 회전시킨 배열의 같은 column에 row만 증가시켜서 넣는 방식입니다. 
		}
	}
	for(i = 0; i < r; i++) {
		free(m[i]);									// 원래 배열의 메모리를 정리합니다. 원래 배열의 일차원 배열이 할당되었던 각 공간을 모두 free로 정리합니다. 
	}
	free(m);										// 원래 배열의 일차원 배열의 포인터를 저장했던 이차원 공간을 모두 free로 정리합니다. 
	m = NULL;										// 원래 배열의 사용했던 포인터에 NULL을 할당합니다. 
	return matR;									// 회전한 배열을 return합니다. 
}

void print(int **m) {						// 이차원 배열의 포인터를 변수로 받아, 그 배열의 요소들을 출력하는 함수입니다. 
	int r = _msize(m) / sizeof(int *);		// 입력받은 배열의 행을 나타냅니다. 
	int c = _msize(m[0]) / sizeof(int);		// 입력받은 배열의 열을 나타냅니다.
	int i, j;
	for(i = 0; i < r; i++) {				// for문으로 각 row마다 실행합니다. 
		for(j = 0; j < c; j++) {			// for문으로 각 row에서 column을 증가시키며 실행합니다. 
			printf("%3d ", m[i][j]);		// 3글자에 맞춰서, 배열의 각 요소를 차례대로 출력합니다. 
		}
		printf("\n");
	}
}

int main(void) {
	int **mat = NULL;								// 새로운 배열(이중 포인터)을 생성합니다.
	int r, c, i, j;
	printf("Input row size : ");
	scanf("%d", &r);								// row을 입력받습니다. 
	printf("Input column size : ");
	scanf("%d", &c);								// column을 입력받습니다. 
	mat = (int **)malloc(r * sizeof(int *));		// 새로운 배열(이중 포인터)에 row 수만큼 * int 크기로 동적 할당 합니다.
	int k = 1;										// 배열에 숫자를 채우는 과정입니다. 첫 숫자는 1로 하고, 1씩 늘려 가며 숫자를 채우는 방식입니다. 
	for(i = 0; i < r; i++) {
		mat[i] = (int *)malloc(c * sizeof(int));	// 할당된 각 공간에 column 수만큼 int 크기로 동적 할당 합니다.
		for(j = 0; j < c; j++) {
			mat[i][j] = k;							// 숫자를 한 칸씩 채웁니다. 
			k++;									// 채우고 나서, 다음 숫자는 +1 하는 과정입니다. 
		}
	}

	printf("< Degree : 0 >\n"); 					// 0도 회전(초기 상태)의 배열은 회전하지 않고 출력합니다. 
	print(mat);										// 초기 배열을 회전 없이 print 함수로 출력합니다. 

	int **mat90 = rotate(mat);						// 90도 회전시킨 배열을 새롭게 생성합니다. 초기 상태에서 rotate 함수를 한번 실행합니다. 
	printf("< Degree : 90 >\n");
	print(mat90);									// 90도 회전시킨 배열을 print 함수로 출력합니다. 

	int **mat180 = rotate(mat90);					// 180도 회전시킨 배열을 새롭게 생성합니다. 90도 회전한 배열에서 rotate 함수를 한번 실행합니다.
	printf("< Degree : 180 >\n");					
	print(mat180);									// 180도 회전시킨 배열을 print 함수로 출력합니다.

	int **mat270 = rotate(mat180);					// 270도 회전시킨 배열을 새롭게 생성합니다. 180도 회전한 배열에서 rotate 함수를 한번 실행합니다.
	printf("< Degree : 270 >\n");
	print(mat270);									// 270도 회전시킨 배열을 print 함수로 출력합니다.

	for(i = 0; i < r; i++) {						// 출력을 다 끝내고 남은 배열은 270도 회전시킨 배열이므로, 이 배열의 메모리를 정리합니다.  
		free(mat270[i]);							// 배열의 일차원 배열이 할당되었던 각 공간을 모두 free로 정리합니다. 
	}
	free(mat270);									// 배열의 일차원 배열의 포인터를 저장했던 이차원 공간을 모두 free로 정리합니다.
	mat270 = NULL;									// 배열의 사용했던 포인터에 NULL을 할당합니다.
	return 0;
}
