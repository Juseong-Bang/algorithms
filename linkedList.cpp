#include <stdio.h>

#define MAX_NODE 100

typedef struct listNode
{
	int data;//데이터
	struct listNode* prev;//이전 
	struct listNode* next;//다음 
} ListNode;

typedef struct
{
	int use;//사용여부 
	ListNode node;//구조체 
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];//힙의 최대 크기 (사용 가능한 구조체의 전체 갯수 

void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;// 미사용 초기화 
	}
}

void initListNode(ListNode* node)
{
	node->data = 0;//주어진 노드의 데이터
	node->prev = node;//이전
	node->next = node;//다음 
//초기화
}

ListNode* getListNode(void)//힙에서 사용 가능한 노드 하나를 줌 
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)//미사용 노드 
		{
			heap[i].use = 1;//사용 표시
			initListNode(&heap[i].node);//초기화
			return &heap[i].node;// 주소값 리턴
		}
	}
	return NULL;
}

void destroyListNode(ListNode* node)//주어진 노드 없애기 
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);//ListNodeHeap 구조체의 use에 접근하기 위해서 주소값을 int 만큼 하나 줄여서 접근한다.
	heap_node->use = 0;
}

ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();//새로운 노드 할당 
	node->data = data;//data 기록 
	if (list == NULL)//받은 리스트가 비어있다면 
	{
		return node;// 새로 만든 노드를 리턴 
	}
	else
	{
		ListNode* last = list->prev;// 받은 리스트의 이전노드를
		last->next = node;//새 노드에 연결 
		list->prev = node;//받은 노드의 이전 
		node->prev = last;//새노드의 이전 노드를 이전에 
		node->next = list;//새 노드의 다음을 받은 노드에 연결 
		// prev-new-list 형태로 연결 
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
		ListNode* prev = node->prev;//노드의 이전
		ListNode* next = node->next;//노드의 다음
		prev->next = next;
		next->prev = prev;
		//서로 연결
		destroyListNode(node);// 노드 삭제 

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