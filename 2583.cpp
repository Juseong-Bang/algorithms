/*
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다.
M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지,
그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다.
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다.
모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
*/

#include<iostream>
#include<queue>
using namespace std;

int m, n, k;//세로, 가로 
int sqr[100][4] = { 0, };//왼아xy , 오위xy 순서 
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
		cin >> sqr[i][0] >> sqr[i][1] >> sqr[i][2] >> sqr[i][3];//가로 세로 

	plt();
	int cnt = bfs();
	cout << cnt << endl;

	qsort(cct+1, cnt, sizeof(int), (int(*)(const void *, const void *))cmp);

	for (int i = 1; i <= cnt; i++)
		cout << cct[i] << " ";
	return 0;
}