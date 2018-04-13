/*
������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�.
M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������,
�׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. M, N, K�� ��� 100 ������ �ڿ����̴�.
��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����.
�������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. �ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.

���
ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�. ��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�.
*/

#include<iostream>
#include<queue>
using namespace std;

int m, n, k;//����, ���� 
int sqr[100][4] = { 0, };//�޾�xy , ����xy ���� 
bool map[100][100] = { false, };
int vi[100][100] = { 0, };
queue<pair<int, int > > q;
int ix[4] = { 0,0,1,-1 };
int iy[4] = { 1,-1,0,0 };
int cct[10000] = { 0, };

bool rng(int y, int x)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}
void plt()
{
	for (int h = 0; h < k; h++)
	{
		for (int j = sqr[h][1]; j < sqr[h][3]; j++)//y
			for (int i = sqr[h][0]; i < sqr[h][2]; i++)//x
				map[j][i] = true;
	}
}
int bfs()
{
	int x, y, nx, ny;
	int cnt = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!map[i][j] && vi[i][j] == 0)
			{
				vi[i][j] = ++cnt;
				cct[cnt]++;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int a = 0; a < 4; a++)
					{
						nx = x + ix[a];
						ny = y + iy[a];
						if (rng(ny, nx) && !map[nx][ny] && vi[nx][ny] == 0)
						{
							vi[nx][ny] = cnt;
							cct[cnt]++;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
	return cnt;
}
int cmp(const void *a, const  void*b)
{
	return (*(int *)a - *(int *)b);
};
int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> sqr[i][0] >> sqr[i][1] >> sqr[i][2] >> sqr[i][3];//���� ���� 

	plt();
	int cnt = bfs();
	cout << cnt << endl;

	qsort(cct+1, cnt, sizeof(int), (int(*)(const void *, const void *))cmp);

	for (int i = 1; i <= cnt; i++)
		cout << cct[i] << " ";
	return 0;
}