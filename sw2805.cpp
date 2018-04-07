/*
[제약 사항]

농장의 크기 N은 1 이상 49 이하의 홀수이다. (1 ≤ N ≤ 49)

농작물의 가치는 0~5이다.

[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스에는 농장의 크기 N과 농장 내 농작물의 가치가 주어진다.


[출력]

각 줄은 '#t'로 시작하고, 공백으로 농장의 규칙에 따라 얻을 수 있는 수익을 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/
#include<iostream>
#include<stdio.h>
using namespace std;

int val = 0;
int map[50][50] = { 0, };
int n, m;

int main() {
	int tc;
	cin >> tc;
	for (int z = 0; z < tc; z++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		val = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				if (i - j <= n / 2  && j-i <=n/2 && n/2 <= i + j && i+j < n / 2 + n)
			val += map[i][j];
			}
		}
		cout << "#" << z + 1 << " " << val << endl;
	}
}