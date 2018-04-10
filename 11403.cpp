/*
문제
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다.
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다.
i번째 줄의 i번째 숫자는 항상 0이다.

출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다.
정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
*/
#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[100][100] = { 0, };
int rnd[100][100] = { 0, };
int vi[100] = { 0, };
queue<pair<int, int > > q;
int n;
void bfs()
{
	int s, t;

	for (int i = 0; i < n; i++)
	{
		memset(vi, 0, sizeof(vi));
		q.push(make_pair(i, 0));
		//vi[i] = true;
		while (!q.empty())
		{
			s = q.front().first;
			t = q.front().second;
			q.pop();
			for (int j = 0; j < n; j++)
			{
			//	if (j == s)
			//		continue;
				if (map[s][j] == 1 && !vi[j])
				{
					vi[j] = s + 1;
					q.push(make_pair(j, s + 1));
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (vi[j] > 0)
				rnd[i][j] = 1;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << rnd[i][j] << " ";
		cout << endl;
	}
}