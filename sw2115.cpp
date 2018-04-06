/*
[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초.

2. 벌통들의 크기 N은 3 이상 10 이하의 정수이다. (3 ≤ N ≤ 10)

3. 선택할 수 있는 벌통의 개수 M은 1 이상 5 이하의 정수이다. (1 ≤ M ≤ 5)

4. 선택할 수 있는 벌통의 개수 M은 반드시 N 이하로만 주어진다.

5. 꿀을 채취할 수 있는 최대 양 C는 10 이상 30 이하의 정수이다. (10 ≤ C ≤ 30)

6. 하나의 벌통에서 채취할 수 있는 꿀의 양은 1 이상 9 이하의 정수이다.

7. 하나의 벌통에서 일부분의 꿀만 채취할 수 없고, 벌통에 있는 모든 꿀을 한번에 채취해야 한다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 벌통들의 크기 N, 선택할 수 있는 벌통의 개수 M, 꿀을 채취할 수 있는 최대 양 C가 차례로 주어진다.

그 다음 줄부터 N*N 개의 벌통에서 채취할 수 있는 꿀의 양에 대한 정보가 주어진다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 두 일꾼이 꿀을 채취하여 얻을 수 있는 최대 수익이다.
*/
#include<iostream> 
#include<cstring>
using namespace std;
int n, m, c;
int map[10][10] = { 0, };
int vi[10][10] = { 0, };
int pick[10] = { 0, };
void ch(int x, int y, int cur, int cnt)//x,y부터 m개중 선택하는 dfs함수 
{

	if (cur >= m)
	{
		
		int pr = 0;

		for (int i = y; i < y + m; i++)
		{
			if (pick[i] == 1)//만약에 m개의 벌통중 i번쨰껄 선택 햇다면 
				pr += (map[x][i] * map[x][i]);
		}

		if (vi[x][y] <= pr)
			vi[x][y] = pr;

		return;
	}
	else
	{

		pick[y + cur + 1] = 1;
		ch(x, y, cur + 1, cnt + map[x][y + cur + 1]);

		pick[cur + 1] = 0;
		ch(x, y, cur + 1, cnt);//현재껄 포함하지 않은 c 

	}
}

int main() {
	freopen("sample_input.txt", "r", stdin);

	int x = 0;
	cin >> x;
	for (int tc = 0; tc < x; tc++) {
		cin >> n >> m >> c;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - m + 1; j++)
			{
				memset(pick, 0, sizeof(pick));
				ch(i, j, -1, 0);
			}

		int m1[2][2] = { 0, };
		int temp = 0;

		for (int l = 0; l < 2; l++) {
			temp = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n - m + 1; j++)
				{

					if (l == 1) {
						if (m1[0][0] == i && m1[0][1] - m < j && j < m1[0][1] + m)
						{
							continue;
						}
						if (temp < vi[i][j])
						{
							temp = vi[i][j];
							m1[l][0] = i;
							m1[l][1] = j;
						}
					}
					else if (temp < vi[i][j])
					{
						temp = vi[i][j];
						m1[l][0] = i;
						m1[l][1] = j;
					}
				}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << vi[i][j] << " ";
			}
			cout << endl;
		}

		temp = vi[m1[0][0]][m1[0][1]] + vi[m1[1][0]][m1[1][1]];
		cout << "#" << tc + 1 << " " << temp << endl;
		memset(vi, 0, sizeof(vi));

	}
	return 0;
}