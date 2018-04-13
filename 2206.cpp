/*
����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����. ����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �� �� �ִ� ��η� �̵��Ϸ� �Ѵ�. �ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �� �� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.

���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.

���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1��N��1,000), M(1��M��1,000)�� �־�����. ���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.
*/
#include<iostream>
#include <queue>
#include<cstring>
using namespace std;
int n, m;
char map[1000][1001] = { 0, };
int vi[2][1000][1000] = { 0, };//�湮 ���θ� �ΰ����� üũ
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
				if (c > 0 && map[nx][ny] == '1')//��ȸ�� �ѹ� ����
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