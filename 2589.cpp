/*
보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.

입력
첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 빈칸을 사이에 두고 주어진다. 이어 l과 w로 표시된 보물 지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 칸이 없다. 보물 지도의 가로, 세로의 크기는 각각 50이하이다.

출력
첫째 줄에 보물이 묻혀 있는 두 곳 사이를 최단 거리로 이동하는 시간을 출력한다.
*/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
char map[51][51] = { 0, };
int vi[51][51] = { 0, };

int ix[4] = { 0,0,1,-1 };
int iy[4] = { 1,-1,0,0 };
queue< pair<int, int > > q;

bool rng(int x, int y) {
	if (x < 0 || y < 0 || n <= x || m <= y || map[x][y] == 'W')
		return false;
	return true;
}

int bfs()
{
	int x, y;
	int nx, ny;
	int ret = 0;
	x = q.front().first;
	y = q.front().second;
	vi[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + ix[i];
			ny = y + iy[i];

			if (rng(nx, ny))//범위 안에 들고
				if (vi[nx][ny] == 0)//방문 X  
				{
					vi[nx][ny] = vi[x][y] + 1;
					q.push(make_pair(nx, ny));
					if (ret < vi[nx][ny])
						ret = vi[nx][ny];
				}
		}
	}

	return ret;
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	int ma = 0, ret;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				memset(vi, 0, sizeof(vi));
				q.push(make_pair(i, j));
				ret = bfs();

				if (ma < ret)
					ma = ret;
			}
		}
	}

	cout << ma - 1;

	return 0;
}