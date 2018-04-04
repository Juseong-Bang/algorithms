#include<iostream>
////////잘 모르겟다  문제로 풀어보는 알고리즘 60p)

using namespace std;
int pay(int m,int n);
int bill[50]={0,};
int main (){
	int n=0;
	int money=0;
	cout<<"input number of bill:";
	cin>>n;
	cout<<"input bills:";
	for(int i=0;i<n;i++)
	{
		cin>>bill[i];
	}
	cout<<"input money:";
	cin>>money;

	cout<<pay(money,n);
	return 0;
}

int pay(int m, int n){
	int count =0;
	if (n==1)
		return m % bill[n-1] == 0 ? 1 : 0 ;
	for(int i=0;i<=m/bill[n-1];i++)
	count+=pay(m-bill[n-1]*i,n-1);	
return count;

}
