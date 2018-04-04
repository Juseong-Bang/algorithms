/*
입력
첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)

둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다. d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.

셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 빈 칸은 0, 벽은 1로 주어진다. 장소의 모든 외곽은 벽이다.

로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.

출력
로봇 청소기가 청소하는 칸의 개수를 출력한다.
*/
#include <iostream>
#include<queue>
using namespace std;
int n,m;
int ix[4]={-1,0,1,0};
int iy[4]={0,1,0,-1};
short map[50][50]={0,};
short vi[50][50]={0,};
int step=0;

typedef struct position{
	int x;
	int y;
	int w;
}pos;
queue <pos> q;
bool rng(int x,int y)//
{
	if(map[x][y]==1)
	return 	true;
	return false;
}
pair<int,int> left(int x,int y, int dir){// 왼쪽의 좌표 리턴 
	int nx=x+ix[(dir+3)%4];
	int ny=y+iy[(dir+3)%4];
	return make_pair(nx,ny);
}
int bfs(){
	int r,c,d,s=0;
	pos temp;
	pair<int,int> col;
	
	while(!q.empty()){
		r=q.front().x;
		c=q.front().y;
		d=q.front().w;
		//vi[r][c] = ++step;// 현재 위치 청소 표시
		col=left(r,c,d);// 왼쪽 탐색
		if(s==4)
		{
			s=0;
			col=left(r,c,(d+3)%4);//뒤쪽 좌표
			if(map[col.first][col.second]==1)//벽이면 
				return 0;
			q.push(pos{col.first,col.second,d});//후진
		}
		else if(vi[col.first][col.second]==0 && map[col.first][col.second]==0) //청소하지 않은 빈 공간이 있다면 
		{
			s=0;
			temp.x=col.first;
			temp.y=col.second;
			temp.w=(d+3)%4;
			q.push(temp);//회전, 이동 
			vi[col.first][col.second]=++step;//청소 표시
			//cout<<"("<<col.first<<","<<col.second<<")"<<endl;
		}else if(vi[col.first][col.second]>0 || map[col.first][col.second]==1)//청소 했거나 벽이라면 
		{
			s++;//왼쪽 탐색  
			q.push(pos{r,c,(d+3)%4});// 회전
		}
		
		q.pop();
		
	}
	return 0;
}
int main(){
	
	cin>>n>>m;
	int r=0,c=0,d=0;
	cin>>r>>c>>d;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
	q.push(pos{r,c,d});
	vi[r][c]=++step;
	bfs();
	cout<<step;
	return 0;
}