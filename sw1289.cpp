/*

예를 들어 지금 메모리 값이 0100이고, 3번째 bit를 골라 1로 설정하면 0111이 된다.

원래 상태가 주어질 때 초기화 상태 (모든 bit가 0) 에서 원래 상태로 돌아가는데 최소 몇 번이나 고쳐야 하는지 계산해보자.
*/
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