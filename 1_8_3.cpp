#include<iostream>
using namespace std;
int make(int ,int );
int p[100]={0,};
int size=0;
int main (){
	int n=0,m=0;
	cout<<"n,m:";
	cin>>n>>m;
	size=m;
	make(n,m);
}
int make(int n ,int m ){
	if ( m==1){
		p[m]=n;
		for(int i=1;i<=size;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			p[m]=i;
			make(n-i,m-1);
		}	
	}
}
