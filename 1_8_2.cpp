#include<iostream>
using namespace std;
int com(int);
int part[512][1024]={0,};
int main (){
	int k;
	cout<<"input k:";
	cin>>k;
	com(k);
}
int com(int k)
{
	part[1][k]=1;

	for(int i=2;i<=k;i++){
		for(int j=1 ;j<=k*2 ;j++)
			part[i][j]=part[i-1][j-1]+part[i-1][j+1];
	}

	for(int i=1;i<=k;i++){
		for(int j=1 ;j<=k*2 ;j++)
		{
			if(part[i][j]==0) 
				cout<<" ";
			else
				cout<<part[i][j];
		}
		cout<<endl;
	}
}
