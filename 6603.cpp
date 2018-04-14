/*
입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 숫자는 k (6 < k < 13)이고, 다음 k개 숫자는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스 마다 숫자를 고르는 모든 방법을 출력한다. 이 때, 사전 순으로 출력한다.

각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.

*/
#include<iostream>

using namespace std;
int set[15] = { 0, };
bool ch[15] = { false, };
int k;
void dfs(int cur, int num)//현재 탐색중인 번호 주소, 총 선택한 갯수 
{

	if (cur == k && num == 6)//현재 끝번호 까지 탐색했고 갯수가 6인경우(모든 검사 뒤) 
	{
		for (int i = 0; i < k; i++) {
			if (ch[i])
				cout << set[i] << " ";
		}
		cout << endl;
	}

	if (cur == k)
		return;

	ch[cur] = true;
	dfs(cur + 1, num + 1);
	ch[cur] = false;
	dfs(cur + 1, num);

}
int main() {
	k = 0;
	while (1) {
		cin >> k;
		if (k == 0)
			return 0;

		for (int i = 0; i < k; i++) {
			cin >> set[i];
		}

		dfs(0, 0);
		cout << endl;
	}
}