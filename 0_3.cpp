#include <iostream>

using namespace std;

int rotate(int arr[],int s,int e,int t);

int main(){
int num,s,e,t;
cout<<"배열의 크기:"<<endl;
cin>>num;
int arr[num];
cout<<"시작:"<<endl;
cin>>s;
cout<<"갯수:"<<endl;
cin>>e;
cout<<"횟수:"<<endl;
cin>>t;
rotate (arr,s,e,t);
}
int rotate(int arr[],int s,int e,int t){

int temp[t]={0,};
for(int i=s;i<s+e;i++){
for( int j=0;j++<t;i++){
temp[j] =arr[i+j];
}
}
}
