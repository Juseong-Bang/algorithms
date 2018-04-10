#include<iostream>
using namespace std;



int main(void)
{
	int in = 0;
	cout << "input number:";
	cin >> in;
	int cnt = 0;
	while (in != 0) {
		if (in & 1 == 1)
			cnt++;
		in >>= 1;
	}
	cout << "1의 갯수는 " << cnt << "개" << endl;
	return 0;
}
