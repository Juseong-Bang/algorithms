/*
입력
첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.

둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
10:40
*/
#include<iostream>
using namespace std;
int n;
int tp[15][2]={0,};
bool ch[15]={false,};
int mi=-1;

int pr(){
	int ret=0;
for(int i=0;i<n;i++)
{
	if(ch[i]){
		ret+=tp[i][1];
	}
}
	return ret;
	
	
}
void dfs(int day)//
{
	if(day==n){
		int m=0;
		m=pr();
		if(mi==-1 || mi<m)
		{
			mi=m;
		}
		return;
	}
	
	if(day>=n)	
		return;
	
	ch[day]=true;
	dfs(day+tp[day][0]);
	ch[day]=false;
	dfs(day+1);
	
	return;
}
int main ()
{
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>tp[i][0];
		cin>>tp[i][1];
	}
	dfs(0);
	cout<<mi;
	return 0;
}
