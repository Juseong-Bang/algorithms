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
int b[3] = { 0, };
bool vi[201][201][201] = { false, };
typedef struct bottle
{
	int a;
	int b;
	int c;
}bt;
queue<bt> q;

void bfs()
{
	bt s = { 0,0,b[2] };
	int t[3];
	int nt[3];
	int f, d;
	q.push(s);
	vi[0][0][b[2]] = true;

	while (!q.empty())
	{
		t[0] = q.front().a;
		t[1] = q.front().b;
		t[2] = q.front().c;
		q.pop();

		for (int i = 0; i < 3; i++)//i에서 
			for (int j = 0; j < 3; j++)//j로 부음 
				if (i != j)
				{
					nt[0] = t[0];
					nt[1] = t[1];
					nt[2] = t[2];

					f = t[i];//부어아할 양
					d = b[j] - t[j];//남은 공간

					if (d <= 0 || f <= 0)//부을 공간 없음 또는 부을 게 없음 
						continue;

					if (d >= f)//다 부을수 있음 
					{
						nt[j] = t[j] + t[i];
						nt[i] = 0;
					}
					else if (d < f)//다 못부음 
					{
						nt[j] = t[j] + d;
						nt[i] = t[i] - d;
					}

					if (!vi[nt[0]][nt[1]][nt[2]])
					{
						vi[nt[0]][nt[1]][nt[2]] = true;

						s.a = nt[0];
						s.b = nt[1];
						s.c = nt[2];
						q.push(s);
						//cout << "(" << nt[0] << "," << nt[1] << "," << nt[2] << ")" << endl;
					}
				}
	}
}
int main()
{
	cin >> b[0] >> b[1] >> b[2];
	bfs();
	for (int i =0; i<=b[2]; i++)
		if (vi[0][b[2] - i][i])
			cout << i << " ";
	return 0;
}