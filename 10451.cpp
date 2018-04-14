/*
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 순열의 크기 N (2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 순열이 주어지며, 각 정수는 공백으로 구분되어 있다.

출력
각 테스트 케이스마다, 입력으로 주어진 순열에 존재하는 순열 사이클의 개수를 출력한다.
*/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
int tb[1000] = { 0, };
int vi[1000] = { 0, };
queue<int> q;

int bfs()
{
	int cnt = 0,ns;
	for (int i = 0; i < n; i++)
	{
		if (vi[i] == 0)
		{
			q.push(i);
			vi[i] = ++cnt;
			while (!q.empty())
			{
				ns = q.front();
				q.pop();
				if (vi[tb[ns]] == 0) {
					q.push(tb[ns]);
					vi[tb[ns]] = cnt;
				}
			}
		}
	}
	return cnt;
}
int main()
{
	int x = 0;
	cin >> x;

	for (int tc = 0; tc < x; tc++)
	{
		cin >> n;
		int tm = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tm;
			tb[i] = tm - 1;

		}
		memset(vi, 0, sizeof(vi));
		cout << bfs() << endl;
	}
	return 0;
}