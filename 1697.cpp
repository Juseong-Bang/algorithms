/*
입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std ;

int n,k;
bool visit[100001]={0,};
queue <pair<int,int> >q;

int bfs(){
int s=0;
int r=0;	
 q.push(pair<int,int> (0,n));
	visit[n]=true;
	
	while(!q.empty()){
		
	s=q.front().second;
	r=q.front().first;
	q.pop();
		
	if(s==k)
		break;
	
		if(s+1<=100000 && !visit[s+1])
		{
			visit[s+1]=true;	
			q.push(pair<int,int>(r+1,s+1));	
		}
	
		if(0<s && !visit[s-1])
	{
		visit[s-1]=true;	
		q.push(pair<int,int>(r+1,s-1));
	}
		if(2*s<=100000 && !visit[s*2])
		{
		visit[s*2]=true;	
		q.push(pair<int,int>(r+1,s*2));
		}
	}
	return r;
}
int main (){
	cin>>n>>k;
	cout<<bfs()<<endl;
}