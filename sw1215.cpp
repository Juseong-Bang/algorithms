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
