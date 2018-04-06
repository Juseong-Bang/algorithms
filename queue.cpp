#include <stdio.h>
#include<malloc.h>


int front;//�賾 �ּҸ� ����Ŵ
int rear;//�� �ּҸ� ����Ŵ
int * queue;//ũ��� max
int MAX_N = 10;

void queueInit(void)//�ʱ�ȭ�� ����Ʈ�� ��� 0���� 
{
	front = 0;
	rear = 0;
	queue = (int *)malloc(sizeof(int)*MAX_N);
}

int queueIsEmpty(void)
{
	return (front == rear);//������ ��� 
}

int queueIsFull(void)
{
	if ((rear + 1) % MAX_N == front)//����+1�� ��������  ũ�⸦ �Ѿ�� 
	{ 
		MAX_N*=2;//2�� Ȯ�� 
		int * temp = (int *)malloc(sizeof(int)*MAX_N);
		for (int i = 0; i < MAX_N/2;i++) 
		{
			temp[i] = queue[i];
		}
		free(queue);
		queue = temp;
		printf("resize to:%d",MAX_N);
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(int value)
{
	if (queueIsFull())//
	{
		printf("queue is full!");
		return 0;
	}

	queue[rear] = value;//��� ���� �ְ� 
	rear++;//�ϳ� ���� 
	if (rear == MAX_N)//��� �ִ��
	{
		rear = 0;//�� ������ , ���� ���� �ʾұ� ������ �տ� �� 
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty())//����ٸ� 
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[front];//�Ѱܹ��� �����Ϳ� ���� 
	front++;//����Ʈ ���� 
	if (front == MAX_N)//���࿡ ������ ����Ʈ�� �Ӵٸ� 
	{
		front = 0;//�� ������ 
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int T;
	int N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		queueInit();
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			queueEnqueue(value);
			printf("setValue");
		}

		printf("#%d ", test_case);

		while (!queueIsEmpty())
		{
			int value;
			if (queueDequeue(&value) == 1)
			{
				printf("%d ", value);
			}
		}
		printf("\n");
	}
	return 0;
}