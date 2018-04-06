/*
제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초

2. 도시의 크기 N은 5 이상 20 이하의 정수이다. (5 ≤ N ≤ 20)

3. 하나의 집이 지불할 수 있는 비용 M은 1 이상 10 이하의 정수이다. (1 ≤ M ≤ 10)

4. 홈방범 서비스의 운영 비용은 서비스 영역의 면적과 동일하다.

5. 도시의 정보에서 집이 있는 위치는 1이고, 나머지는 0이다.

6. 도시에는 최소 1개 이상의 집이 존재한다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 도시의 크기 N과 하나의 집이 지불할 수 있는 비용 M이 주어진다.

그 다음 줄부터 N*N 크기의 도시정보가 주어진다. 지도에서 1은 집이 위치한 곳이고, 나머지는 0이다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 서비스 영역을 찾았을 때,

그 때의 서비스를 제공 받는 집들의 수이다.
*/
#include<iostream>
using namespace std;
int n, m, x;//도시 크기, 1집 지불 비용
int map[20][20] = { 0, };//1집 0
int ma = 0;

bool rng(int x, int y) //x,y가 범위 벗어나면 false
{
	if (x < 0 || y < 0 || n <= x || n <= y)
		return false;
	return true;
}
int val(int x, int y, int k)
{
	int ret = 0;
	int nx, ny;
	int f = 0;
	for (int i = -k + 1; i < k; i++)
	{
		for (int j = -k + 1; j < k; j++)
		{
			nx = x + i;
			ny = y + j;

			if (-k < i + j && -k < i - j && i + j < k && i - j < k)
			{
				f++;
				if (rng(nx, ny))
					ret += map[nx][ny];
			}
		}
	}
	if (ret*m - f >= 0)// 집*m-비용
		return ret;
	else
		return -1;

}
void chk(int x, int y) //int x,y
{

	int r = 0;

	for(int k=1;k<n+n/2;k++)
	{	r = val(x, y, k);

		if (r > ma)
			ma = r;
	}

}
int main() {

	freopen("sample_input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int z = 0; z < tc; z++) {
		cin >> n >> m;
		x = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		ma = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				chk(i, j);

		cout << "#" << z + 1 << " " << ma << endl;

	}
}