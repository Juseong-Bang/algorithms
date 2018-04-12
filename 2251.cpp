/*
문제
각각 부피가 A, B, C(1≤A, B, C≤200) 리터인 세 개의 물통이 있다.
처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다.
이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이 때에는 한 물통이 비거나, 다른 한 물통이 가득 찰 때까지 물을 부을 수 있다.
이 과정에서 손실되는 물은 없다고 가정한다.

이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다.
첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, C가 주어진다.

출력
첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.
*/
#include<iostream>
#include<queue>
using namespace std;
int b[3][2] = { 0, };
typedef struct bottle
{
	int a;
	int b;
	int c;
}bt;
queue<bt> q;

void bfs()
{
	bt s = bt{ 0,0, };
	int ta, tb, tc;
	q.push(s);
	while (!q.empty())
	{
		ta = q.front().a;
		tb = q.front().b;
		tc = q.front().c;
		q.pop();
		{}
	}
}
int main()
{
	cin >> b[0][1] >> b[1][1] >> b[2][1];
	bfs();
}