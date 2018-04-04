/*
입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 

출력
첫째 줄에 만들 수 있는 식의 결과의 최대값을, 둘째 줄에는 최소값을 출력한다. 최대값과 최소값은 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 앞에서 부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.
*/
#include<iostream>
using namespace std;
int n,mi,ma;
int opt[4]={0,};
int rec[4]={0,};
int od[11]={0,};
bool first=true;
int cal(int a,int b, int op)
{
	if(op==0)return a+b;
	if(op==1)return a-b;
	if(op==2)return a*b;
	if(op==3)return a/b;
}

int dfs(int cnt,int val)//연산자의 총 갯수,지금 고른 연산자 위치(0~n-1), 현재까지 계산 값  
{
	if(cnt==n-1)//연산자를 다 고름 
	{
		if(first){
			first=false;
			mi=val;
			ma=val;
		}
		else if(val>ma)
			ma=val;
		else if(val<mi)
			mi=val;
	}
	else//아직 다 못고름
	{
		int ad=0;
		for(int i=0;i<4;i++)
		{
			if(opt[i]>0)
			{//연산자가 남아있으면 
				ad=cal(val,od[cnt+1],i);
				opt[i]--;//연산자 사용
				dfs(cnt+1,ad);
				opt[i]++;//연산자 복구 
			}
		}
	}
	
}
int main(){
cin>>n;
	for(int i=0;i<n;i++)
		cin>>od[i];
	
	for(int i=0;i<4;i++){
		cin>>opt[i];
		rec[i]=opt[i];
	}
	dfs(0,od[0]);
	cout<<ma<<endl<<mi<<endl;
}