#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	char text[100];
	scanf("%[^\n]s", text);
	scanf("%d", &n);
	for(int i=0; i < sizeof(text) / sizeof(text[0]); i++) {
		if (text[i] == '\0') {
			break;
		}
		printf("%c", text[i]);
		if (i%n == (n-1)) {
			printf("\n");
		}
	}
	return 0;
}
