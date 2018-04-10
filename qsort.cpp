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

	if (first < last)//���� �� �ּҰ� 
	{
		pivot = first;//ù���� ���� pivot���� ���� 
		i = first;
		j = last;

		while (i < j)//�����Ǳ� ������ 
		{
			while (input[i] <= input[pivot] && i < last)//last�� �Ѿ�� �ʾƾ��� 
			{
				i++;
			}
			// pivot���� ū ���� i  
			while (input[j] > input[pivot])//������ pivot�� ó�� ���Ҵ� while���� ������ �Ѿ�� ����
			{
				j--;
			}
			//pivot���� ���� ���� j 

			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			// i�� j ��ü
			// �ݺ��ϸ� pivot�� �������� �������� ū������ ������ 
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;
		//pivot�� j�� �ٲٰ� 
		//j�� �������� �����Ͱ� ū������ ���� �ٽ� ȣ�� 
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
int ar[100] = { 0, };
void qsort(int front, int rear)//�������� ���� 
{
	int temp, i = front + 1, pi = front, j = front;

	if (front < rear)
	{
		for (; i <= rear; i++) // i == pivot+1~rear 
		{
			if (ar[i] < ar[pi])
			{
				j++;//j�� �ϳ� �ø��� 
				//i�� j ��ü 
				temp = ar[j];
				ar[j] = ar[i];
				ar[i] = temp;
			}
		}
		//j�� pivot ��ü 
		temp = ar[j];
		ar[j] = ar[pi];
		ar[pi] = temp;

		qsort(front, j - 1);
		qsort(j + 1, rear);
	}
}