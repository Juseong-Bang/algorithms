#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)//시작 끝 주소값 
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)//교차되기 전까지 
		{
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}

			while (input[j] > input[pivot])
			{
				j--;
			}

			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

void printResult(void)
{
	int i;

	for (i = 0; i < num; ++i)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}

int main(void)
{
	int T;
	int test_case;
	int i;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &num);
		for (i = 0; i < num; i++)
		{
			scanf("%d", &input[i]);
		}
		quickSort(0, num - 1);
		printf("#%d ", test_case);
		printResult();
	}

	return 0;
}