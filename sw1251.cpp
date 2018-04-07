/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15StKqAQkCFAYD&categoryId=AV15StKqAQkCFAYD&categoryType=CODE
[입력]

가장 첫 줄은 전체 테스트 케이스의 수이다.

각 테스트 케이스의 첫 줄에는 섬의 개수 N이 주어지고 (1≤N≤1,000),

두 번째 줄에는 각 섬들의 정수인 X좌표, 세 번째 줄에는 각 섬들의 정수인 Y좌표가 주어진다 (0≤X≤1,000,000, 0≤Y≤1,000,000).

마지막으로, 해저터널 건설의 환경 부담 세율 실수 E가 주어진다 (0≤E≤1).

[출력]

각 테스트 케이스의 답을 순서대로 출력하며, 각 케이스마다 줄의 시작에 “#C”를 출력하여야 한다. 이때 C는 케이스의 번호이다.

같은 줄에 빈칸을 하나 두고, 주어진 입력에서 모든 섬들을 잇는 최소 환경 부담금을 소수 첫째 자리에서 반올림하여 정수 형태로 출력하라.
*/
#include<iostream>
#include<math.h>
using namespace std;
int c;//case
int n;//섬의 수 
double e;//세율
long long s[1000][2];//x,y
double t[1000][1000];//s1과 s2를 직접 이었을때 세금 

double cost(int s1, int s2) {
	return (pow(s[s1][0] - s[s2][0], 2) + pow(s[s1][1] - s[s2][1], 2))*e;
}

long long tax() {
	double ret = 0;
	bool g[1000] = { false, };
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			t[i][j] = cost(i, j);
			t[j][i] = t[i][j];
			//	cout<<t[i][j]<<endl;
		}

	double min = 0;
	int s1, s2 = 0;
	g[0] = true;//시작점 하나 고름

	for (int u = 0; u < n; u++)
	{
		min = 0;

		for (int i = 0; i < n; i++) {

			if (g[i])//그룹이 아닌점은 pass  
				for (int j = 0; j < n; j++)
				{
					if (!g[j])//연결 그룹에 속해있지 않다면 
					{
						if (min == 0)
						{
							min = t[i][j];//초기 설정 
							s2 = j;
						}
						else if (t[i][j] < min) {
							min = t[i][j];//최소 비용 저장
							s2 = j;//연결 섬 저장
						}

					}
				}
		}
		g[s2] = true;
		ret += min;
		//		cout<<s2<<":"<<ret<<endl;

	}//
	return (long long)(ret + 0.5);
}
int main()
{
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s[j][0];
		}
		for (int j = 0; j < n; j++) {
			cin >> s[j][1];
		}
		cin >> e;
		//		tax();
		cout << "#" << i + 1 << " " << tax() << endl;
	}
}