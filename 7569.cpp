/*입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H 가 주어진다.
M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다.
둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다.
즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다.
각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다.
정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
이러한 N개의 줄이 H 번 반복하여 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다.
만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1 을 출력해야 한다.
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
				if (map[i][j][r] == 1)//익은 토마토 에서 시작 
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
							if (rng(nl, nx, ny) && map[nl][nx][ny] == 0)//안익은 것 만 
								if (vi[nl][nx][ny] == 0 || vi[nl][nx][ny] > d + 1)//처음 방문 또는 더 가깝게 방문  
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
			//	else if (map[i][j][r] == -1)//비어있는 자리
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