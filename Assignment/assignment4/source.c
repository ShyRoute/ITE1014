#include <stdio.h>
#include <stdlib.h>

void printMenu();
float opAdd(float A, float B);
float opSub(float A, float B);
float opMul(float A, float B);
float opDiv(float A, float B);
float input();

int main() {
	char command = -1;
	int counter = 0;

	float firstOp = 0;
	float secondOp = 0;

	const char opStr[] = " +-*/";

	printf("-----------------------------------\n"
		"         Last Calculator\n"
		"-----------------------------------\n");

	while (1) {
		printMenu();
		scanf(" %c", &command);

		if (command == '0')
			break;
		else if (command != '1' && command != '2' && command != '3' && command != '4') {
			printf("Wrong command!\n");
			continue;
		}

		if (counter == 0) {
			printf("Input first operand: ");
			firstOp = input();
			printf("Input second operand: ");
			secondOp = input();
		} else {
			printf("%.4f %c ", firstOp, opStr[command - '0']);
			secondOp = input();
		}

		if (command == '1')
			firstOp = opAdd(firstOp, secondOp);
		else if (command == '2')
			firstOp = opSub(firstOp, secondOp);
		else if (command == '3')
			firstOp = opMul(firstOp, secondOp);
		else if (command == '4')
			(secondOp != 0) ? (firstOp = opDiv(firstOp, secondOp)) : printf("Can't divide by zero!\n");

		counter = 1;
		printf("Result is %.4f\n", firstOp);
	}

	printf("Good bye!\n");
}

void printMenu() {
	printf(
		"-----------------------------------\n"
		"1. add\n2. sub\n3. mul\n4. div\n0. exit\n"
		"-----------------------------------\n"
		">>> "
	);
}

float opAdd(float A, float B) {
	return A + B;
}

float opSub(float A, float B) {
	return A - B;
}

float opMul(float A, float B) {
	return A * B;
}

float opDiv(float A, float B) {
	return A / B;
}

float input() {
	char temp[256];
	float ret = 0;

	while (1) {
		scanf(" %s", temp);
		ret = atof(temp);

		if (ret == 0 && temp[0] != '0') {
			printf("Wrong input! Input again: ");
			continue;
		}

		return ret;
	}
}
