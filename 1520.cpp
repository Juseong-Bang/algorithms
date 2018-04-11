/*�Է�
ù° �ٿ��� ������ ������ ũ�� M�� ������ ũ�� N�� ��ĭ�� ���̿� �ΰ� �־�����. �̾� ���� M�� �ٿ� ���� �� �ٿ� N���� ���������� ���ʷ� �� ������ ���̰� �� ĭ�� ���̿� �ΰ� �־�����. M�� N�� ���� 500������ �ڿ����̰�, �� ������ ���̴� 10000������ �ڿ����̴�.

���
ù° �ٿ� �̵� ������ ����� �� H�� ����Ѵ�. ��� �Է¿� ���Ͽ� H�� 10�� ������ ���� �ƴ� �����̴�.
9:16
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<int, int> > q;
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
int m, n;//���� ����
int map[500][500] = { 0, };
int vi[500][500];

bool rng(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n)
		return false;
	return true;
}
int dfs(int x, int y)
{
	int & ret = vi[x][y];//memoization  (int * ret= &vi[x][y])

	if (x == m - 1 && y == n - 1)
	{
		return 1;//�������� ������ �б⿡�� 1�� ������ 
	}

	if (ret >= 0)//���࿡ ������ ������ ���� �ִٸ� (0���� �ؾ� ���� �бⰡ ������������ ���� ����)
		return ret;//�ߺ� �ʿ� �����Ƿ� �ٷ� ����

	ret = 0;//���� ���Ϲ��� �бⰡ ����

	int nx, ny;
	for (int a = 0; a < 4; a++)
	{
		nx = x + ix[a];
		ny = y + iy[a];
		if (rng(nx, ny))
			if (map[x][y] > map[nx][ny])
			{
				ret += dfs(nx, ny);//�б�鿡�� ���� ������ ���� 
			}
	}
	return ret;//���Ϲ��� �б�� ���� ��������
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	memset(vi, -1, sizeof(vi));
	cout << dfs(0, 0) << endl;
	return 0;
}