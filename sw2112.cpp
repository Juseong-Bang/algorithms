/*
[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초

2. 보호 필름의 두께 D는 3이상 13이하의 정수이다. (3≤D≤13)

3. 보호 필름의 가로크기 W는 1이상 20이하의 정수이다. (1≤W≤20)

4. 합격기준 K는 1이상 D이하의 정수이다. (1≤K≤D)

5. 셀이 가질 수 있는 특성은 A, B 두 개만 존재한다.


[입력]

첫 줄에 총 테스트 케이스의 개수 T가 주어진다.

두 번째 줄부터 T개의 테스트 케이스가 차례대로 주어진다.

각 테스트 케이스의 첫 줄에는 보호 필름의 두께 D, 가로크기 W, 합격기준 K가 차례로 주어진다.

그 다음 D줄에 보호 필름 단면의 정보가 주어진다. 각 줄에는 셀들의 특성 W개가 주어진다. (특성A는 0, 특성B는 1로 표시된다.)


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 “#x”로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 성능검사를 통과할 수 있는 약품의 최소 투입 횟수이다. 약품을 투입하지 않고도 성능검사를 통과하는 경우에는 0을 출력한다.
*/


#include<iostream>
#include<cstring>
using namespace std;
int d, w, k;
int map[14][21] = { 0, };
int vi[14] = { 0, };//약품1=1 , 약품0=-1,
int mi = -1;

bool chk(int w) //w열의 검사 
{
	int set = map[0][w];//맨 위층부터 검사 

	int cnt = 1;
	int temp = 0;

	for (int i = 0; i < d; i++)
	{
		if (vi[i] != 0) //약품을 사용했다면 
		{
			if (vi[i] == 1)
				temp = 1;
			else if (vi[i] == -1)
				temp = 0;
		}
		else //사용하지 않았다면 
		{
			temp = map[i][w];
		}

		if (i == 0)
		{
			set = temp;
			continue;
		}

		if (set == temp)//이전과 특성이 같으면 
			cnt++;
		else //다르면 
		{
			set = temp;//새로운 특성부터 
			cnt = 1;//1로 세기 시작 
		}

		if (cnt >= k)//만약 검사 기준 k를 넘는 연속 특성이 나온다면 
			return true;//합격
	}
	return false;
}
void dfs(int cur, int cnt, int m)//현재 고려하는 행, 고른 갯수, 최대 고르는 수
{
	if (cnt >= m)// 다 고름   
	{
		int v = 0;
		for (; v < w; v++)
			if (!chk(v))
				break;

		if (v >= w)//모든 열이 검사 통과시
		{
			mi = cnt;
			return;//사용한 약품의 횟수 
		}
		return ;
	}
	else//덜 고름  
	{
		if (cur >= d)//다못고르고 맨끝 옴 
			return ;

		vi[cur] = 1;//약품 1
		dfs(cur + 1, cnt + 1, m);

		vi[cur] = -1;//약품 2
		dfs(cur + 1, cnt + 1, m);

		vi[cur] = 0;//약품 안바름
		dfs(cur + 1, cnt, m);
		
		return ;
	}
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	int x = 0;
	cin >> x;

	for (int tc = 0; tc < x; tc++)
	{
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		mi = -1;

		for (int i = 0; i <= k; i++)
		{
			memset(vi, 0, sizeof(vi));
			dfs(0, 0, i);
			
			if (mi != -1)
				break;
			
		}
		cout << "#" << tc + 1 << " " << mi << endl;
	}
}