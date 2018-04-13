/*
����
��ġ�� ���� �ǳ� ���밡 ��Ÿ���ٰ� ���� ������� �ӿ����� ���� ���̻� ���� ������� ���� �ʴ´�. ȭ�� �� ���� �����ɿ� ��Ÿ �ƿ� ������� ����� �ִ� ��Ÿ���ȿ� ���� ����־� ����� ��Ƹ԰� �ߴ�.

������ ����� ���� ����� �ƴϴ�. ���� ��Ÿ�� ���� ���� ����� ���ڰ� ������ ���ں��� �� ���� ��� ���밡 ���� ��Ƹ�����. ���� �� ���� ���� ���� ���� ��Ƹ��������� ���̴�.

���� ���� �ȶ��߱� ������ �̵��� ����� �̹� �˰��ִ�. ���� �� ������ '.'(��)���� ��Ÿ���� ��Ÿ���� '#', ���븦 'v', ���� 'k'��� ��Ÿ���ٸ� �������� �� ������ ��� ���밡 ��Ƴ����� ����� �� �ְڴ°�?

(��, ��Ÿ���� ������ ���� ������ ���� ���ɻ����� �ƴϸ� ��� ����� �밢������ �̵��� �� ����.)



�Է�
�Է��� ù ��° �ٿ��� ���� ������ ���ο� ������ ���̸� ��Ÿ���� �� ���� ���� R, C (3 �� R, C �� 250)�� �־�����.

���� �� R�ٿ��� C���� ���ڰ� �־����� �̵��� ������ ������ ��ȣ���̴�.

���
��Ƴ��� �Ǵ� ��� ������ ���� ���� ������� ����Ѵ�.
*/
#include<iostream>
#include<queue>

using namespace std;

int r, c;//����, ����
char map[250][251] = { 0, };
bool vi[250][250] = { false, };

int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };

int v = 0, k = 0;//���� ,��

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= r || y >= c)
		return false;
	return true;
}
void bfs(int x, int y)
{
	int ax, ay;
	int nx, ny;
	int lv = 0, lk = 0;
	bool take = false;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	if (map[x][y] == 'v')
		lv++;
	else if (map[x][y] == 'k')
		lk++;

	vi[x][y] = true;

	while (!q.empty())
	{
		ax = q.front().first;
		ay = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			nx = ax + ix[a];
			ny = ay + iy[a];

			if (rng(nx, ny))
			{
				if (map[nx][ny] != '#' && !vi[nx][ny]) //��Ÿ���� �ƴϰ� �湮���� ���ٸ�  
				{
					vi[nx][ny] = true;//�湮 ǥ��

					if (map[nx][ny] == 'v')
						lv++;
					else if (map[nx][ny] == 'k')
						lk++;

					q.push(make_pair(nx, ny));
				}

			}
			else
				take = true;
		}
	}

	//	cout << lk << " " << lv << endl;
	if (!take) {
		if (lv < lk)//���� �� ���ٸ� 
			k += lk;
		else//���밡 �� ���ų� ���ٸ� 
			v += lv;
	}
	return;
}
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> map[i];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (!vi[i][j] && map[i][j] != '#')//�̹湮�� �� �׸��� ��Ÿ���� �ƴѰ� 
			{
				bfs(i, j);
				//cout << "(" << i << "," << j << ")" << endl;
			}
	cout << k << " " << v << endl;

	return 0;
}