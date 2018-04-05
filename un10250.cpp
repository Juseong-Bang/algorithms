/*
입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 써 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 써 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n, m;
int map[500][500] = { 0, };
int ch[500][500] = { false, };
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
long mx = -1;

queue<pair<int, int> > q;

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

	if (num == 4) {//4개를 골랏다면 
		int re = cnt();//합산 
		if (mx == -1 || re > mx)
			mx = re;//최대값 갱신 
		/*
		if (re == 7)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					cout << ch[i][j] << ",";
				cout << endl;
			}
			*/
		return;// 종료 
	}
	ch[x][y] = true;
	
	if (num == 3) { // ㅗ 모양 
		int xl, yl, xh, yh;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (ch[i][j] == true)
				{
					if (i > xh)
						xh = i;
					else if (i < xl)
						xl = i;
					if (j > yh)
						yh = j;
					else if (j < yl)
						yl = j;
				}

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
	

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			memset(ch, 0, sizeof(ch));
			dfs(i, j, 0);
		}
	cout << mx;
}