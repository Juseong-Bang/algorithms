#include<iostream>
#define size 8


struct inode{
	int data;
	struct inode * link;
};
typedef struct inode node_t;
void inq(int);
int deq();
using namespace std;
node_t * head=NULL;
node_t * tail=NULL;

int main(){
	int in=0;

	while(1){
		cout<<"input number:";
		cin>>in;
		if(in>0){
			inq(in);
		}
		else if(in==0){
			int out =deq();
			if(out!=-1)		
				cout<<"["<<out<< "]"<<endl;
		}else if(in<0){
			cout<<"program treminated..."<<endl;
			return 0;
		}
	}
}
void inq(int x){

	node_t * n = new node_t;
	n->data=x;
	n->link=NULL;

	if(head==NULL)
	{
		head=n;
		tail=n;
	}else{

		tail->link=n;
		tail=n;
	}
}
int deq(){

	if(head==NULL)
	{
		cout<<"queue is empty"<<endl;
		return -1;
	}

	node_t *tem=head;
	int t=head->data;

	head=head->link;
	if(head==NULL)
		tail=NULL;
	delete tem;
	return t;
}
