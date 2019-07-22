#include <stdio.h>
#include <string.h>

void strReverse(char* text, int a) {
	int i=0;
	for(i=0 ; i<a/2 ; i++) {
		char temp = text[i];
		text[i] = text[a-1-i];
		text[a-1-i] = temp;
	}
}

int main(void) {
	char str[100];
	printf("Input string : ");
	scanf("%[^\n]s", str);
	strReverse(str, strlen(str));
	printf("Reversed str : %s\n", str);
	return 0;
}
