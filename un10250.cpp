/*
입력
프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T 개의 테스트 데이터로 이루어져 있는데 T 는 입력의 맨 첫 줄에 주어진다. 각 테스트 데이터는 한 행으로서 H, W, N, 세 정수를 포함하고 있으며 각각 호텔의 층 수, 각 층의 방 수, 몇 번째 손님인지를 나타낸다(1 ≤ H, W ≤ 99, 1 ≤ N ≤ H × W).

출력
프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행을 출력하는데, 내용은 N 번째 손님에게 배정되어야 하는 방 번호를 출력한다.
	*/
#include<iostream>
using namespace std;
int main()
{
	int h[1024], w, n[1024];
	int k = 0;
	cin >> k;
	for (int p = 0; p < k; p++) {
		cin >> h[p] >> w >> n[p];
	}
	for (int p = 0; p < k; p++) {

		cout << n[p] % h[p];
		cout.fill('0');
		cout.width(2);
		if (h[p] == 0)
			h[p] = 1;

		cout << (n[p] / h[p]) + 1 << endl;

	}

}
