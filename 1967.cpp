/*
Ʈ��(tree)�� ����Ŭ�� ���� ������ �׷����̴�. Ʈ�������� � �� ��带 �����ص� �� ���̿� ��ΰ� �׻� �ϳ��� �����ϰ� �ȴ�. Ʈ������ � �� ��带 �����ؼ� �������� �� ��� ��, ���� ��� �þ�� ��찡 ���� ���̴�. �̷� �� Ʈ���� ��� ������ �� �� ��带 ������ �� ������ �ϴ� �� �ȿ� ���� �ȴ�.
�̷� �� ��� ������ ����� ���̸� Ʈ���� �����̶�� �Ѵ�. ��Ȯ�� �������ڸ� Ʈ���� �����ϴ� ��� ��ε� �߿��� ���� �� ���� ���̸� ���Ѵ�.
�Է����� ��Ʈ�� �ִ� Ʈ���� ����ġ�� �ִ� ������� �� ��, Ʈ���� ������ ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. �Ʒ��� ���� Ʈ���� �־����ٸ� Ʈ���� ������ 45�� �ȴ�.

�Է�
������ ù ��° ���� ����� ���� n (1��n ��10000)�̴�. ��° �ٺ��� n ��° �ٱ��� �� ������ ���� ������ ���´�. ������ ���� ������ �� ���� ������ �̷���� �ִ�. ù ��° ������ ������ �����ϴ� �� ��� �� �θ� ����� ��ȣ�� ��Ÿ����, �� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ�� ��Ÿ����. ������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�, �θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�. ��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�.

���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, x, y;
char map[10000][10000] = { 0, };
bool vi[10000] = { false, };
queue <pair<int, int > > q;//������, ����ġ 
int bfs(int st)
{

	vi[st] = true;
	for (int i = 0; i < n; i++)
		if (map[st][i] > 0)
		{
			vi[i] = true;
			q.push(make_pair(i, map[st][i]));//st�� ����� ���� 
		}

	int cur, we, mx = 0;

	while (!q.empty())
	{
		cur = q.front().first;
		we = q.front().second;
		q.pop();

		if (mx < we)
		{
			mx = we;
			x = cur;
		}

		for (int i = 0; i < n; i++)
		{
			if (!vi[i] && map[cur][i] > 0)
			{
				vi[i] = true;
				q.push(make_pair(i, we + map[cur][i]));
			}
		}
	}
	return mx;
}

int main()
{
	int p, c, w;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> p >> c >> w;
		map[p - 1][c - 1] = w;
		map[c - 1][p - 1] = w;
	}
	int ret = 0;

	bfs(0);
	memset(vi, 0, sizeof(vi));
	ret = bfs(x);
	cout << ret;
}