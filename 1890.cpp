/*
����
N��N �����ǿ� ���� ������ �ִ�. �� ������ ��ǥ�� ���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� ������ �ؼ� ���� ���̴�.

�� ĭ�� �����ִ� ���� ���� ĭ���� �� �� �ִ� �Ÿ��� �ǹ��Ѵ�. �ݵ�� �������̳� �Ʒ������θ� �̵��ؾ� �Ѵ�. 0�� �� �̻� ������ ���� �������̸�, �׻� ���� ĭ�� �����ִ� ����ŭ �������̳� �Ʒ��� ���� �Ѵ�.

���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� �̵��� �� �ִ� ����� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� ũ�� N (4 �� N �� 100)�� �־�����. �� ���� N�� �ٿ��� �� ĭ�� ������ �ִ� ���� N���� �־�����. ĭ�� �����ִ� ���� 0���� ũ�ų� ����, 9���� �۰ų� ���� �����̸�, ���� ������ �Ʒ� ĭ���� �׻� 0�� �־�����.

���
���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ������ ��Ģ�� �°� �� �� �ִ� ����� ������ ����Ѵ�. ����� ������ 263-1���� �۰ų� ����.
*/
#include<cstring>
#include<iostream>
using namespace std;
int n;
int map[101][101] = { 0, };
int ix[2] = { 1,0 };
int iy[2] = { 0,1 };
long vi[101][101];

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;

}
long dfs(int r, int c)
{
	long &ret = vi[r][c];

	if (r == n - 1 && c == n - 1)
	{
		ret = 1;
		return 1;
	}

	if (ret >= 0)
		return ret;

	ret = 0;
	int nx, ny;
	for (int a = 0; a < 2; a++)
	{
		nx = r + ix[a] * map[r][c];
		ny = c + iy[a] * map[r][c];

		if (rng(nx, ny))
			ret += dfs(nx, ny);
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	memset(vi, -1, sizeof(vi));

	cout << dfs(0, 0);
	return 0;
}