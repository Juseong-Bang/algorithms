/*
입력
첫째줄에 N이 주어진다. ( 2 ≤ N ≤ 100 )

다음줄에 사과의 개수 K가 주어진다.( 0 ≤ K ≤ 100 )

그리고 K개의 줄에는 사과의 위치가 주어지는데, 첫번째 숫자는 행(row), 두번째 숫자는 열(column) 위치를 의미한다. 사과들의 위치는 모두 다르며, 맨 위 맨 좌측(1행 1열)에는 사과가 없다.

그리고 뱀의 방향변환 개수 L 이 주어진다. ( 1 ≤ L ≤ 100 )

그리고 L개의 줄에는 뱀의 방향변환 정보가 주어지는데,  숫자 X와 문자 C로 이루어져 있다. X초 후에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 방향을 변경 한다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.

출력
문제의 정답,  즉 초(seconds) 를 첫째줄에 출력하라.
*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct coordinate {
	int x;
	int y;
	int dir;

}col;
int ix[4] = { 0,1,0,-1 };
int iy[4] = { 1,0,-1,0 };
int n, k, l, body = 1;
col ap[100];
vector<pair<int, char> > d;
vector<col> q;

bool check(int a, int b) {
	for (int i = 0; i<k; i++) {
		if (a == ap[i].x && b == ap[i].y)
		{
			ap[i].x=-10;
			ap[i].y=-10;
			return true;
		}
	}
	return false;
}

int main() {

	cin >> n;
	cin >> k;
	for (int i = 0; i<k; i++)
	{
		cin >> ap[i].x >> ap[i].y;
	}
	l = 0;
	cin >> l;
	int t;
	char v;
	for (int i = 0; i<l; i++)
	{
		cin >> t >> v;
		d.push_back(make_pair(t, v));
	}

	int w = 0;
	int j = 0, x = 1, y = 1;

	for (int i = 0; i<l; i++)
	{
		for (j; j<d[i].first; j++)
		{
			x += ix[w];
			y += iy[w];
			col tmp = { x,y,w };//x,y는 이동한 머리 
			q.push_back(tmp);
			
			if (x <= 0 || y <= 0 || n < x || n < y)//벽에 부딫힘
			{
				cout << j+1;
				return 0;
			}
			
			if (check(x, y))//사과를 먹음
				body++;
		
			if (body != 1)//자기자신이랑 부딫힘
				for (t = 1; t<=body; t++) {
					if (q[j].x == q[j - t].x && q[j].y == q[j - t].y) {
						cout << j+1 ;
						return 0;
					}
				}
		}
		w = (d[i].second == 'D') ? (w + 1) % 4 : (w + 3) % 4;// 방향 변환
	}
	j--;
	while (1) {
		x += ix[w];
		y += iy[w];
		if (x <= 0 || y <= 0 || n<x || n<y)
		{
			cout << j;
			return 0;
		}else if (body != 1)//자기자신이랑 부딫힘
				for (t = 1; t<=body; t++) {
					if (q[j].x == q[j - t].x && q[j].y == q[j - t].y) {
						cout << j ;
						return 0;
					}
				} 
		j++;
	}
}