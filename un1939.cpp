/*
문제
N(2≤N≤10,000)개의 섬으로 이루어진 나라가 있다. 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.

영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다.
물품을 생산하다 보면 공장에서 다른 공장으로 생산 중이던 물품을 수송해야 할 일이 생기곤 한다.
그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다. 만약 중량제한을 초과하는 양의 물품이 다리를 지나게 되면 다리가 무너지게 된다.

한 번의 이동에서 옮길 수 있는 물품들의 중량의 최대값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, M(1≤M≤100,000)이 주어진다. 다음 M개의 줄에는 다리에 대한 정보를 나타내는 세 정수 A, B(1≤A, B≤N), C(1≤C≤1,000,000,000)가 주어진다.
이는 A번 섬과 B번 섬 사이에 중량제한이 C인 다리가 존재한다는 의미이다.

서로 같은 두 도시 사이에 여러 개의 다리가 있을 수도 있으며, 모든 다리는 양방향이다.

마지막 줄에는 공장이 위치해 있는 섬의 번호를 나타내는 서로 다른 두 정수가 주어진다.
공장이 있는 두 섬을 연결하는 경로는 항상 존재하는 데이터만 입력으로 주어진다.

출력
첫째 줄에 답을 출력한다.
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, s, d;//섬,다리,시작,끝
int b[100000][2] = { 0, };//다리 연결정보 ,양방향
long c[100000] = { 0, };//중량 정보
bool vi[100000] = { false, };
typedef struct bridge {
	int s;
	int e;
	long w;
}bg;

queue <bg> q;//연결 지점, 현재 연결들의 중량제한 최소값 

int bfs()
{
	int ns, ne;
	bg e;
	long nc,mx = -1;

	e.s = -1;
	e.e = s;
	e.w = -1;
	q.push(e);
	
	while (!q.empty())
	{
		ns = q.front().s;
		ne = q.front().e;
		nc = q.front().w;
		q.pop();

		if (ne == d) //맨끝에 도달함
		{
			if (mx < nc)
				mx = nc;
			continue;
		}

		for (int j = 0; j < m; j++)
			if (vi[j] == false)
				if (ne == b[j][0] || ne == b[j][1])//시작 또는 끝이 같다면 
				{
					vi[j] = true;
					e.s = ne;//끝점을 시작점으로 시작 
					e.e = (ne == b[j][0] ? b[j][1] : b[j][0]);

					if (nc == -1 || nc > c[j])
						e.w = c[j];
					else
						e.w = nc;

					if (mx != -1 && e.w < mx)//이미 구해진 최대 중량보다 작다면
						continue;

					q.push(e);
				}
	}
	return mx;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> b[i][0] >> b[i][1] >> c[i];

	cin >> s >> d;
	cout << bfs()<<endl;
	return 0;
}