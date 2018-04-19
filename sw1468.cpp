/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 N, B(1 ≤ N ≤ 20, 1 ≤ B ≤ S)가 공백으로 구분되어 주어진다.

S는 두 번째 줄에서 주어지는 점원들 키의 합이다.

두 번째 줄에는 N개의 정수가 공백으로 구분되어 주어지며, 각 정수는 각 점원의 키 Hi (1 ≤ Hi ≤ 10,000)을 나타낸다.


[출력]

각 테스트 케이스마다 첫 번째 줄에는 ‘#t’(t는 테스트 케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 만들 수 있는 높이가 B 이상인 탑 중에서 탑의 높이와 B의 차이가 가장 작은 것을 출력한다.


[예제 풀이]

테스트 케이스의 경우 키가 3, 3, 5, 6인 점원이 탑을 만들면 높이가 17(3 + 3 + 5 + 6)이 된다.

높이가 16인 탑은 만들 수 없으므로 높이가 17인 탑이 문제에서 구하려는 탑의 높이이다. 따라서 17 – 16 = 1이 답이 된다.
*/
#include<iostream>
#include<cstring>

using namespace std;
long n, b;//사람 수 , 선반 높이 
int t[20] = { 0, };
bool vi[20] = { false, };
long cal()
{
	long ret = 0;
	for (int i = 0; i < n; i++)
		if (vi[i])
			ret += t[i];
	return ret;
}
long mi = -1;
void dfs(int cur)
{

	if (cur == n)
	{
		long rr = cal();
		if (rr >= b)
			if (mi == -1 || mi > rr)
				mi = rr;

		return;
	}
	else {
		vi[cur] = true;
		dfs(cur + 1);
		vi[cur] = false;
		dfs(cur + 1);
	}

}
int main()
{
	int x;
	freopen("input.txt", "r", stdin);
	cin >> x;
	for (int tc = 0; tc < x; tc++)
	{
		cin >> n >> b;
		memset(vi, 0, sizeof(vi));
		mi = -1;
		for (int i = 0; i < n; i++)
			cin >> t[i];
		dfs(0);

		cout << "#" << tc + 1 << " " << mi - b << endl;
	}
	return 0;
}