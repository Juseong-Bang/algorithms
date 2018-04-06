#include <stdio.h>
#include<malloc.h>


int front;//배낼 주소를 가르킴
int rear;//들어갈 주소를 가르킴
int * queue;//크기는 max
int MAX_N = 10;

void queueInit(void)//초기화는 프론트와 리어를 0으로 
{
	front = 0;
	rear = 0;
	queue = (int *)malloc(sizeof(int)*MAX_N);
}

int queueIsEmpty(void)
{
	return (front == rear);//같으면 빈거 
}

int queueIsFull(void)
{
	if ((rear + 1) % MAX_N == front)//리어+1의 나머지가  크기를 넘어가면 
	{ 
		MAX_N*=2;//2배 확장 
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

	queue[rear] = value;//리어에 값을 넣고 
	rear++;//하나 증가 
	if (rear == MAX_N)//리어가 최대면
	{
		rear = 0;//맨 앞으로 , 가득 차지 않았기 때문에 앞에 빔 
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty())//비엇다면 
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[front];//넘겨받은 포인터에 저장 
	front++;//프론트 증가 
	if (front == MAX_N)//만약에 끝까지 프론트가 왓다면 
	{
		front = 0;//맨 앞으로 
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