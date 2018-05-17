/*
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다.
입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄부터 N개 줄에는 그림이 주어진다.

출력
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
char map[101][102] = { 0, };
bool vi[100][100] = { false, };
queue<pair<int, int > > q;
int ix[4] = { 0,0,-1,1 };
int iy[4] = { -1,1 ,0,0 };

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}
bool color(char m, char now, bool st)
{
	if (m == now)//같으면 true
		return true;
	else if (st)// 색맹이 아님
	{
		return false;//다르니 false
	}
	else//색맹임
	{
		if (m != 'B' && now != 'B')//구분 하지 못하는 색일때 
			return true;
		else
			return false;
	}
}
int bfs(bool st)//true==정상 , false == 색맹
{
	int x, y, nx, ny,cnt = 0;
	char c ;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!vi[i][j])// 방문 체크
			{
				q.push(make_pair(i, j));
				vi[i][j] = true;
				c = map[i][j];
				cnt++;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						nx = x + ix[k];
						ny = y + iy[k];
						if (rng(nx, ny) && !vi[nx][ny])
							if (color(map[nx][ny], c, st))
							{
								vi[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
					}
				}
			}
		}
	return cnt;
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	cout << bfs(true) <<" ";
	memset(vi, 0, sizeof(vi));
	cout << bfs(false);
	return 0;
}