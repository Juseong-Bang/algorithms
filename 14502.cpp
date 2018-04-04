/*
입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
*/
#include<iostream>
#include<queue>

using namespace std;
int n,m;
int map[8][8]={0,};//map 
queue <pair<int,pair<int ,int> > > q;//bfs를 위한 큐
vector<pair<int,int> > em;//빈칸들을 저장해두는 백터
int ix[4]={0,0,-1,1};
int iy[4]={-1,1,0,0};

int ma=-1,va=0;//최댓값과 빈칸의 수를 기록
int chk[3]={-1,-1,-1};

int bfs();
void dfs(int cnt,int cur){//전체 사용한 벽수 , 전체 빈칸중 현재 고려하는 번호	
	
	if(cnt == 3 && cur == va)//현재 3개 다 골랏고 고려하는 칸이 더이상 없을떄 
	{
		for(int i=0;i<3;i++)
			map[em[chk[i]].first][em[chk[i]].second]=1; //벽 만들기
		
		int val = bfs();
		
		if(ma==-1 || val > ma)
			ma=val;
		
		for(int i=0;i<3;i++)
			map[em[chk[i]].first][em[chk[i]].second]=0; // 만든 벽 해제 
	}
	
	if(cur == va)//다 못고르고 결과에 도착하는 경우
		return ;
	
	if(cnt ==3)
	dfs(cnt,va);//3개의 벽을 모두 골랏다면 
	else{	
		chk[cnt]=cur;//현재 벽을 고르고 
		dfs(cnt+1,cur+1);// 다음 진행 
		chk[cnt]=-1;//고르지 않고 
		dfs(cnt,cur+1);//다음 진행
	}
}

bool ch(int x,int y){//범위 계산
	if(0<=x && 0<=y && x<n && y<m)
		return true;
	return false;
}

int bfs(){//count;
	int x=0,y=0,c=2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		if(map[i][j]==2){//바이러스가 있는 구역
			q.push(make_pair(c,make_pair(i,j)));//in q
			while(!q.empty()){
				x=q.front().second.first;
				y=q.front().second.second;
				c=q.front().first+1;
				q.pop();//deq
				for(int a=0;a<4;a++){//4방향으로 퍼짐 
				int nx=x+ix[a];
				int ny=y+iy[a];
					if(ch(nx,ny) && map[nx][ny]==0){//빈곳에 퍼질수 있으면 
						map[nx][ny]=c;//기록
						q.push(make_pair(c,make_pair(nx,ny)));//in q
					}
				}
			}
		}
		}
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==0)// 빈칸의 수 세기
			ret++;
			if(map[i][j]>2)
				map[i][j]=0;// 원상 복구 
		}
	}
	return ret;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			
			if(map[i][j]==0)
				em.push_back(make_pair(i,j));// 빈칸만 따로 기록
		}
	va=em.size();//사이즈 따로 저장 
	
	dfs(0,0);// dfs 시작 
	cout<<ma;// 최대값 출력 
	return 0;
}