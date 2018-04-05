#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char bits[50] = { 0, };
int main() {
	int tc, cnt;
	cin >> tc;

	for (int k = 0; k < tc; k++) {

		int b = 0;
		int l = 0;

		scanf("%s", bits);

		cnt = 0;
		l = strlen(bits);
		b = bits[l - 1];

		for (int i = l - 2; i >= 0; i--)
		{
			if (b != bits[i])
			{
				cnt++;
				b = bits[i];
			}
		}


		if (bits[0]-'0' == 1)
			cnt++;

		cout << "#" << k + 1 << " " << cnt << endl;

	}
	return 0;

}