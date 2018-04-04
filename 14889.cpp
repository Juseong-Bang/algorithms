/*
입력
첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최소값을 출력한다.
*/
#include <iostream>
using namespace std;
int n;//전체 수
int m=-1;
int map[20][20];
bool g1[20]={false,};

int dif(){
	int m1=0,m2=0;
	
	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(g1[j] && g1[i]){//g1사람들의 능력치 더하기 
				m1+=map[i][j];
				}
				if(!g1[j] && !g1[i])//g2사람들의 능력치 더하기
				{
					m2+=map[i][j];
				}
			}
	return m1-m2>0 ? m1-m2 : m2-m1;
}

void dfs(int p,int c)//1팀에 들어간 사람수,현재 고려하는 사람
{
	
	if(p == n/2 && c == n)// g1이 절반을 고름 && 끝까지 다 봣다면 
	{
		int t = dif();
		if(m == -1 || m > t)//처음이거나 저장된 min보다 최소일 경우
		{
			m = t;// 두 팀간의 전력차 저장
		}
	}
	
	if(c==n)// 끝까지 보기만 한 경우, 절반 선택 X  
		return;

			g1[c]=true;	
			dfs(p+1,c+1);//g1 사람 추가, c+1번째 고려
			g1[c]=false;
			dfs(p,c+1);//g2사람 추가  , c+1번쨰 고려
			
	
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	m=-1;
	dfs(0,0);
	cout<<m<<endl;
}