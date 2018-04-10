/*
[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초

2. 디저트 카페가 모여있는 지역의 한 변의 길이 N은 4 이상 20 이하의 정수이다. (4 ≤ N ≤ 20)

3. 디저트 종류를 나타나는 수는 1 이상 100 이하의 정수이다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 디저트 카페가 모여있는 지역의 한 변의 길이 N이 주어진다.

그 다음 N 줄에는 N * N 크기의 디저트 카페에서 팔고 있는 디저트 종류에 대한 정보가 주어진다.


[출력]

테스트 케이스 개수만큼 T개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.

각 줄은 "#t"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (t는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 가능한 경우 중 디저트를 가장 많이 먹을 때의 디저트 수 이다.

만약, 디저트를 먹을 수 없는 경우 정답은 -1이다.
*/
#include<iostream>
using namespace std;
int n;
int map[21][21] = { 0, };

int ix[4] = { 1, 1,-1,-1 };
int iy[4] = { 1,-1,-1, 1 };
int menu[80] = { 0, };
int ma = -1;

bool rng(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)//범위를 벗어남
		return false;//false
	return true;//true
}
void quickSort(int first, int last)// qsort
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)//시작 끝 주소값 
	{
		pivot = first;//첫번쨰 값을 pivot으로 설정 
		i = first;
		j = last;

		while (i < j)//교차되기 전까지 
		{
			while (menu[i] <= menu[pivot] && i < last)//last를 넘어가지 않아야함 
			{
				i++;
			}
			// pivot보다 큰 원소 i  
			while (menu[j] > menu[pivot])//어차피 pivot은 처음 원소니 while에서 앞으로 넘어가지 않음
			{
				j--;
			}
			//pivot보다 작은 원소 j 

			if (i < j)
			{
				temp = menu[i];
				menu[i] = menu[j];
				menu[j] = temp;
			}
			// i와 j 교체
			// 반복하면 pivot을 기준으로 작은값과 큰값으로 나눠짐 
		}

		temp = menu[pivot];
		menu[pivot] = menu[j];
		menu[j] = temp;
		//pivot을 j와 바꾸고 
		//j를 기준으로 작은것과 큰것으로 나눠 다시 호출 
		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
bool test(int item)//중복검사 
{
	quickSort(0, item - 1);//정렬 , 0~item-1번째 주소까지 사용 

	int temp = menu[0];

	for (int i = 1; i < item; i++)
		if (temp == menu[i])//중복 검사 
			return false;
		else
			temp = menu[i];

	return true;
}
void cal()
{
	int x, y, dot, uu = 0, fo = 0, on = 0;

	for (int i = 0; i < n - 2; i++)//시작점 i 
		for (int j = 1; j < n - 1; j++)//j
			for (int u = 1; u < n - 1; u++)//i,j에서 u만큼 대각선 
				for (int v = 1; v < n - 1; v++)//u만큼 간뒤 v만큼 대각선 
				{
					dot = 0;
					x = i;
					y = j;

					for (fo = 0; fo < 4; fo++)
					{
						if (fo % 2 == 0)//0,2
							uu = u;
						else//1,3
							uu = v;
						for (on = 0; on < uu; on++)//uu번 
						{
							x += ix[fo];
							y += iy[fo];//이런거좀 잘보자 

							if (!rng(x, y))//범위 벗어남 
								break;
							else//범위 내부
								menu[dot++] = map[x][y];
						}
						if (on < uu)//범위에서 벗어나 break로 나오는 경우 
							break;
					}
					if (fo == 4 && test(dot))//4변이 다 추가되고 , 겹치는지 검사 
						if (ma < dot)//최대값 저장 
							ma = dot;
				}
}
int main()
{
	freopen("sample_input.txt", "r", stdin);

	int x;
	cin >> x;
	for (int tc = 0; tc < x; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		ma = -1;
		cal();
		cout << "#" << tc + 1 << " " << ma << endl;
	}
	return 0;
}