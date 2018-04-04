#include<iostream>
using namespace std;
int ser(int m, int n);
long long path[1024][1024]={0,};
long long map[1024][1024]={0,};
int main (){
	cout<<"m,n :";
	int m=0,n=0;
	cin>>m>>n;

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];

	ser(m-1,n-1);
	cout<<path[m-1][n-1]<<endl;
}

int ser(int m, int n){
	path[0][0]=map[0][0];

	for(int i=1 ;i<m;i++)
	{
		if(map[i][0]==0)
			path[i][0]=0;
		else
			path[i][0]=path[i-1][0];
	}
	for(int i=1 ;i<n;i++)
	{
		if(map[0][i]==0)
			path[0][i]=0;
		else
			path[0][i]=path[0][i-1];
	}
	for(int i=1; i<n; i++)
		for(int j=1;j<n; j++){

			if(map[i][j]==0)
				path[i][j]=0;
			else 
				path[i][j]=path[i-1][j]+path[i][j-1];
		}


}
