#include <stdio.h>

#define MAX_NODE 100

typedef struct listNode
{
	int data;//������
	struct listNode* prev;//���� 
	struct listNode* next;//���� 
} ListNode;

typedef struct
{
	int use;//��뿩�� 
	ListNode node;//����ü 
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];//���� �ִ� ũ�� (��� ������ ����ü�� ��ü ���� 

void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;// �̻�� �ʱ�ȭ 
	}
}

void initListNode(ListNode* node)
{
	node->data = 0;//�־��� ����� ������
	node->prev = node;//����
	node->next = node;//���� 
//�ʱ�ȭ
}

ListNode* getListNode(void)//������ ��� ������ ��� �ϳ��� �� 
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)//�̻�� ��� 
		{
			heap[i].use = 1;//��� ǥ��
			initListNode(&heap[i].node);//�ʱ�ȭ
			return &heap[i].node;// �ּҰ� ����
		}
	}
	return NULL;
}

void destroyListNode(ListNode* node)//�־��� ��� ���ֱ� 
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);//ListNodeHeap ����ü�� use�� �����ϱ� ���ؼ� �ּҰ��� int ��ŭ �ϳ� �ٿ��� �����Ѵ�.
	heap_node->use = 0;
}

ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();//���ο� ��� �Ҵ� 
	node->data = data;//data ��� 
	if (list == NULL)//���� ����Ʈ�� ����ִٸ� 
	{
		return node;// ���� ���� ��带 ���� 
	}
	else
	{
		ListNode* last = list->prev;// ���� ����Ʈ�� ������带
		last->next = node;//�� ��忡 ���� 
		list->prev = node;//���� ����� ���� 
		node->prev = last;//������� ���� ��带 ������ 
		node->next = list;//�� ����� ������ ���� ��忡 ���� 
		// prev-new-list ���·� ���� 
		return list;
	}
}

ListNode* removeListNode(ListNode* list, ListNode* node)
{
	if (list == list->next)//..?
	{
		destroyListNode(node);
		return NULL;
	}
	else
	{
		ListNode* prev = node->prev;//����� ����
		ListNode* next = node->next;//����� ����
		prev->next = next;
		next->prev = prev;
		//���� ����
		destroyListNode(node);// ��� ���� 

		return (list == node) ? next : list;
	}
}

int main(int argc, char* argv[])
{

	int T, N;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		ListNode* list = NULL;
		ListNode* node;
		int i;

		initHeap();

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			int data;
			scanf("%d", &data);
			list = appendListNode(list, data);
		}

		node = list;
		while (list != list->next)
		{
			ListNode* nextNode = node->next;
			list = removeListNode(list, node);
			node = nextNode->next->next;
		}

		printf("#%d %d\n", test_case, list->data);
	}
	return 0;
}