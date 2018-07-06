#include<iostream>
#include<queue>

using namespace std;
queue<pair<int, pair<int, int> > > q;
bool vi[4][4] = { false, };
int map[4][4] = { 0, };
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
int ar[7] = { 0, };
bool ext[10000000] = { false, };
bool rng(int x, int y) {
	if (x < 0 || y < 0 || x>3 || y>3)
		return false;
	return true;
}
int res()
{
	int ret = 0;
	for (int i = 0; i < 7; i++)
	{
		ret *= 10;
		ret += ar[i];
	}
	if (!ext[ret])
		ext[ret] = true;
	return ret;
}
/*
int bfs(int r, int s)
{
	int cnt = 0, x = 0, y = 0, nx, ny;
	q.push(make_pair(1,make_pair(r, s)));
	vi[r][s] = true;

	while (q.empty())
	{

		cnt = q.front.first;
		x = q.front.second.first;
		y = q.front.second.second;
		if (cnt == 6)
		{

		}
		for (int i = 0; i < 4; i++)
		{
			nx = x + ix[i];
			ny = y + iy[i];
			if (rng(nx, ny))
			{
				q.push(make_pair(cnt + 1, make_pair(nx, ny)));
			}
		}
	}

}
*/
int dfs(int x, int y, int cnt)
{
	if (cnt >= 7)
	{
	int ret = res();
	return ret;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + ix[i];
		int ny = y + iy[i];
		if (rng(nx, ny))
		{
			dfs(nx,ny,cnt+1);
		}
	}
}
int main()
{
	int tc = 0;
	fopen("sample_input.txt", "stdin");
	cin >> tc;
	for (int x = 0; x < tc; x++)
	{
		int ret = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				memset(ar, 0, sizeof(ar));
				memset(vi, false, sizeof(vi));
				dfs(i, j, 0);
				//bfs(i, j);
			}

		cout << "# " << tc + 1 << " " << ret << endl;
		memset(ext, false, sizeof(ext));
	}
	return 0;
}