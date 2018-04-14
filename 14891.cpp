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
#include<stdio.h>
#include<queue>
using namespace std;

int gear[4][8] = { 0, };//톱니바퀴 
int spin[100][2] = { 0, };//회전 정보 - gear 번호 , 방향
queue <pair<int, int> > q;//기어 번호, 방향
int k;//회전 횟수 

void roll(int gn, int w)// 기어 번호, 방향 
{
	int temp;
	if (w < 0)//-1은 반시계
		for (int i = 0; i < 8 - 1; i++)
		{
			temp = gear[gn][(i + 1) % 8];
			gear[gn][(i + 1) % 8] = gear[gn][i];
			gear[gn][i] = temp;
		}
	else//1은 시계
		for (int i = 7; i > 0; i--) {
			temp = gear[gn][i - 1];
			gear[gn][i - 1] = gear[gn][i];
			gear[gn][i] = temp;
		}
	return;
}
void bfs() {
	int gn, w;//기어번호, 방향	
	for (int c = 0; c < k; c++)
	{
		int check[4] = { 0, };
		check[spin[c][0]] = spin[c][1];
		q.push(make_pair(spin[c][0], spin[c][1]));
		while (!q.empty())
		{
			gn = q.front().first;
			w = q.front().second;
			q.pop();
			if (0 < gn && gn < 4)//왼쪽이 있다면 123
				if (gear[gn][6] != gear[gn - 1][2] && check[gn - 1] == 0)//극이 다르고 회전한적이 없다면 
				{
					check[gn - 1] = -w;
					q.push(make_pair(gn - 1, -w));
				}

			if (-1 < gn && gn < 3)//오른쪽이 있다면 012
				if (gear[gn][2] != gear[gn + 1][6] && check[gn + 1] == 0)//극이 다르면 
				{
					check[gn + 1] = -w;
					q.push(make_pair(gn + 1, -w));
				}
		}

		for (int b = 0; b < 4; b++)
			if (check[b] != 0)
				roll(b, check[b]);
	}
	return;
}

int main()
{
	int  score = 0, t = 1;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);//i번쨰 기어의 극 입력 
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> spin[i][0] >> spin[i][1];//기어 번호, 회전 
		spin[i][0]--;
	}
	bfs();

	t = 1;
	score = 0;

	for (int b = 0; b < 4; b++)
	{
		if (gear[b][0] == 1)
			score += t;
		t *= 2;
	}
	cout << score;

	return 0;
}