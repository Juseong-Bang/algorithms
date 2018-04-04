#include<iostream>
//순서가 있는 수 분할 66p 이해가 잘 안됨

using namespace std;
int part(int m);
int main (){
	int m=0,n=0;
	cout<<"input number to partition:";
	cin>>m;

	cout<<part(m);
	return 0;
}

int part(int m){
	int count =0;

	for(int i=1;i<m;i++)
		count+=part(m-i);	
	return count+1;

}
