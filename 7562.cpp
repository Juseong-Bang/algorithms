/*입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다.
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
int kx, ky;
int dx, dy;
int ix[8] = { -2,-1,1,2,-2,-1,1,2 };
int iy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int vi[301][301] = { 0, };

bool rng(int x, int y) 
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}
int bfs() 
{
	int x, y, nx, ny, cnt;
	queue < pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(kx, ky)));
	vi[kx][ky] = 1;

	while (!q.empty())
	{
		x = q.front().second.first;
		y = q.front().second.second;
		cnt = q.front().first;
		q.pop();
		
		if (x == dx && y == dy)//이것때문에 큐가 비어있지 않고 끝남
			return cnt;

		for (int i = 0; i < 8; i++) 
		{
			nx = x + ix[i];
			ny = y + iy[i];
			if (rng(nx, ny) && vi[nx][ny] == 0)
			{
				vi[nx][ny] = 1;
				q.push(make_pair(cnt + 1, make_pair(nx, ny)));
			}
		}
	}
	return -1;
}
int main() 
{
	int ret, x = 0;
	cin >> x;
	for (int tc = 0; tc < x; tc++) 
	{
		cin >> n;
		cin >> kx >> ky;
		cin >> dx >> dy;

		memset(vi, 0, sizeof(vi));
		ret = bfs();
		cout << ret << endl;
	}
	return 0;
}