/*�Է�
ù �ٿ��� ������ ũ�⸦ ��Ÿ���� �� ���� M,N�� �׾ƿ÷����� ������ ���� ��Ÿ���� H �� �־�����.
M�� ������ ���� ĭ�� ��, N�� ������ ���� ĭ�� ���� ��Ÿ����. ��, 2 �� M �� 100, 2 �� N �� 100, 1 �� H �� 100 �̴�.
��° �ٺ��ʹ� ���� ���� ���ں��� ���� ���� ���ڱ����� ����� �丶����� ������ �־�����.
��, ��° �ٺ��� N���� �ٿ��� �ϳ��� ���ڿ� ��� �丶���� ������ �־�����.
�� �ٿ��� ���� �����ٿ� ����ִ� �丶����� ���°� M���� ������ �־�����.
���� 1�� ���� �丶��, ���� 0 �� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����.
�̷��� N���� ���� H �� �ݺ��Ͽ� �־�����.

���
�������� �丶�䰡 ��� ���� ������ �ּ� ��ĥ�� �ɸ������� ����ؼ� ����ؾ� �Ѵ�.
����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1 �� ����ؾ� �Ѵ�.
*/
#include<iostream>
#include<queue>
using namespace std;
int n, m, h;
int il[6] = { 0,0,0,0,1,-1 };
int ix[6] = { 0,0,-1,1,0,0 };
int iy[6] = { -1,1,0,0,0,0 };
int map[100][100][100] = { 0, };
int vi[100][100][100] = { 0, };
typedef struct tomato
{
	int l;
	int x;
	int y;
	int d;
}tmt;
queue<tmt> q;

bool rng(int l, int x, int y)
{
	if (l < 0 || x < 0 || y < 0 || l >= h || x >= n || y >= m)
		return false;
	return true;
}
int bfs()
{
	tmt con;
	int x, y, l, d;
	int nx, ny, nl;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int r = 0; r < m; r++)
			{
				if (map[i][j][r] == 1)//���� �丶�� ���� ���� 
				{
					con.d = 0;
					con.l = i;
					con.x = j;
					con.y = r;
					vi[i][j][r] = 1;
					q.push(con);
					while (!q.empty()) 
					{
						x = q.front().x;
						y = q.front().y;
						l = q.front().l;
						d = q.front().d;
						q.pop();
						for (int a = 0; a < 6; a++)
						{
							nx = x + ix[a];
							ny = y + iy[a];
							nl = l + il[a];
							if (rng(nl, nx, ny) && map[nl][nx][ny] == 0)//������ �� �� 
								if (vi[nl][nx][ny] == 0 || vi[nl][nx][ny] > d + 1)//ó�� �湮 �Ǵ� �� ������ �湮  
								{
									con.x = nx;
									con.y = ny;
									con.l = nl;
									con.d = d + 1;

									vi[nl][nx][ny] = d + 1;
									q.push(con);
								}
						}
					}
				}
			//	else if (map[i][j][r] == -1)//����ִ� �ڸ�
				//	vi[i][j][r] = -1;
			}

	int ma = 0;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int r = 0; r < m; r++)
				if (map[i][j][r] == 0 && vi[i][j][r] == 0)
					return -1;
				else if(map[i][j][r] !=1 && ma < vi[i][j][r])
					ma = vi[i][j][r];

	return ma;

}
int main()
{
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int r = 0; r < m; r++)
				cin >> map[i][j][r];

	cout << bfs();

}