/*
문제
백준이는 국방의 의무를 수행하기 위해 떠났다. 혹독한 훈련을 무사히 마치고 나서, 정말 잘 생겼고 코딩도 잘하는 백준은 그 특기를 살려 적군의 진영을 수학적으로 분석하는 일을 맡게 되었다.

2차원 평면 위의 N곳에 적군의 진영이 설치되어 있다. 각 적군의 진영들은 마다마다 하나의 통신탑을 설치해, i번째 적군의 통신탑은 설치 위치로부터 Ri 이내 거리에 포함되는 모든 지역을 자신의 통신영역 Ai로 가지게 된다. 만약 임의의 통신영역 Ai와 Aj가 닿거나 겹치는 부분이 있다면 진영 i와 진영 j는 직접적으로 통신이 가능하다. 물론 직접적으로 통신이 가능하지 않더라도, 임의의 지역 i와 j가 중간에 몇 개의 직접통신을 거쳐서 최종적으로 통신이 가능하다면 i와 j는 상호간에 통신이 가능한 것으로 본다.

적들은 영리해서, 상호간에 통신이 가능한 부대끼리는 결집력있는 한 그룹처럼 행동한다. 백준은 이러한 그룹의 갯수를 알아내 아군의 전략지침에 도움을 주고자 한다. 군대에 가서도 코딩하는 불쌍한 백준을 위해 적군의 통신망 분석을 도와주자!

입력
입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 그 다음에는 T개의 테스트 케이스가 주어진다.

각각의 테스트 케이스에 대해서 적군 진영의 숫자 N (1 ≤ N ≤ 3,000)이 주어진다. 이어서 N줄에 걸쳐 적군 진영의 좌표 x, y (0 ≤ x, y ≤ 5,000), 그리고 해당 진영의 R (0 ≤ R ≤ 5,000)이 주어진다.
주어지는 수는 모두 정수이다.

출력
각 테스트 케이스에 대해서 한 줄에 걸쳐 적군 진영의 그룹 갯수를 출력한다.
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int rt[3000][3] = { 0, };
int n;
int g[3000] = { 0, };//그룹명 
queue<int> q;
bool map[3000][3000] = { false, };
int rng(int rt1, int rt2) {
	int x1 = rt[rt1][0];
	int x2 = rt[rt2][0];
	int y1 = rt[rt1][1];
	int y2 = rt[rt2][1];

	return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
bool grp(int rt1, int rt2)
{
	if ((rt[rt1][2] + rt[rt2][2])*(rt[rt1][2] + rt[rt2][2]) >= rng(rt1, rt2))
		return true;
	return false;
}

int bfs()
{
	int cnt = 0;
	int nc = 0;
	for (int i = 0; i < n; i++)
	{
		if (g[i] == 0)
		{
			g[i] = ++cnt;
			q.push(i);
			while (!q.empty())
			{
				nc = q.front();
				q.pop();
				for (int j = 0; j < n; j++)
				{
					if (g[j] == 0 && map[nc][j])
					{
						g[j] = cnt;
						q.push(j);
					}
				}
			}
		}
	}

	return cnt;
}
int main()
{
	int x;
	cin >> x;
	for (int tc = 0; tc < x; tc++)
	{
		cin >> n;
		memset(g, 0, sizeof(g));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			cin >> rt[i][0] >> rt[i][1] >> rt[i][2];
		}

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				map[i][j] = grp(i, j);
				map[j][i] = map[i][j];
			}

		cout << bfs() << endl;
	}
	return 0;
}