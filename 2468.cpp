/*
입력
첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. N은 2 이상 100 이하의 정수이다. 둘째 줄부터 N 개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다. 각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N 개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다. 높이는 1이상 100 이하의 정수이다. 

출력
첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다. 
*/
#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
int n,m,l=101;
int map[101][101]={0,};
int vi[101][101]={0,};
int nx[4]={-1,0,0,1};
int ny[4]={0,-1,1,0};
queue <pair<int,int> > q;
int bfs(){
int ret=0;
	
	for(int h=l-1;h<m+1;h++)
	{
		int x,y,cnt=0;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(map[i][j]>h && vi[i][j]==0){
					vi[i][j]=++cnt;
					q.push(pair<int,int>(i,j));
					
					while(!q.empty()){
						x=q.front().first;
						y=q.front().second;
						q.pop();
						
						for(int k=0;k<4;k++){
						
							if(0<=x+nx[k] && 0<=y+ny[k] && x+nx[k]<n+1 && y+ny[k] <n+1 ){
								if(map[x+nx[k]][y+ny[k]]>h && vi[x+nx[k]][y+ny[k]]==0){
								vi[x+nx[k]][y+ny[k]]=cnt;
								q.push(pair<int ,int> (x+nx[k],y+ny[k]));
							}}}}
					
				}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<vi[i][j]<<" ";
		cout<<endl;
		}
		*/
		if(cnt>ret)
			ret=cnt;
		memset(vi,0,sizeof(vi));
//	cout<<h<<endl;
	}
	
return ret;
}	

int main (){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
	{
		cin>>map[i][j];
		if(m<map[i][j])
			m=map[i][j];
			if(l>map[i][j])
				l=map[i][j];
	}
	//	cout<<endl;
	cout<<bfs()<<endl;
}