/*
문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이 때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이 때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤1,000), M(1≤M≤1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/
#include<iostream>
#include <queue>
#include<cstring>
using namespace std;
int n, m;
char map[1000][1001] = { 0, };
int vi[2][1000][1000] = { 0, };//방문 여부를 두가지로 체크
int ix[4] = { 0,0,-1,1 };
int iy[4] = { -1,1,0,0 };

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}
int bfs()
{
	int dest1, dest2;
	int x, y, nx, ny, c;
	queue<pair<int, pair<int, int > > > q;
	memset(vi, 0, sizeof(vi));
	q.push(make_pair(1, make_pair(0, 0)));
	vi[1][0][0] = 1;

	while (!q.empty())
	{
		c = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		for (int a = 0; a < 4; a++)
		{
			nx = x + ix[a];
			ny = y + iy[a];
			if (rng(nx, ny))
			{
				if (map[nx][ny] == '0'&& vi[c][nx][ny] == 0)
				{
					vi[c][nx][ny] = vi[c][x][y] + 1;
					q.push(make_pair(c, make_pair(nx, ny)));
				}
				if (c > 0 && map[nx][ny] == '1')//기회가 한번 있음
				{
					vi[c - 1][nx][ny] = vi[c][x][y] + 1;
					q.push(make_pair(c - 1, make_pair(nx, ny)));
				}
			}
		}
	}

	dest1 = vi[1][n - 1][m - 1];
	dest2 = vi[0][n - 1][m - 1];

	if (dest1 == 0 && dest2 == 0)
		return -1;
	else if (dest1 > 0 && dest2 > 0)
		return min(dest1, dest2);
	else
		return dest1 > 0 ? dest1 : dest2;
}
int main()
{
	cin >> n >> m;
	char a;

	for (int i = 0; i < n; i++)
		cin >> map[i];

	cout << bfs();
}