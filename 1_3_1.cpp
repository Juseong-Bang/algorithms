#include<iostream>
using namespace std;
unsigned long long com(int, int);

unsigned long long st[1024][1024]={0,};
int main (){
	int n,r;
	cout<<"n:";
	cin>>n;
	cout<<"r:";
	cin>>r;
	cout<<endl<<com(n,r)<<endl;
}
unsigned long long com(int n, int r){
	if(st[n][r]!=0)
		return st[n][r];

	if(n == r){
		st[n][r]=1;
		return 1;
	}
	if(r == 0)
	{
		st[n][r]=1;
		return 1;
	}
	if(r>0){
		if(st[n-1][r-1]==0)
			st[n-1][r-1]=com(n-1,r-1);
		if(st[n-1][r]==0)
			st[n-1][r]=com(n-1,r);

		st[n][r]=st[n-1][r-1]+st[n-1][r];
		return st[n][r];
	}
}
