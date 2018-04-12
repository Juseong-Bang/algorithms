/*
문제
양치기 꿍은 맨날 늑대가 나타났다고 마을 사람들을 속였지만 이젠 더이상 마을 사람들이 속지 않는다. 화가 난 꿍은 복수심에 부타 아예 늑대들을 양들이 있는 울타리안에 마구 집어넣어 양들을 잡아먹게 했다.

하지만 양들은 보통 양들이 아니다. 같은 울타리 영역 안의 양들의 숫자가 늑대의 숫자보다 더 많을 경우 늑대가 전부 잡아먹힌다. 물론 그 외의 경우는 양이 전부 잡아먹히겠지만 말이다.

꿍은 워낙 똑똑했기 때문에 이들의 결과는 이미 알고있다. 만약 빈 공간을 '.'(점)으로 나타내고 울타리를 '#', 늑대를 'v', 양을 'k'라고 나타낸다면 여러분은 몇 마리의 양과 늑대가 살아남을지 계산할 수 있겠는가?

(단, 울타리로 막히지 않은 영역은 꿍의 관심사항이 아니며 양과 늑대는 대각선으로 이동할 수 없다.)



입력
입력의 첫 번째 줄에는 각각 영역의 세로와 가로의 길이를 나타내는 두 개의 정수 R, C (3 ≤ R, C ≤ 250)가 주어진다.

다음 각 R줄에는 C개의 문자가 주어지며 이들은 위에서 설명한 기호들이다.

출력
살아남게 되는 양과 늑대의 수를 각각 순서대로 출력한다.
*/
#include<iostream>
#include<queue>

using namespace std;

int r, c;//세로, 가로
char map[250][251] = { 0, };
bool vi[250][250] = { false, };

int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };

int v = 0, k = 0;//늑대 ,양

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= r || y >= c)
		return false;
	return true;
}
void bfs(int x, int y)
{
	int ax, ay;
	int nx, ny;
	int lv = 0, lk = 0;
	bool take = false;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	if (map[x][y] == 'v')
		lv++;
	else if (map[x][y] == 'k')
		lk++;

	vi[x][y] = true;

	while (!q.empty())
	{
		ax = q.front().first;
		ay = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			nx = ax + ix[a];
			ny = ay + iy[a];

			if (rng(nx, ny))
			{
				if (map[nx][ny] != '#' && !vi[nx][ny]) //울타리가 아니고 방문한적 없다면  
				{
					vi[nx][ny] = true;//방문 표시

					if (map[nx][ny] == 'v')
						lv++;
					else if (map[nx][ny] == 'k')
						lk++;

					q.push(make_pair(nx, ny));
				}

			}
			else
				take = true;
		}
	}

	//	cout << lk << " " << lv << endl;
	if (!take) {
		if (lv < lk)//양이 더 많다면 
			k += lk;
		else//늑대가 더 많거나 같다면 
			v += lv;
	}
	return;
}
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> map[i];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (!vi[i][j] && map[i][j] != '#')//미방문한 곳 그리고 울타리가 아닌곳 
			{
				bfs(i, j);
				//cout << "(" << i << "," << j << ")" << endl;
			}
	cout << k << " " << v << endl;

	return 0;
}