/*
�Է�
ù° �ٿ��� N(1��N��100)�� ��Ÿ���� ���� �ϳ��� �־�����. �� ���� �ٺ��ʹ� ǥ�� ��° �ٿ� ���� �������� ������� �� �ٿ� �ϳ��� �Էµȴ�.

���
ù° �ٿ� ���� �������� ������ ����ϰ�, �� ���� �ٺ��ʹ� ���� �������� ���� ������ ū ���� ������ �� �ٿ� �ϳ��� ����Ѵ�.
*/
#include<iostream>
using namespace std;
int ta[2][101] = { 0, };
int n;
bool v[101] = { false, };

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ta[0][i] = i;
		cin >> ta[1][i];
	}

	for (int i = 1; i <= n; i++)
		v[ta[1][i]] = true;

	int j, cnt = 0;

	while (1)
	{
		bool tk = false;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{

			if (v[i])//2�࿡ ����
			{
				cnt++;
				for (j = 1; j <= n; j++)
					if (v[j] && (ta[0][i] == ta[1][j]))
						break;

				if (j > n)
				{
					v[ta[0][i]] = false;
					tk = true;
					cnt--;
				}
			}
		}
		if (tk == false)
			break;
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (v[i])
			cout << i << endl;


	return 0;
}