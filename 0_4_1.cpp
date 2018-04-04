#include<iostream>
#define size 8

using namespace std;
int main(){
int in=0;
int st=0;
int en=0;
int ca=0;

int qu[size]={0,};
while(1){
cout<<"input number:";
cin>>in;
if(in>0){
if(ca>7){
cout<<"queue is full"<<endl;
continue;
}
ca++;
qu[en%size]=in;
en++;
}else if(in==0){
if(ca==0)
{
cout<<"queue is enpty"<<endl;
continue;
}
ca--;
cout<<"["<<qu[st%size]<<"]"<<endl;
st++;
}else if(in<0){
cout<<"program treminated..."<<endl;
return 0;
}
}
}

