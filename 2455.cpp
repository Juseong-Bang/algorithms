#include<iostream>

using namespace std;

int main()
{
	int p=0,mx=0;
	int in, out;
	for (int i = 0; i < 4; i++)
	{
		cin  >> out>>in;
		p=p - out + in;
		if (mx < p)
			mx = p;
	}

	cout << mx;

	return 0;

}