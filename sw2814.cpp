/*
N개의 정점과 M개의 간선으로 구성된 가중치가 없는 무방향 그래프에서의 최장 경로의 길이를 계산하자.
정점의 번호는 1번부터 N번까지 순서대로 부여되어 있다.
경로에는 같은 정점의 번호가 2번 이상 등장할 수 없으며, 경로 상의 인접한 점들 사이에는 반드시 두 정점을 연결하는 간선이 존재해야 한다.
경로의 길이는 경로 상에 등장하는 정점의 개수를 나타낸다.
[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 두 개의 자연수 N M(1 ≤ N ≤ 10, 0 ≤ M ≤ 20)이 주어진다.
두 번째 줄부터 M개의 줄에 걸쳐서 그래프의 간선 정보를 나타내는 두 정수 x y(1 ≤ x, y ≤ N)이 주어진다.
x와 y는 서로 다른 정수이며, 두 정점 사이에 여러 간선이 존재할 수 있다.
[출력]
각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 그래프에서의 최장 경로의 길이를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#pragma warning(disable: 4996)

using namespace std;

int n, m, ma = -1;
int map[10][10] = { 0, };//map
int vi[10] = { 0, };

void dfs(int cur, int cnt) {
	if (ma < cnt)
		ma = cnt;

	vi[cur] = cnt;//현재 선택된 노드에 방문 표시 

	for (int i = 0; i < n; i++)// 모든 노드에 대해서 
	{
		if (map[cur][i] == 1 && vi[i] == 0)//cur과 연결되고 방문하지 않은 노드 i에 대해서 
		{
			dfs(i, cnt + 1);//i를 선택, 갯수+1
		}
	}
	vi[cur] = 0;// 방문 후 해제 

	return;
}

int main() {
	int a, b, t = 0;
	freopen("sample_input.txt", "r", stdin);
	cin >> t;//테스트 케이스 

	for (int k = 0; k < t; k++)//
	{
		cin >> n >> m;//n 노드수 m 간선 수 

		memset(map, 0, sizeof(map));//map 초기화

		for (int h = 0; h < m; h++)
		{
			cin >> a >> b;
			map[a - 1][b - 1] = 1;
			map[b - 1][a - 1] = 1;
		}

		ma = -1;

		for (int i = 0; i < n; i++)
		{
			memset(vi, 0, sizeof(vi));//방문 초기화!!!!
			dfs(i, 1);//cur,cnt
		}

		cout << "#" << k + 1 << " " << ma << endl;
	}
	return 0;
}