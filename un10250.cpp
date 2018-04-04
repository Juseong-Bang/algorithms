/*
입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 써 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 써 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/
#pragma warning(disable: 4819)
#include<iostream>
#include<queue>
using namespace std;
int n, m;
int map[500][500] = { 0, };
int ch[500][500] = { false, };
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
long mx = -1;

queue<pair<int, int> > q;

void bfs(int, int);
int cnt() {
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ch[i][j])
				ret += map[i][j];
	return ret;
}
bool rang(int x, int y) {

	if (x < 0 || y < 0 || n - 1 < x || m - 1 < y)
		return false;
	return true;
}

void dfs(int x, int y, int num) //x,y,고른수
{
	ch[x][y] = true;
	if (num == 4) {//4개를 골랏다면 
		int re = cnt();//합산 
		if (mx == -1 || re > mx)
			mx = re;//최대값 갱신 
		return;// 종료 
	}
	// 4개 고르지 못함 
	for (int i = 0; i < 4; i++) {
		int nx = x + ix[i];
		int ny = y + iy[i];
		if (rang(nx, ny) && !ch[nx][ny]) {

			dfs(nx, ny, num + 1);
			ch[nx][ny] = false;
		}
	}

	/*
	int nx,ny,x,y;
	while(!q.empty()){
	x=q.front().first;
	y=q.front().second;

	for(int k=0;k<4;k++)
	{
	nx = x +ix[k];
	ny = y +iy[k];
	if(rang(nx,ny) && ch[nx][ny]==false)
	{
	num++;
	q.push(make_pair(nx,ny));
	}
	}
	}*/

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	dfs(0, 0, 0);
	cout << mx;
}