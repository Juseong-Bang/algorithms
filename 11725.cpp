/*
문제
루트 없는 트리가 주어진다. 이 때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
*/
#include <iostream>
#include <queue>

using namespace std;
int n;
queue <int >q;
int par [100001]={0,};
int map1 [100001]={0,};
int map2 [100001]={0,};
void parent(){
	
	int p=1, c=0;
	q.push(p);
	
while(!q.empty())
{	
	p=q.front();
	q.pop();
	
	for(int i=2;i<=n;i++){
		c=i;
		if(par[c] == 0)//부모노드를 모르고 
		if(map1[p] == c || map2[p] == c){//만약 부모노드와 연결되어 있다면 
			{
				par[c] = p;// 부모노드 표시
				q.push(c);
		//		cout<<c<<" ";
			}
		}
	}

}
	
}
	
int main (){
	cin>>n;
	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;	
		map1[a]=b;
		map2[b]=a;
	}
	 parent();
	
for(int i=2;i<n;i++)
	cout<<par[i]<<endl;
	
}
