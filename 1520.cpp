/*입력
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 N이 빈칸을 사이에 두고 주어진다. 이어 다음 M개 줄에 걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 빈 칸을 사이에 두고 주어진다. M과 N은 각각 500이하의 자연수이고, 각 지점의 높이는 10000이하의 자연수이다.

출력
첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
9:16
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<int, int> > q;
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
int m, n;//세로 가로
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
		return 1;//목적지에 도착한 분기에서 1씩 리턴함 
	}

	if (ret >= 0)//만약에 이전에 도달한 적이 있다면 (0부터 해야 다음 분기가 없는지점인지 구분 가능)
		return ret;//중복 필요 없으므로 바로 끝냄

	ret = 0;//아직 리턴받은 분기가 없음

	int nx, ny;
	for (int a = 0; a < 4; a++)
	{
		nx = x + ix[a];
		ny = y + iy[a];
		if (rng(nx, ny))
			if (map[x][y] > map[nx][ny])
			{
				ret += dfs(nx, ny);//분기들에서 받은 정보를 저장 
			}
	}
	return ret;//리턴받은 분기들 수를 리턴해줌
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