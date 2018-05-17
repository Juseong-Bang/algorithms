/*
ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�.
�Է�
ù° �ٿ� N�� �־�����. (1 �� N �� 100)

��° �ٺ��� N�� �ٿ��� �׸��� �־�����.

���
���ϻ����� �ƴ� ����� ���� ���� ������ ������ ���ϻ����� ����� ���� ���� ������ ���� �������� ������ ����Ѵ�.
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
char map[101][102] = { 0, };
bool vi[100][100] = { false, };
queue<pair<int, int > > q;
int ix[4] = { 0,0,-1,1 };
int iy[4] = { -1,1 ,0,0 };

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}
bool color(char m, char now, bool st)
{
	if (m == now)//������ true
		return true;
	else if (st)// ������ �ƴ�
	{
		return false;//�ٸ��� false
	}
	else//������
	{
		if (m != 'B' && now != 'B')//���� ���� ���ϴ� ���϶� 
			return true;
		else
			return false;
	}
}
int bfs(bool st)//true==���� , false == ����
{
	int x, y, nx, ny,cnt = 0;
	char c ;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!vi[i][j])// �湮 üũ
			{
				q.push(make_pair(i, j));
				vi[i][j] = true;
				c = map[i][j];
				cnt++;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						nx = x + ix[k];
						ny = y + iy[k];
						if (rng(nx, ny) && !vi[nx][ny])
							if (color(map[nx][ny], c, st))
							{
								vi[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
					}
				}
			}
		}
	return cnt;
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	cout << bfs(true) <<" ";
	memset(vi, 0, sizeof(vi));
	cout << bfs(false);
	return 0;
}