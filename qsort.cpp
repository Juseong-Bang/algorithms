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
		pivot = first;//첫번쨰 값을 pivot으로 설정 
		i = first;
		j = last;

		while (i < j)//교차되기 전까지 
		{
			while (input[i] <= input[pivot] && i < last)//last를 넘어가지 않아야함 
			{
				i++;
			}
			// pivot보다 큰 원소 i  
			while (input[j] > input[pivot])//어차피 pivot은 처음 원소니 while에서 앞으로 넘어가지 않음
			{
				j--;
			}
			//pivot보다 작은 원소 j 

			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			// i와 j 교체
			// 반복하면 pivot을 기준으로 작은값과 큰값으로 나눠짐 
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;
		//pivot을 j와 바꾸고 
		//j를 기준으로 작은것과 큰것으로 나눠 다시 호출 
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