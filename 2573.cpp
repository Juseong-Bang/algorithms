/*
입력
첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다.
N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다.
각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다.
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

출력
첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.
*/

#include<iostream>
#include<queue>

using namespace std;

int n, m;
int total;
int map[301][301] = { 0, };
int map2[301][301] = { 0, };
int(*vi)[301];
int(*ch)[301];
int ix[4] = { 0,1,-1,0 };
int iy[4] = { 1,0,0,-1 };
queue <pair<int, int > > q;
bool check() {

	int visit[301][301] = { 0, };
	int c=0;
	
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (visit[i][j] == 0 && vi[i][j]>0 ) {
				visit[i][j] = ++c;
				if(c>1)
					return true;
				q.push(pair<int, int>(i, j));
				
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					
					for (int k = 0; k<4; k++) {
						int nx = x + ix[k];
						int ny = y + iy[k];
						
						if (-1<nx && nx<n && -1<ny && ny<m && vi[nx][ny]>0 && visit[nx][ny]==0) {
							q.push(pair<int, int>(nx, ny));
							visit[nx][ny] = c;
						}
					}
					q.pop();
				}
			}
		}
	}
	
	return false;
}

int bfs() {
	vi = map;
	ch = map2;
	int ret = 0;

	while (!check()) {
		if(total==0)//전부 녹을때까지 분리되지 않는경우 0을 리턴
			return 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (vi[i][j] > 0){
					int cn = 0;
					for (int k = 0; k<4; k++) {
						int nx = i + ix[k];
						int ny = j + iy[k];
						if (-1<nx && nx<n && -1<ny && ny<m && vi[nx][ny] == 0) {
							cn++;
						}
					}
					if (vi[i][j] - cn < 0)
					{
						ch[i][j] = 0;
						total-=vi[i][j];
					}else{
						ch[i][j] = vi[i][j] - cn;
						total-=cn;
					}
				}
				else
				{
					ch[i][j] = 0;
				}
			}
		}

		int(*tm)[301] = vi;
		vi = ch;
		ch = tm;
		ret++;
	
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) {
		cin >> map[i][j];
		total+=map[i][j];
		}
	cout << bfs() << endl;
}