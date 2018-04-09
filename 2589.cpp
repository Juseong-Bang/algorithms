/*
������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� ���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�.

�Է�
ù° �ٿ��� ���� ������ ������ ũ��� ������ ũ�Ⱑ ��ĭ�� ���̿� �ΰ� �־�����. �̾� l�� w�� ǥ�õ� ���� ������ �Ʒ��� ���� ���� �־�����, �� ���� ���̿��� �� ĭ�� ����. ���� ������ ����, ������ ũ��� ���� 50�����̴�.

���
ù° �ٿ� ������ ���� �ִ� �� �� ���̸� �ִ� �Ÿ��� �̵��ϴ� �ð��� ����Ѵ�.
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

			if (rng(nx, ny))//���� �ȿ� ���
				if (vi[nx][ny] == 0)//�湮 X  
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