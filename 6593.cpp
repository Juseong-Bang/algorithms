/*
����
����� ��� ������ ������ ���Ҵ�. ���⼭ Ż���ϴ� ���� ���� ���� �����ϱ�? ��� ������ �� ���� ���̰� 1�� ������ü(���� ������ü)�� �̷�����ִ�. �� ������ü�� ������ �̷���� �־� ������ �� ���ų�, ����־ ������ �� �ְ� �Ǿ��ִ�. ����� �� ĭ���� ������ 6���� ĭ(��,��,��,��,��,��)���� 1���� �ð��� �鿩 �̵��� �� �ִ�. ��, �밢������ �̵��ϴ� ���� �Ұ����ϴ�. �׸��� ��� ������ �ٱ��鵵 ��� ������ �����־� �ⱸ�� ���ؼ��� Ż���� �� �ִ�.

����� ��� ������ Ż���� �� ������? ���� �׷��ٸ� �󸶳� �ɸ���?

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷������, �� �׽�Ʈ ���̽��� �� ���� ���� L, R, C�� �����Ѵ�. L(1 �� L �� 30)�� ��� ������ �� ���̴�. R(1 �� R �� 30)�� C(1 �� C �� 30)�� ��� ������ �� ���� ��� ���� ������ ��Ÿ����.

�� ���� �� ���� C���� ���ڷ� �̷���� R���� ���� L�� �־�����. �� ���ڴ� ��� ������ �� ĭ�� ��Ÿ����. ������ �����־� ������ �� ���� ĭ�� '#'���� ǥ���ǰ�, ����ִ� ĭ�� '.'���� ǥ���ȴ�. ����� ���� ������ 'S'�� ǥ���ǰ�, Ż���� �� �ִ� �ⱸ�� 'E'�� ǥ���ȴ�. �� �� ���̿��� �� ���� ������, �Է��� ���� L, R, C�� ��� 0���� ǥ���ȴ�.

���
�� ������ ���� �� �پ� ���� ����Ѵ�. ���� ����� Ż���� �� �ִٸ� ������ ���� ����Ѵ�.

Escaped in x minute(s).
���⼭ x�� ��� ������ Ż���ϴ� ���� �ʿ��� �ִ� �ð��̴�.

���� Ż���� �Ұ����ϴٸ�, ������ ���� ����Ѵ�.
Trapped!
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char map[31][31][31] = { 0, };
int ih[6] = { 0,0,0,0,-1,1 };
int ix[6] = { 1,-1,0,0,0,0 };
int iy[6] = { 0,0,-1,1,0,0 };
int l, r, c;
int  vi[31][31][31] = { 0, };
bool rng(int h, int x, int y)
{
	if (h < 0 || x < 0 || y < 0 || h >= l || x >= r || y >= c)
		return false;
	return true;
}
typedef struct pos {
	int h;
	int x;
	int y;
}p;
int bfs(int h, int x, int y)
{
	queue<p> q;
	p ef;
	int nh, nx, ny;
	int a, b, c;
	ef.h = h;
	ef.x = x;
	ef.y = y;
	vi[h][x][y] = 1;

	q.push(ef);
	while (!q.empty())
	{
		a = q.front().h;
		b = q.front().x;
		c = q.front().y;
		q.pop();
		if (map[a][b][c] == 'E')//���� 
		{
			return vi[a][b][c];
		}

		for (int i = 0; i < 6; i++)
		{
			nh = a + ih[i];
			nx = b + ix[i];
			ny = c + iy[i];

			if (rng(nh, nx, ny) && map[nh][nx][ny] != '#')
				if (vi[nh][nx][ny] == 0)
				{
					ef.h = nh;
					ef.x = nx;
					ef.y = ny;
					vi[nh][nx][ny] = vi[a][b][c] + 1;
					q.push(ef);
				}
		}
	}
	return 0;
}
int main()
{
	while (1)
	{
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
			break;

		memset(vi, 0, sizeof(vi));

		int s[3] = { -1,-1,-1 };
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
			{
				cin >> map[i][j];
				if (s[0] == -1)
					for (int k = 0; k < c; k++)
						if (map[i][j][k] == 'S')//���� 
						{
							s[0] = i;
							s[1] = j;
							s[2] = k;
							vi[i][j][k] = 1;
						}
			}

		int ret = bfs(s[0], s[1], s[2]);

		if (ret == 0)
			cout << "Trapped!" << endl;
		else
		{
			cout << "Escaped in " << ret - 1 << " minute(s)." << endl;
		}
	}
	return 0;
}