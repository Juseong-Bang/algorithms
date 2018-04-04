/*
[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 방의 한 변의 길이 N이 주어진다.

다음 N줄에는 N*N 크기의 지도의 정보가 주어진다.

지도에서 1은 사람을, 2 이상은 계단의 입구를 나타내며 그 값은 계단의 길이를 의미한다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

정답은 이동이 완료되는 최소의 시간을 출력한다.
*/
#include<iostream>
using namespace std;
int n,e=0,mi=-1;
int map[10][10]={0,};
pair<int,int> st[2];
pair<int,int> pe[10];
bool ch[10]={false,};
int ti(int num, int s)//사람 번호 , 출구 번호 가는 시간 리턴  
{
	int x= st[s].first-pe[num].first;
	int y= st[s].second-pe[num].second;
	int ret= (x>0?x:-x) + (y>0?y:-y);
	return ret;
}
int cnt(){
	int tm[10][2]={0,};//입구0,1에 대한 거리순 오름차순 배열
	int tem1=-1,tem2=-1;
	int a=0;
	int v[2]={0,};//각 입구로 빠져나가는 사람의 시간 기록 
	for(int i=0;i<e;i++){
		
		if(ch[i]) 
			a=0;//0번 출구
		else
			a=1;//1번 출구
			
		tem1=ti(i,a);//거리 받아옴 
		if(v[a]++==0)//만약 배열이 비어있다면 
				tm[0][a]=tem1;//첫번쨰 기록 
		else
		{
			for(int j=0;j<v[a]-1;j++)//비교 
				if(tem1<tm[j][a])
				{//더 작은게 앞으로 
					tem2=tm[j][a];
					tm[j][a]=tem1;
					tem1=tem2;
				}
			tm[v[a]-1][a]=tem1;//마지막 원소 삽입
		}
	}
	/*
	for(int i=0;i<2;i++){
		for(int x=0;x<v[i];x++){
			cout<<tm[x][i]<<",";
		}
		cout<<endl;
		}
	*/
	int ma=-1;
	int l=0,x;
	for(int i=0;i<2;i++)//0번과 1번
	{
		l=map[st[i].first][st[i].second];//계단 길이
		for(int cur=0;cur<v[i];cur++)//cur은 지금 고려하는 사람
		{
			if(cur<3)//3명미만일떄
			{
				tm[cur][i]+=(l+1);//현재로부터 l+1 분뒤 나갈수 있음
			}
			else//3명 이상일떄 
			{
				if(tm[cur][i] < tm[cur-3][i])//3명 이전의 사람이 안나갓다면 
				tm[cur][i]+=(l + tm[cur-3][i]-tm[cur][i]);//그사람이 나가는 시간+ 통로를 빠져나가는 시간
				else
					tm[cur][i]+=(l+1);//현재로부터 l+1 분뒤 나갈수 있음
			}
		}
	}
	if(v[0]!=0 && v[1]!=0)
		return ((tm[v[0]-1][0]-tm[v[1]-1][1])>0) ? tm[v[0]-1][0] : tm[v[1]-1][1];//둘중에 큰거 출력
	else if(v[0]==0)
		return tm[v[1]-1][1];
	else
		return tm[v[0]-1][0];
}
void dfs(int cur){
	if(cur==e){
		int r=cnt();
	//	cout<<"@"<<r<<endl;
		if(mi==-1||r<mi)
			mi=r;
		return;
	}
	ch[cur]=true;
	dfs(cur+1);
	ch[cur]=false;
	dfs(cur+1);
	
	return;
	
}
int main(){
	int c,p,a=0;
	cin>>c;
	for(int q=0;q<c;q++){
	cin>>n;
	e=0;
	a=0;
	mi=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>p;
			map[i][j]=p;
			if(p==1){//사람인 경우 
				pe[e++]=make_pair(i,j);//e는 사람 수
			}
			else if(p>1)//통로인 경우
				st[a++]=make_pair(i,j);
		}
	}
		dfs(0);
		cout<<"#"<<q+1<<" "<<mi<<endl;
}
}