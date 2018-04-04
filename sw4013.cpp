/*
[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,

그 다음 줄부터 T 개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 자석을 회전시키는 횟수 K 가 주어진다.

다음 4 개의 줄에는 1 번 자석부터 4 번 자석까지 각각 8 개 날의 자성정보가 차례대로 주어진다.

그 다음 K 개의 줄에는 자석을 1 칸씩 회전시키는 회전 정보가 주어진다.

자석의 회전 정보는 회전시키려는 자석의 번호, 회전방향으로 구성되어 있다.

회전방향은 1 일 경우 시계방향이며, -1 일 경우 반시계방향이다.
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
	if (w<0)//-1은 반시계
		for (int i = 0; i<8 - 1; i++)
		{
			temp = gear[gn][(i + 1) % 8];
			gear[gn][(i + 1) % 8] = gear[gn][i];
			gear[gn][i] = temp;
		}
	else//1은 시계
		for (int i = 7; i>0; i--) {
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
		check[spin[c][0]]=spin[c][1];
		q.push(make_pair(spin[c][0], spin[c][1]));
		while (!q.empty())
		{
			gn = q.front().first;
			w = q.front().second;
			q.pop();
			if (0<gn && gn<4)//왼쪽이 있다면 123
				if (gear[gn][6] != gear[gn - 1][2] && check[gn - 1] == 0)//극이 다르고 회전한적이 없다면 
				{
					check[gn-1] = -w;
					q.push(make_pair(gn - 1, -w));
				}
			
			if (-1<gn && gn<3)//오른쪽이 있다면 012
				if (gear[gn][2] != gear[gn + 1][6] && check[gn + 1] == 0)//극이 다르면 
				{
					check[gn+1]= -w;
					q.push(make_pair(gn + 1, -w));
				}
		}
		
		for (int b = 0; b<4; b++)
			if (check[b] != 0)
				roll(b, check[b]);
	}
	return;
}

int main()
{
	int h, score = 0, t = 1;
	cin >> h;
	for (int y = 0; y<h; y++)
	{
		cin >> k;
		
		for (int i = 0; i<4; i++)
			for (int j = 0; j<8; j++)
				cin>>gear[i][j];//i번쨰 기어의 극 입력 
		
		for (int i = 0; i<k; i++)
		{
			cin >> spin[i][0] >> spin[i][1];//기어 번호, 회전 
			spin[i][0]--;
		}
		bfs();
		
		t = 1;
		score = 0;

		for (int b = 0; b<4; b++)
		{
			if (gear[b][0] == 1)
				score += t;
			t *= 2;
		}
	cout << "#" << y + 1 << " " << score<<endl;
	}
	return 0;
}