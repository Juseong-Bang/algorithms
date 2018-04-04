/*
입력
입력은 20 행으로 구성된다. 1 번째 줄부터 10 번째 줄에는 W 대학의 각 참가자의 점수를 나타내는 정수가 11 번째 줄부터 20 번째 줄에는 K 대학의 각 참가자의 점수를 나타내는 정수가 적혀있다. 이 정수는 모두 0 이상 100 이하이다.

출력
W 대학 점수와 K 대학의 점수를 순서대로 공백으로 구분하여 출력하라.
*/

#include<iostream>
using namespace std;
int w[10]={0,},k[10]={0,};
void sw(int * a,int * b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void qsort(int * ar , int l, int r){
	int i=l+1,p=l,j=l;
	
	if(l<r)
	{
		for(;i<=r;i++){
		if(ar[i]<ar[p]){
			j++;
			sw(&ar[j],&ar[i]);
		}
	}
	sw(&ar[j],&ar[p]);
		

	qsort(ar,l,j-1);
	qsort(ar,j+1,r);
}
	
}
int main (){
	for(int i=0;i<20;i++){
		if(i<10)
			cin>>w[i];
		else
			cin>>k[i-10];
	}
	qsort(w,0,9);
	qsort(k,0,9);
	
	int s1=0,s2=0;
	for(int i=0;i<3;i++){
		s1+=w[9-i];
		s2+=k[9-i];
		
	}
	cout<<s1<<" "<<s2<<endl;
}