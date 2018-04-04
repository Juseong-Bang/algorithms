/*
입력
첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>

using namespace std;


bool  map[100][100]={false,};
int  visit[100][1024]={false,};
int ix[4]={0,1,-1,0};
int iy[4]={1,0,0,-1};
int m=0,n=0;
	

int bfs(){

	int x=0,y=0;
queue<pair<int,int> > q;

	q.push(pair<int,int>(x,y) );
	visit[x][y]=1;
	
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		
		if(x==n && y==m)
			break;
		
		for(int a=0;a<4;a++){
			int nx=x+ix[a];
			int ny=y+iy[a];
			
			if((0<=nx && nx<n ) && (0<=ny && ny<m) && map[nx][ny] && visit[nx][ny]==0){
			visit[nx][ny]=visit[x][y]+1;	
			q.push(pair<int,int>(nx,ny));
			}
			
		}
		
	}
	 /*for(int i=0;i<n; i++){
        for(int j=0; j<m ; j++){
            cout << visit[i][j];
        }
        cout << endl;
    }
	*/
	
	return visit[n-1][m-1];
	
}
int main (){
		cin>>n>>m;
	
	int h=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&h);
			if(h == 1)
				map[i][j]=true;
			else
			map[i][j]=false;
		}
	}
	
	/* for(int i=0;i<n; i++){
        for(int j=0; j<m ; j++){
           if(map[i][j])
						 cout<<"1";
					else
						cout<<"0";
        }
        cout << endl;
    }
	cout << endl;
	*/
	cout<<bfs();
	return 0;
	
}
