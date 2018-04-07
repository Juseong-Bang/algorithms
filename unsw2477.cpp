/*
[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초

2. 접수 창구의 개수 N과 정비 창구의 개수 M은 1 이상 9 이하의 정수이다. (1 ≤ N, M ≤ 9)

3. 접수 창구 i에서 고장을 접수하는 처리 시간 ai는 1 이상 20 이하의 정수이다. (1 ≤ ai ≤ 20)

4. 정비 창구 j에서 차량을 정비하는 처리 시간 bj는 1 이상 20 이하의 정수이다. (1 ≤ bj ≤ 20)

5. 차량 정비소를 방문한 고객의 수 K는 2 이상 1,000 이하의 정수이다. (2 ≤ K ≤ 1,000)

6. 고객 k의 도착 시간 tk는 0 이상 1,000 이하의 정수이다. (0 ≤ tk ≤ 1,000)

7. 지갑을 두고 간 고객이 이용한 접수 창구번호 A는 1 이상 N 이하의 정수이다. (1 ≤ A ≤ N)

8. 지갑을 두고 간 고객이 이용한 정비 창구번호 B는 1 이상 M 이하의 정수이다. (1 ≤ B ≤ M)

9. 창구번호와 고객번호는 1부터 시작한다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 접수 창구의 개수 N, 정비 창구의 개수 M, 차량 정비소를 방문한 고객의 수 K, 지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B가 주어진다.

두 번째 줄에는 i번째 접수 창구가 고장을 접수하는 데 걸리는 시간 ai가 N개 주어진다.

세 번째 줄에는 j번째 정비 창구가 차량을 정비하는 데 걸리는 시간 bj가 M개 주어진다.

네 번째 줄에는 k번째 고객이 차량 정비소를 방문하는 시간 tk가 순서대로 K개 주어진다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 지갑을 두고 간 고객과 같은 접수 창구 A와 같은 정비 창구 B를 이용한 고객들의 고객번호의 합이다. 만약 그런 고객이 없는 경우 정답으로 -1을 출력한다.

*/
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int n, m, k, a, b;
int ai[9] = { 0, };
int bi[9] = { 0, };
int tk[1000] = { 0, };
int rec[1000][2] = { 0, };

queue<int> nq[9];//접수 큐
queue<int> mq[9];//정비 큐

queue<int> tq;//손님 도착 큐
queue<int> wq;//정비 대기 큐

void cal() {

	int t = 0;
	int cn = 0;

	while (1)
	{
		while (tk[cn] == t)//cn번째 손님이 온 시간 이 t라면 
		{
			tq.push(cn);// 손님 번호 inq
			cn++;//다음 손님 검사 
		}
		t++;//시간 지나감 
		
		for (int i = 0; i < n; i++) // 모든 접수 큐에서 
		{
			if (tq.empty())// 대기 손님이 없을떄까지 
				break;

			if (nq[i].empty()) //i번쨰 접수 창구 비엇다면 
			{
				for (int j = 0; j < ai[i]; j++)// 소요되는 시간만큼 
					nq[i].push(tq.front());//해당 q에 손님 넣음
				
				tq.pop();//대기 1손님 deq 
			}

		}
		if (t == 1)
			continue;
		
		int cos = 0;


		for (int i = 0; i < n; i++)//접수 일하기  
		{
			if (nq[i].empty())//비어있는 접수는 넘어감 
				continue;

			cos = nq[i].front();// 접수 1명 일하면 
			nq[i].pop();//꺼냄 

			if (nq[i].empty())//마지막이엿다면? 
			{
				rec[cos][0] = i;//cos번 손님은 i번 접수 이용
				wq.push(cos);//1명 정비 대기 큐 inq 
			}
		}
		cos = 0;
		for (int i = 0; i < m; i++)//정비 일하기 
		{
			if (mq[i].empty())//만약 정비 큐가 비어있다면 
				continue;//넘어감

			cos = mq[i].front();
			mq[i].pop();

			if (mq[i].empty()) // 수리가 끝남 
			{
				rec[cos][1] = i;//cos번 손님은 i번 정비 이용
			}
		}

		for (int i = 0; i < m; i++)// 모든 수리 큐에서  
		{
			if (wq.empty())// 정비 대기 손님이 없을떄까지 
				break;

			if (mq[i].empty()) //i번쨰 정비 비엇다면 
			{
				for (int j = 0; j < bi[i]; j++)
					mq[i].push(wq.front());//해당 q에 손님 넣음 
				wq.pop();
			}

		}

		if (cn < k)//모든 손님이 다 왓다면 
			continue;

		for (int i = 0; i < n; i++)//접수 큐가 비엇고 
			if (!nq[i].empty())
				continue;

		for (int i = 0; i < m; i++)//수리 큐가 비었을때 
			if (!mq[i].empty())
				continue;

		//	cout << "t:" << t<<endl;

		return;// 모든 일 끝남

	}
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	int c = 0, ret = 0;
	cin >> c;

	for (int tc = 0; tc < c; tc++)
	{
		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++)
			cin >> ai[i];
		for (int i = 0; i < m; i++)
			cin >> bi[i];
		for (int i = 0; i < k; i++)
			cin >> tk[i];

		if (tc != 1)
			continue;
		ret = 0;
		memset(rec, 0, sizeof(rec));
		cal();

		for (int i = 0; i < k; i++) {

			if (a - 1 == rec[i][0] && b - 1 == rec[i][1])
				ret += i + 1;
			//if(tc==1)cout << rec[i][0] << " " << rec[i][1] << endl;
		}
		if (ret == 0)
			ret = -1;

		cout << "#" << tc + 1 << " " << ret << endl;
	}
}
