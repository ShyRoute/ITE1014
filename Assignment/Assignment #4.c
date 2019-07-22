#include <stdio.h>
#include <stdlib.h>

void printmenu(void) {	// 메뉴를 출력합니다. 
	printf("==================\n");
	printf("      1. add      \n");
	printf("      2. sub      \n");
	printf("      3. mul      \n");
	printf("      4. div      \n");
	printf("      0. exit     \n");
	printf("==================\n");
	return; 
}

float add(void) {	// 초기 덧셈 함수입니다. 두 개의 수를 입력받습니다. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// 입력값과 atof 결과값, result값을 선언합니다. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof를 사용하여 입력값을 float 형태로 전환합니다. 
	result = num1 + num2;
	return result;	// result에 연산 결과값을 저장합니다. 
}

float add_R(float result) {	// 반복 덧셈 함수입니다. 한 개의 수를 입력받습니다. 초기 함수에서 계산한 result값을 사용합니다. 
	char input[20];
	float num;
	printf("%.4f + ", result);
	scanf("%s", input);
	num = atof(input);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	result = result + num;
	return result;	// result에 연산 결과값을 저장합니다.
}

float sub(void) {	// 초기 뺄셈 함수입니다. 두 개의 수를 입력받습니다.
	char input1[20];
	char input2[20];
	float num1, num2, result;	// 입력값과 atof 결과값, result값을 선언합니다. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	result = num1 - num2;
	return result;	// result에 연산 결과값을 저장합니다.
}

float sub_R(float result) {	// 반복 뺄셈 함수입니다. 한 개의 수를 입력받습니다. 초기 함수에서 계산한 result값을 사용합니다. 
	char input[20];
	float num;
	printf("%.4f - ", result);
	scanf("%s", input);
	num = atof(input);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	result = result - num;
	return result;	// result에 연산 결과값을 저장합니다.
}

float mul(void) {	// 초기 곱셈 함수입니다. 두 개의 수를 입력받습니다. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// 입력값과 atof 결과값, result값을 선언합니다. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	result = num1 * num2;
	return result;	// result에 연산 결과값을 저장합니다.
}

float mul_R(float result) {	// 반복 곱셈 함수입니다. 한 개의 수를 입력받습니다. 초기 함수에서 계산한 result값을 사용합니다. 
	char input[20];
	float num;
	printf("%.4f * ", result);
	scanf("%s", input);
	num = atof(input);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	result = result * num;
	return result;	// result에 연산 결과값을 저장합니다.
}

float divf(void) {	// 초기 나눗셈 함수입니다. 두 개의 수를 입력받습니다. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// 입력값과 atof 결과값, result값을 선언합니다. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
	while (1) {
		printf("Input second number : ");
		scanf("%s", input2);
		num2 = atof(input2);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
		if (num2 == 0) {
			printf("Can't divide by zero !!\n");
			continue;	// 나누는 수가 0일 때, continue문으로 나누는 수를 다시 입력받습니다. 
		} else {
			break;	// 나누는 수가 0이 아닐 때, while문을 빠져나와 나눗셈을 수행합니다. 
		}
	}
	result = num1 / num2;
	return result;	// result에 연산 결과값을 저장합니다.
}

float divf_R(float result) {	// 반복 나눗셈 함수입니다. 한 개의 수를 입력받습니다. 초기 함수에서 계산한 result값을 사용합니다. 
	char input[20];
	float num;
	while (1) {
		printf("%.4f / ", result);
		scanf("%s", input);
		num = atof(input);	// atof를 사용하여 입력값을 float 형태로 전환합니다.
		if (num == 0) {
			printf("Can't divide by zero !!\n");
			return result;	// 나누는 수가 0일 때, 나눗셈을 수행하지 않고 result값을 다시 반환합니다. 
		} else {
			break;	// 나누는 수가 0이 아닐 때, while문을 빠져나와 나눗셈을 수행합니다. 
		}
	}
	result = result / num;
	return result;	// result에 연산 결과값을 저장합니다.
}

int main(void) {	// 메인 함수입니다. 
	char work[10];	// 어떤 연산을 수행할지 입력하는 변수
	float result;
		
	printf("==================\n");
	printf("    Calculator    \n");
	printf("==================\n");
	
	while (1) {	// 초기 연산 루프입니다.  
		printmenu();
		printf(">>> ");	
		scanf(" %c", &work);
		
		if (work[0] == '1') {	// 연산 종류를 입력받고 result에 연산값을 저장합니다. Wrong command 등의 오입력 오류를 방지하기 위해 여백을 넣었습니다. 
			result = add();
		} else if (work[0] == '2') {
			result = sub();
		} else if (work[0] == '3') {
			result = mul();
		} else if (work[0] == '4') {		
			result = divf();
		} else if (work[0] == '0') {
			printf("Good bye !!");
			return 0;
		} else {	// 잘못된 문자 입력 예외 처리입니다. 
			printf("Wrong command !!\n");
			continue;
		}
		printf("Result is %.4f\n", result);	// result값을 소수점 넷째 자리까지 출력합니다. 
		break;	// 초기 계산 루프이기 때문에 한번만 작동합니다. 
	}
	
	while (1) {	// 반복 계산 루프입니다. 초기 연산 결과 값에 추가 연산이 가능합니다. 
		printmenu();
		printf(">>> ");
		scanf(" %c", &work);	// 연산 종류를 입력받고 result에 연산값을 저장합니다. Wrong command 등의 오입력 오류를 방지하기 위해 여백을 넣었습니다. 
		
		if (work[0] == '1') {
			result = add_R(result);
		} else if (work[0] == '2') {
			result = sub_R(result);
		} else if (work[0] == '3') {
			result = mul_R(result);
		} else if (work[0] == '4') {		
			result = divf_R(result);
		} else if (work[0] == '0') {
			printf("Good bye !!");
			break;
		} else {	// 잘못된 문자 입력 예외 처리입니다. 
			printf("Wrong command !!\n");
			continue;
		}
		printf("Result is %.4f\n", result);	// result값을 소수점 넷째 자리까지 출력합니다.
		continue;	// 반복 계산 루프이기 때문에 while문을 계속 반복합니다. 
	}
	return 0;
}
