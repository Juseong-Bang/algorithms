/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD

[입력]

가장 첫 줄은 전체 테스트케이스의 수이다.

각 테스트 케이스마다 지도의 크기(N x N)가 주어진다. 지도의 크기는 최대 100 x 100이다.

그 다음줄 부터 지도의 크기만큼 2차원 배열 형태의 지도 정보가 주어진다.

[출력]

각 테스트 케이스의 답을 순서대로 출력하며, 각 케이스마다 줄의 시작에 “#C”를 출력하여야 한다.

이때 C는 케이스의 번호이다.

같은 줄에 빈 칸을 하나 두고, 주어진 입력에서 출발지에서 도착지까지 가는 경로 중에 복구 작업에 드는 시간이 가장 작은 경로의 복구 시간을 출력하시오.

*/
#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;
int c;
int number = 0;
int map[101][101];
int ix[4] = { 0,0,1,-1 };
int iy[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;

int path() {
	int x, y, nx, ny;
	int vi[101][101] = { 0, };
	int val[101][101] = { 0, };
	q.push(pair<int, int>(0, 0));//0,0 이 시작 지점
	vi[0][0] = map[0][0];//출발지에서의 복구비용은 그대로 
	int t = 0;
	while (!q.empty()) {//que가 빌때 까지 

		x = q.front().first;
		y = q.front().second;
		q.pop();//원소 하나 꺼냄 

		for (int a = 0; a < 4; a++) {// 4방향 모두를 고려함 
			nx = x + ix[a];
			ny = y + iy[a];
			if (0 <= nx && 0 <= ny && nx < number && ny < number)//0~number-1 까지 탐색 
			{
				if (val[nx][ny] == 0 || vi[nx][ny] > vi[x][y] + map[nx][ny])//새로 탐색하거나 비용이 더 적으면 
				{
					vi[nx][ny] = vi[x][y] + map[nx][ny];// 복구비용을 입력 
					q.push(pair<int, int>(nx, ny));
					val[nx][ny] = 1;
				}
			}
		}
	}
	return vi[number - 1][number - 1];// 도착지까지의 복구 비용
}
int main() {
	long long y;
	cin >> c;
	for (int a = 0; a < c; a++) {
		cin >> number;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		cout << "#" << a + 1 << " " << path() << endl;// 결과 출력
	}
}