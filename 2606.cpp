/*
입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.s
 */

#include<iostream>
#include<queue>


using namespace std;
int n=0;//computer
int v=0;//vertex
bool map[101][101]={false,};
int visit[101]={0,};
queue <int> q;

int bfs(){
	int ret=-1;
	int c=0;
	
	visit[1] = 1;
	q.push(1);
	//cout<<endl;
	while(!q.empty()){
		
		c=q.front();
		q.pop();
		
		ret++;
		
		for(int i=2;i<=n;i++)
			if( map[c][i]== true && visit[i] == 0)
			{
				visit[i]=1;
				q.push(i);
				//cout<<c<<","<<i<<endl;
			}
	}
	
	return ret;
}


int main(){
	cin>>n>>v;

		int x,y;
	
	for(int i=0;i<v;i++)
	{
		cin>>x>>y;
		map[x][y]=true;
		map[y][x]=true;
	}
	
	cout<<bfs()<<endl;
}
