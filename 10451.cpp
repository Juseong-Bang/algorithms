/*
�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� N (2 �� N �� 1,000)�� �־�����. ��° �ٿ��� ������ �־�����, �� ������ �������� ���еǾ� �ִ�.

���
�� �׽�Ʈ ���̽�����, �Է����� �־��� ������ �����ϴ� ���� ����Ŭ�� ������ ����Ѵ�.
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