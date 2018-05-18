/*
문제
어떤 수 N이 주어져 있을 때 이 수가 10보다 크면 일의 자리에서 반올림을 하고, 이 결과가 100보다 크면 다시 10의 자리에서 반올림을 하고,
또 이 수가 1000보다 크면 100의 자리에서 반올림을 하고.. (이하 생략) 이러한 연산을 한 결과를 출력하시오.

입력
첫째 줄에 어떤 수 N이 주어진다. (0<=N<=99,999,999)

출력
첫째 줄에 위와 같은 연산을 한 결과를 출력하시오.
*/
long long n;

#include<iostream>
using namespace std;

int main()
{
	cin >> n;
	long long k = 1;

	while (n > k*10)
	{
		if (n % (k * 10) >= (5 * k))
			n += (10 - (n % (k * 10)) / k)*k;
		else
			n -= ((n % (k * 10)) / k)*k;

		k *= 10;
	}
	
	cout << n;
	return 0;

}