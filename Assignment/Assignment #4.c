#include <stdio.h>
#include <stdlib.h>

void printmenu(void) {	// �޴��� ����մϴ�. 
	printf("==================\n");
	printf("      1. add      \n");
	printf("      2. sub      \n");
	printf("      3. mul      \n");
	printf("      4. div      \n");
	printf("      0. exit     \n");
	printf("==================\n");
	return; 
}

float add(void) {	// �ʱ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// �Է°��� atof �����, result���� �����մϴ�. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�. 
	result = num1 + num2;
	return result;	// result�� ���� ������� �����մϴ�. 
}

float add_R(float result) {	// �ݺ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. �ʱ� �Լ����� ����� result���� ����մϴ�. 
	char input[20];
	float num;
	printf("%.4f + ", result);
	scanf("%s", input);
	num = atof(input);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	result = result + num;
	return result;	// result�� ���� ������� �����մϴ�.
}

float sub(void) {	// �ʱ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�.
	char input1[20];
	char input2[20];
	float num1, num2, result;	// �Է°��� atof �����, result���� �����մϴ�. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	result = num1 - num2;
	return result;	// result�� ���� ������� �����մϴ�.
}

float sub_R(float result) {	// �ݺ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. �ʱ� �Լ����� ����� result���� ����մϴ�. 
	char input[20];
	float num;
	printf("%.4f - ", result);
	scanf("%s", input);
	num = atof(input);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	result = result - num;
	return result;	// result�� ���� ������� �����մϴ�.
}

float mul(void) {	// �ʱ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// �Է°��� atof �����, result���� �����մϴ�. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);
	printf("Input second number : ");
	scanf("%s", input2);
	num2 = atof(input2);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	result = num1 * num2;
	return result;	// result�� ���� ������� �����մϴ�.
}

float mul_R(float result) {	// �ݺ� ���� �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. �ʱ� �Լ����� ����� result���� ����մϴ�. 
	char input[20];
	float num;
	printf("%.4f * ", result);
	scanf("%s", input);
	num = atof(input);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	result = result * num;
	return result;	// result�� ���� ������� �����մϴ�.
}

float divf(void) {	// �ʱ� ������ �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. 
	char input1[20];
	char input2[20];
	float num1, num2, result;	// �Է°��� atof �����, result���� �����մϴ�. 
	printf("Input first number : ");
	scanf("%s", input1);
	num1 = atof(input1);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
	while (1) {
		printf("Input second number : ");
		scanf("%s", input2);
		num2 = atof(input2);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
		if (num2 == 0) {
			printf("Can't divide by zero !!\n");
			continue;	// ������ ���� 0�� ��, continue������ ������ ���� �ٽ� �Է¹޽��ϴ�. 
		} else {
			break;	// ������ ���� 0�� �ƴ� ��, while���� �������� �������� �����մϴ�. 
		}
	}
	result = num1 / num2;
	return result;	// result�� ���� ������� �����մϴ�.
}

float divf_R(float result) {	// �ݺ� ������ �Լ��Դϴ�. �� ���� ���� �Է¹޽��ϴ�. �ʱ� �Լ����� ����� result���� ����մϴ�. 
	char input[20];
	float num;
	while (1) {
		printf("%.4f / ", result);
		scanf("%s", input);
		num = atof(input);	// atof�� ����Ͽ� �Է°��� float ���·� ��ȯ�մϴ�.
		if (num == 0) {
			printf("Can't divide by zero !!\n");
			return result;	// ������ ���� 0�� ��, �������� �������� �ʰ� result���� �ٽ� ��ȯ�մϴ�. 
		} else {
			break;	// ������ ���� 0�� �ƴ� ��, while���� �������� �������� �����մϴ�. 
		}
	}
	result = result / num;
	return result;	// result�� ���� ������� �����մϴ�.
}

int main(void) {	// ���� �Լ��Դϴ�. 
	char work[10];	// � ������ �������� �Է��ϴ� ����
	float result;
		
	printf("==================\n");
	printf("    Calculator    \n");
	printf("==================\n");
	
	while (1) {	// �ʱ� ���� �����Դϴ�.  
		printmenu();
		printf(">>> ");	
		scanf(" %c", &work);
		
		if (work[0] == '1') {	// ���� ������ �Է¹ް� result�� ���갪�� �����մϴ�. Wrong command ���� ���Է� ������ �����ϱ� ���� ������ �־����ϴ�. 
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
		} else {	// �߸��� ���� �Է� ���� ó���Դϴ�. 
			printf("Wrong command !!\n");
			continue;
		}
		printf("Result is %.4f\n", result);	// result���� �Ҽ��� ��° �ڸ����� ����մϴ�. 
		break;	// �ʱ� ��� �����̱� ������ �ѹ��� �۵��մϴ�. 
	}
	
	while (1) {	// �ݺ� ��� �����Դϴ�. �ʱ� ���� ��� ���� �߰� ������ �����մϴ�. 
		printmenu();
		printf(">>> ");
		scanf(" %c", &work);	// ���� ������ �Է¹ް� result�� ���갪�� �����մϴ�. Wrong command ���� ���Է� ������ �����ϱ� ���� ������ �־����ϴ�. 
		
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
		} else {	// �߸��� ���� �Է� ���� ó���Դϴ�. 
			printf("Wrong command !!\n");
			continue;
		}
		printf("Result is %.4f\n", result);	// result���� �Ҽ��� ��° �ڸ����� ����մϴ�.
		continue;	// �ݺ� ��� �����̱� ������ while���� ��� �ݺ��մϴ�. 
	}
	return 0;
}
