/*
[제약 사항]

가로 길이는 항상 100으로 주어진다.

모든 위치에서 상자의 높이는 1이상 100이하로 주어진다.

덤프 횟수는 1이상 1000이하로 주어진다.

주어진 덤프 횟수 이내에 평탄화가 완료되면 더 이상 덤프를 수행할 수 없으므로 그 때의 최고점과 최저점의 높이 차를 반환한다 (주어진 data에 따라 0 또는 1이 된다).

[입력]

총 10개의 테스트 케이스가 주어지며, 각 테스트 케이스의 첫 번째 줄에는 덤프 횟수가 주어진다. 그리고 다음 줄에 각 상자의 높이값이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 최고점과 최저점의 높이 차를 출력한다.
*/
#include<iostream>
using namespace std;
int g[100] = { 0, };// 땅의 높이 저장 
int ga() {// 최대값 주소 리턴 
	int k = 0, d = 0;
		for(int i=0;i<100;i++)
			if (k < g[i])
			{
				k = g[i];
				d = i;
			}
		return d;
}
int gi() {// 최소 주소 리턴 
	int k = -1, d = 0;
	for (int i = 0; i<100; i++)
		if (k > g[i] || k==-1)
		{
			k = g[i];
			d = i;
		}

	return d;
}
int main() {

	freopen("input.txt", "r", stdin);
	
	for (int tc = 0; tc < 10; tc++) {
		int ret = 0, n = 0;
		cin >> n;

		for (int i = 0; i < 100; i++)
			cin >> g[i];
		
		int h=0, l=0;
		for (int i = 0; i < n; i++)
		{
			h=ga();
			l=gi();

			g[h]--;
			g[l]++;

			ret = g[h] - g[l];
			
			if (ret == 0 || ret == 1)
				break;
		}
		h = ga();
		l = gi();
		ret = g[h] - g[l];


		
	
		cout << "#" << tc + 1 << " " << ret << endl;
	}
}