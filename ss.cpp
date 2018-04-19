#include<algorithm>
#include<iostream>
using namespace std;
int aa[10] = { 0, };
int main()
{
	for(int i=0;i<10;i++)
	cin >> aa[i];

	sort(aa, aa + 10,isgreater<int,int>);

	for (int i = 0; i<10; i++)
		cout<<aa[i]<<" ";

}