#include<iostream>

using namespace std;
int part(int m,int n);
int main (){
	int m=0,n=0;
	cout<<"input number to partition:";
	cin>>m;
	cout<<"input part number :";
	cin>>n;

	cout<<part(m,n);
	return 0;
}

int part(int m, int n){
	int count =0;

	if(m<n)
		n=m;//m-i 로 m이 계속 작아지다가 n보다 작아지면 n-1 하는것과 같다 

	if (n==0)
		return 1;

	for(int i=1;i<=n;i++)
		count+=part(m-i,i);	
	return count;

}
