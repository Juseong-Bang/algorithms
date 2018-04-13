/*
문제
N×N 게임판에 수가 적혀져 있다. 이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.

각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다. 반드시 오른쪽이나 아래쪽으로만 이동해야 한다. 0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다.

가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 게임 판의 크기 N (4 ≤ N ≤ 100)이 주어진다. 그 다음 N개 줄에는 각 칸에 적혀져 있는 수가 N개씩 주어진다. 칸에 적혀있는 수는 0보다 크거나 같고, 9보다 작거나 같은 정수이며, 가장 오른쪽 아래 칸에는 항상 0이 주어진다.

출력
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다. 경로의 개수는 263-1보다 작거나 같다.
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