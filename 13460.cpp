/*
입력
첫 번째 줄에는 보드의 세로/가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다.
다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다.
이 문자열은 '.', '#', 'O', 'R', 'B' 로만으로 이루어져 있다. '.'은 빈 칸을 의미하고,
'#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다.
'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
*/

#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[10][10];
int ix[4] = { 1,0,0,-1 };
int iy[4] = { 0,1,-1,0 };
pair<int, int> r;
pair<int, int> b;
pair<int, int> h;
queue <pair< int, pair< pair<int, int>, pair<int, int> >  > > q;

int move(int w, pair<int, int>* R, pair<int, int>* B) {
	int cnt = 0;
	bool ro = false;
	bool bo = false;
	int rx = R->first ;
	int ry = R->second ;

	int bx = B->first ;
	int by = B->second ;

	while (1) {
		
		if (rx == h.first && ry == h.second)
			ro = true;
		if (map[rx+ix[w]][ry+iy[w]] == '#')
		{
			break;
		}
		else
		{
			rx += ix[w];
			ry += iy[w];
			cnt++;
		}
	}

	while (1) {
		
		if (bx == h.first && by == h.second)
			bo = true;
		if (bx == rx && by == ry) {
			if (cnt  > 0) {
				rx -= ix[w];
				ry -= iy[w];
			}
			else {
				bx -= ix[w];
				by -= iy[w];
			}
			break;
		}
		else if (map[bx+ix[w]][by+iy[w]] == '#')
		{
			break;
		}
		else
		{
			bx += ix[w];
			by += iy[w];
			cnt--;
		}
	}

	if (bo)//블루 빠짐 
		return -1;
	if (ro)// 레드만 빠짐 
		return 1;

	B->first = bx;
	B->second = by;

	R->first = rx;
	R->second = ry;

	if (!bo && !ro)//둘다 안빠짐 
		return 0;

}
int check()
{
	int cnt = 0;
	q.push(pair< int, pair<pair<int, int>, pair<int, int> > >(cnt, make_pair(make_pair(r.first, r.second), make_pair(b.first, b.second))));
	
	while (!q.empty()) {
		int ret = 0;
		cnt = q.front().first;
		if (cnt>9)
		{
			q.pop();
			continue;
		}
		for (int k = 0; k<4; k++) {

			pair<int, int> R = make_pair(q.front().second.first.first, q.front().second.first.second);
			pair<int, int> B = make_pair(q.front().second.second.first, q.front().second.second.second);
			ret = move(k, &R, &B);

			if (ret == 1)//빨강만 빠짐
				return cnt+1;

			if (ret == 0)//빠진 구슬 X
				q.push(pair< int, pair<pair<int, int>, pair<int, int> > >(q.front().first + 1, make_pair(make_pair(R.first, R.second), make_pair(B.first, B.second))));

		}
		q.pop();
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'O')
			{
				h = pair<int, int>(i, j);
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R')
			{
				r = pair<int, int>(i, j);
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B')
			{
				b = pair<int, int>(i, j);
				map[i][j] = '.';
			}
		}
	cout << check();
}