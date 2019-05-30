#include <stdio.h>
#include <malloc.h>

int **createMatrix(int width, int height);
void freeMatrix(int **matrix);

void printMatrix(int **matrix);
void getMatrixShape(int **matrix, int *width, int *height);
int **rotate(int **matrix);

int main(void)
{
	int width, height;

	printf("Input row size of the matrix : ");
	scanf("%d", &height);

	printf("Input column size of the matrix : ");
	scanf("%d", &width);

	int **matrix = createMatrix(width, height);

	for (int degree = 0; degree <= 270; degree += 90)
	{
		printf("< degree : %d >\n", degree);
		printMatrix(matrix);

		(degree < 270) && (matrix = rotate(matrix));
	}

	freeMatrix(matrix);

	return 0;
}

int** createMatrix(int width, int height)
{
	int** ret = (int **)malloc(height * sizeof(int *));

	int index = 0;
	for (int j = 0; j < height; ++j)
	{
		ret[j] = (int *)malloc(width * sizeof(int));

		for (int i = 0; i < width; ++i)
		{
			++index;
			ret[j][i] = index;
		}
	}

	return ret;
}

void freeMatrix(int **matrix)
{
	int width, height;
	getMatrixShape(matrix, &width, &height);

	for (int i = 0; i < height; ++i)
	{
		free(matrix[i]);
		matrix[i] = NULL;
	}

	free(matrix);
}

void printMatrix(int** matrix)
{
	int width, height;
	getMatrixShape(matrix, &width, &height);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
			printf("%4d", matrix[y][x]);

		printf("\n");
	}
}

void getMatrixShape(int **matrix, int *width, int *height)
{
	*height = _msize(matrix) / sizeof(int *);
	*width = _msize(matrix[0]) / sizeof(int);
}

int** rotate(int** matrix)
{
	int width, height;
	getMatrixShape(matrix, &height, &width);

	int **ret = createMatrix(width, height);

	for (int j = 0; j < width; ++j)
	{
		for (int i = 0; i < height; ++i)
		{
			ret[i][width - j - 1] = matrix[j][i];
		}
	}

	freeMatrix(matrix);
	return ret;
}
