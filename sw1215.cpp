/*
[입력]

각 테스트 케이스의 첫 번째 줄에는 찾아야 하는 회문의 길이가 주어지며, 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.


[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 찾은 회문의 개수를 출력한다.
*/
#include<iostream>
#include<stdio.h>
using namespace std;
char map[8][8] = { 0, };
int cnt = 0;
int main() {
	freopen("input.txt", "r", stdin);
	int l = 0;
	for (int k = 0; k < 10; k++) {
		cin >> l;
		cnt = 0;

		for (int i = 0; i < 8; i++)
			scanf("%s", map[i]);

		int t = 0;
		int hl = l / 2;

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8 - l + 1; j++)
			{
				for (t = 0; t < hl; t++)
				{
					if (map[i][j + t] != map[i][j + (l - 1 - t)])
						break;
				}

				if (t == hl)
					cnt++;
			}

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8 - l + 1; j++)
			{
				for (t = 0; t < hl; t++)
				{
					if (map[j + t][i] != map[j + (l - 1 - t)][i])
						break;
				}
				if (t == hl)
					cnt++;
			}


		cout << "#" << k + 1 << " " << cnt << endl;
	}
}
