/*
	 문제
	 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
	 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
	 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

	 입력
	 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
	 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
	 한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 
	 입력으로 주어지는 간선은 양방향이다.

	 출력
	 첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다.
	 V부터 방문된 점을 순서대로 출력하면 된다.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool> > map;
vector<bool> visited;
int n; // 정점의 개수
queue<int> q;

void DFS(int cur) {
	visited[cur] = true;//현재 노드  표시
	printf("%d ", cur);
	for (int i = 1; i <= n; i++)//모든 정점을 검사 
		if (map[cur][i] && !visited[i])//만약 현재 노드와 연결되어 있으면서 방문하지 않았다면 
			DFS(i);//방문 
}

void BFS(int cur) {
	visited[cur] = true;// 현재 노드 표시 
	q.push(cur);	//현재 노드를 큐에 넣는다 
	while (!q.empty()) { //큐가 비어있을 떄 까지 
		printf("%d ", cur);
		for(int i=1;i<=n;i++)//모든 정점을 검사 
			if (map[cur][i] && !visited[i]) {// 현재 노드와 연결 그리고 방문하지 않았다면 
				visited[i] = true;//표시 후 
				q.push(i);//큐에 넣는다 
			}
// 현재 노드와 연결된 노드들을 큐에 넣은뒤 
		q.pop();//하나 꺼낸다 
		if(!q.empty())// 만약 큐가 비어있지 않다면 
			cur = q.front();//꺼낸 노드를 현재 노드로 설정한다 (while문 반복)
	}
}

int main() {
	int m, v, x, y;
	cin.sync_with_stdio(false);
	cin >> n >> m >> v;

	map.assign(n + 1, vector<bool>(n + 1, false));
	visited.assign(n + 1, false);

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = true;
		map[y][x] = true;
	}
	DFS(v);//시작 노드인 v를 입력 

	printf("\n");
	visited.clear();
	visited.assign(n + 1, false);
	BFS(v);
	return 0;
}
