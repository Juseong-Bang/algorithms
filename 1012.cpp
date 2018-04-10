/*
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50),
그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다.
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.
출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, k;
queue <int > q;
int vec[2500][2] = { 0, };
bool vi[2500] = { 0, };

int bfs()
{
	memset(vi, 0, sizeof(vi));

	int pos = 0, difx = 0, dify = 0, cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (vi[i] == true)
			continue;

		q.push(i);
		vi[i] = true;
		cnt++;
		while (!q.empty())
		{
			pos = q.front();
			q.pop();

			for (int j = 0; j < k; j++)
				if (vi[j] == false)
				{
					difx = (vec[j][0] - vec[pos][0]);
					dify = (vec[j][1] - vec[pos][1]);
					difx = difx > 0 ? difx : -difx;
					dify = dify > 0 ? dify : -dify;

					if (difx + dify == 1)
					{
						vi[j] = true;
						q.push(j);
					}
				}
		}
	}
	return cnt;
}
int main()
{
	int t, x, y;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			vec[i][0] = x;
			vec[i][1] = y;
		}
		cout << bfs() << endl;
	}
	return 0;
}