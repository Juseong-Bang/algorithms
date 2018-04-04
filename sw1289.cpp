/*
입력
첫째 줄에 1번 톱니바퀴의 상태, 둘째 줄에 2번 톱니바퀴의 상태, 셋째 줄에 3번 톱니바퀴의 상태, 넷째 줄에 4번 톱니바퀴의 상태가 주어진다. 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.

다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)가 주어진다. 다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다. 각 방법은 두 개의 정수로 이루어져 있고, 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.

출력
총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력한다. 점수란 다음과 같이 계산한다.

1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점
*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct roll {
	int gn;//기어 번호 
	int n;//돌린 횟수 n>0 -> cw,  n<0 -> ccw
}roll;

bool g[4][8] = { false, };//n=false, s=true
int t;
roll mo[100];
queue <pair<roll, int> > q;//  

void ch(int num, int c)//num번째 톱니바퀴를 c번 회전 
{
	bool tmp = 0;
	int ctr = 0;

	if (c<0) {//c가 음수일때 
		ctr = 7 + c;//-1회전은 7회전이랑 같음 
	}

	for (int i = 0; i<8; i++) {
		tmp = g[num][(i + ctr) % 8];
		g[num][(i + ctr) % 8] = g[num][i % 8];
		g[num][i % 8] = tmp;
	}
}

int value() {
	int ret = 0;
	int tw = 1;
	for (int i = 0; i<4; i++) {//회전수 만큼 
		ret += (g[i][0] * tw);
		tw *= 2;
	}
	return ret;
}
int bfs()
{
	int a, b, c;

	for (int i = 0; i<t; i++) {//회전수 만큼 
		q.push(make_pair(mo[i], 0));
		while (!q.empty()) {

			a = q.front().first.gn;//a== i gn 번째 톱니바퀴의 회전 
			b = q.front().first.n;//b== n 바퀴
			c = q.front().second;//돌리는 바퀴 ==0 < == -1 ,  > ==  1
			q.pop();
			if (c == 0) {
				for (int s = 0; s<(b>0) ? b : -b; s++)
				{
					if (0 <= a - 1)//왼쪽 움직임
						if (g[a - 1][2] != g[a][6])//닿아 있는 바퀴랑 다른 극이면 
						{
							if (b>0)
							{
								q.push(make_pair(roll{ a - 1,-1 }, -1));
								ch(a - 1, -1);
							}
							else {
								q.push(make_pair(roll{ a - 1,1 }, -1));
								ch(a - 1, 1);
							}
						}
					if (a + 1 <= 3)//오른쪽 움직임 
						if (g[a][2] != g[a + 1][6])//닿아 있는 바퀴랑 다른 극이면 
						{
							if (b>0) {
								q.push(make_pair(roll{ a + 1,-1 }, 1));
								ch(a + 1, -1);
							}
							else {
								q.push(make_pair(roll{ a + 1,1 }, 1));
								ch(a + 1, 1);
							}
						}
					ch(a, b>0 ? 1 : -1);// 자기자신 움직임
				}
			}
			else
			{
				if (0 <= a - 1 && c == -1)// 왼쪽 
					if (g[a - 1][2] != g[a][6])//닿아 있는 바퀴랑 다른 극이면 
					{
						if (b>0)
						{
							q.push(make_pair(roll{ a - 1,-1 }, -1));
							ch(a - 1, -1);
						}
						else {
							q.push(make_pair(roll{ a - 1,1 }, -1));
							ch(a - 1, 1);
						}
					}
				if (a + 1 <= 3 && c == +1)

					if (g[a][2] != g[a + 1][6])//닿아 있는 바퀴랑 다른 극이면 
					{
						if (b>0) {
							q.push(make_pair(roll{ a + 1,-1 }, 1));
							ch(a + 1, -1);
						}
						else {
							q.push(make_pair(roll{ a + 1,1 }, 1));
							ch(a + 1, 1);
						}
					}

			}

		}
	}
	/*
	if(a==0){

	}else if(a==1){

	}else if(a==2){

	}else if(a==3){

	}
	*/
	return value();
}
int main() {

	for (int i = 0; i<4; i++)
		for (int j = 0; j<8; j++)
			cin >> g[i][j];

	cin >> t;

	for (int i = 0; i<t; i++) {
		cin >> mo[i].gn;
		cin >> mo[i].n;
	}
	cout << bfs() << endl;
}