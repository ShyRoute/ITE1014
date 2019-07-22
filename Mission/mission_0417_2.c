#include <stdio.h>

int main(void) {
	int a, b, temp, gcd, lcm, num1, num2;
	scanf("%d %d", &a, &b);
	num1 = a;
	num2 = b;
	while (1) {
		if (b > a) {
			temp = a;
			a = b;
			b = temp;
		}
		if (b == 0) {
			gcd = a;
			break;
		} else {
			temp = a;
			a = b;
			b = temp % b;
		}
	}
	lcm = num1 * num2 / gcd;
	printf("%d %d", gcd, lcm);
	return 0;
}
