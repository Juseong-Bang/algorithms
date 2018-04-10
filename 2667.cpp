/*
입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/
#include<iostream>
#include<queue>
using namespace std;
int n;
char map[25][26] = { 0, };
int vi[25][25] = { 0, };
int ix[4] = { 0,0,1,-1 };
int iy[4] = { 1,-1,0,0 };
int part[25 * 25] = { 0, };
queue<pair<int, int> > q;

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}
void qsrt(int l, int r)
{
	int temp;
	int i = l + 1, p = l, j = l;

	if (l < r)
	{
		for (; i <= r; i++) {
			if (part[i] < part[p]) {
				j++;
				temp = part[j];
				part[j] = part[i];
				part[i] = temp;
			}
		}

		temp = part[j];
		part[j] = part[p];
		part[p] = temp;

		qsrt(l, j - 1);
		qsrt(j + 1, r);
	}
}
int bfs()
{
	int cnt = 0;
	int x, y, nx, ny;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j]-'0'== 1 && vi[i][j] == 0)
			{
				q.push(make_pair(i, j));
				vi[i][j] = ++cnt;
				part[cnt - 1]++;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();

					for (int a = 0; a < 4; a++)
					{
						nx = x + ix[a];
						ny = y + iy[a];
						if (rng(nx, ny) && map[nx][ny]-'0' == 1 && vi[nx][ny] == 0)
						{
							vi[nx][ny] = cnt;
							part[cnt-1]++;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}

	qsrt(0, cnt - 1);//오름차순 정렬

	return cnt;
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
			cin >> map[i];

	int cnt = bfs();
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << part[i] << endl;
	return 0;
}