#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
	char name[4];
	unsigned int id;
	float score;
	char grade;
} student;

student* fillStudents(const int n) {
	student *list = (student *)malloc(n * sizeof(student));
	for(int i = 0; i < n; i++) {
		char name[4];
		for(int i = 0; i < 3; i++) {
			name[i] = rand() % 26 + 'A';
		}
		name[3] = '\0';
		strcpy(list[i].name, name);
		list[i].id = rand() % 100000 + 2019000000;
		list[i].score = rand() / (float)RAND_MAX * 4.5;
		if(list[i].score >= 4) list[i].grade = 'A';
		else if(list[i].score >= 3) list[i].grade = 'B';
		else list[i].grade = 'F';
	}
	return list;
}

void printStudents(student* list, const int n) {
	for(int i = 0; i < n; i++) {
		printf("	Student %d\n", i + 1);
		printf("Name	: %s\n", list[i].name);
		printf("ID      : %u\n", list[i].id);
		printf("Score	: %.2f\n", list[i].score);
		printf("Grade	: %c\n", list[i].grade);
		printf("=======================\n");
	}
}

int main(void) {
	int n;
	srand(time(NULL));
	printf("Input number of students : ");
	scanf("%d", &n);
	student *list = fillStudents(n);
	printStudents(list, n);
	free(list);
	list = NULL;
	return 0;
}