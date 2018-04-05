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