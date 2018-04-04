#include<iostream>

using namespace std;
#define MAXI 300
int memo_part(int m,int n);
int part_set[MAXI][MAXI]={0,};
int main (){
	int m=0,n=0;
	cout<<"input number to partition:";
	cin>>m;
	cout<<"input part number :";
	cin>>n;

	cout<<memo_part(m,n);
	return 0;
}

int memo_part(int m, int n){
	int count =0;

	if(part_set[m][n]!=0)
		return part_set[m][n];

	if(m<n)
		n=m;//m-i 로 m이 계속 작아지다가 n보다 작아지면 n-1 하는것과 같다 

	if (n==0){
		part_set[m][n]=1;
		return 1;
	}
	for(int i=1;i<=n;i++)
		count+=memo_part(m-i,i);	

	part_set[m][n]=count;

	return part_set[m][n];

}
