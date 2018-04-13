/*
입력
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

출력
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다.
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

			if (v[i])//2행에 있음
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