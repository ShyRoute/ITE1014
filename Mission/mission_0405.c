#include <stdio.h>
#include <stdlib.h> 

int main(void) {
	int a=0;
	float b=0;
	printf("Input integer a : ");
	scanf("%d", &a);
	printf("Input float b : ");
	scanf("%f", &b);
	printf("a + b = %.2f \n", a+b);
	printf("a - b = %.2f \n", a-b);
	printf("a * b = %.2f \n", a*b);
	printf("a / b = %.2f \n", a/b);
	system("pause");
	
	return 0;
}
