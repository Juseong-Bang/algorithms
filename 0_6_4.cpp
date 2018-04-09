#include<iostream>
#define size 8
using namespace std;


struct inode {
	int data;
	struct inode * link;
};

typedef struct inode node_t;

void push(int);
int pop();

node_t * bot = NULL;
node_t * top = NULL;

int main() {
	int in = 0;

	while (1) {
		cout << "input number:";
		cin >> in;
		if (in > 0) {
			push(in);
		}
		else if (in == 0) {
			int out = pop();
			if (out != -1)
				cout << "[" << out << "]" << endl;
		}
		else if (in < 0) {
			cout << "program treminated..." << endl;
			return 0;
		}
	}
}
void push(int x) {

	node_t * n = new node_t;
	n->data = x;
	n->link = NULL;

	if (bot == NULL)
	{
		bot = n;
		top = n;
	}
	else {
		n->link = top;
		top = n;
	}
}
int pop() {

	if (top == NULL)
	{
		cout << "stack is empty" << endl;
		return -1;
	}

	node_t *tem = top;
	int t = top->data;

	top = top->link;

	if (top == NULL)
		bot = NULL;

	delete tem;
	return t;
}
