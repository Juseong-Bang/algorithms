/*�Է�
�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ������ �־�����.

�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù° �ٿ��� ü������ �� ���� ���� l(4 �� l �� 300)�� �־�����.
ü������ ũ��� l �� l�̴�. ü������ �� ĭ�� �� ���� �� {0, ..., l-1} �� {0, ..., l-1}�� ��Ÿ�� �� �ִ�.
��° �ٰ� ��° �ٿ��� ����Ʈ�� ���� �ִ� ĭ, ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.

���
�� �׽�Ʈ ���̽����� ����Ʈ�� �� ������ �̵��� �� �ִ��� ����Ѵ�.
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
int kx, ky;
int dx, dy;
int ix[8] = { -2,-1,1,2,-2,-1,1,2 };
int iy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int vi[301][301] = { 0, };

bool rng(int x, int y) 
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}
int bfs() 
{
	int x, y, nx, ny, cnt;
	queue < pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(kx, ky)));
	vi[kx][ky] = 1;

	while (!q.empty())
	{
		x = q.front().second.first;
		y = q.front().second.second;
		cnt = q.front().first;
		q.pop();
		
		if (x == dx && y == dy)//�̰Ͷ����� ť�� ������� �ʰ� ����
			return cnt;

		for (int i = 0; i < 8; i++) 
		{
			nx = x + ix[i];
			ny = y + iy[i];
			if (rng(nx, ny) && vi[nx][ny] == 0)
			{
				vi[nx][ny] = 1;
				q.push(make_pair(cnt + 1, make_pair(nx, ny)));
			}
		}
	}
	return -1;
}
int main() 
{
	int ret, x = 0;
	cin >> x;
	for (int tc = 0; tc < x; tc++) 
	{
		cin >> n;
		cin >> kx >> ky;
		cin >> dx >> dy;

		memset(vi, 0, sizeof(vi));
		ret = bfs();
		cout << ret << endl;
	}
	return 0;
}