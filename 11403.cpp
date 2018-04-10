/*
����
����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٺ��� N�� �ٿ��� �׷����� ���� ����� �־�����.
i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�, 0�� ���� ���ٴ� ���̴�.
i��° ���� i��° ���ڴ� �׻� 0�̴�.

���
�� N���� �ٿ� ���ļ� ������ ������ ������� �������� ����Ѵ�.
���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����ؾ� �Ѵ�.
*/
#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[100][100] = { 0, };
int rnd[100][100] = { 0, };
int vi[100] = { 0, };
queue<pair<int, int > > q;
int n;
void bfs()
{
	int s, t;

	for (int i = 0; i < n; i++)
	{
		memset(vi, 0, sizeof(vi));
		q.push(make_pair(i, 0));
		//vi[i] = true;
		while (!q.empty())
		{
			s = q.front().first;
			t = q.front().second;
			q.pop();
			for (int j = 0; j < n; j++)
			{
			//	if (j == s)
			//		continue;
				if (map[s][j] == 1 && !vi[j])
				{
					vi[j] = s + 1;
					q.push(make_pair(j, s + 1));
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (vi[j] > 0)
				rnd[i][j] = 1;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << rnd[i][j] << " ";
		cout << endl;
	}
}