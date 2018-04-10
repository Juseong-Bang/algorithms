/*
�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� ���� �ٺ��� ������ �׽�Ʈ ���̽��� ���� ù° �ٿ��� ���߸� ���� ���߹��� ���α��� M(1 �� M �� 50)�� ���α��� N(1 �� N �� 50),
�׸��� ���߰� �ɾ��� �ִ� ��ġ�� ���� K(1 �� K �� 2500)�� �־�����.
�� ���� K�ٿ��� ������ ��ġ X(0 �� X �� M-1), Y(0 �� Y �� N-1)�� �־�����.
���
�� �׽�Ʈ ���̽��� ���� �ʿ��� �ּ��� ������������ ���� ���� ����Ѵ�.
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m, k;
queue <int > q;
int vec[2500][2] = { 0, };
bool vi[2500] = { 0, };

int bfs()
{
	memset(vi, 0, sizeof(vi));

	int pos = 0, difx = 0, dify = 0, cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (vi[i] == true)
			continue;

		q.push(i);
		vi[i] = true;
		cnt++;
		while (!q.empty())
		{
			pos = q.front();
			q.pop();

			for (int j = 0; j < k; j++)
				if (vi[j] == false)
				{
					difx = (vec[j][0] - vec[pos][0]);
					dify = (vec[j][1] - vec[pos][1]);
					difx = difx > 0 ? difx : -difx;
					dify = dify > 0 ? dify : -dify;

					if (difx + dify == 1)
					{
						vi[j] = true;
						q.push(j);
					}
				}
		}
	}
	return cnt;
}
int main()
{
	int t, x, y;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			vec[i][0] = x;
			vec[i][1] = y;
		}
		cout << bfs() << endl;
	}
	return 0;
}