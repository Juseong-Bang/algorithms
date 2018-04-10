/*
[�������]

1. �ð����� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴ� �� C/C++/Java ��� 3��

2. ����Ʈ ī�䰡 ���ִ� ������ �� ���� ���� N�� 4 �̻� 20 ������ �����̴�. (4 �� N �� 20)

3. ����Ʈ ������ ��Ÿ���� ���� 1 �̻� 100 ������ �����̴�.


[�Է�]

�Է��� �� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־�����, �� ���� �ٺ��� T���� �׽�Ʈ ���̽��� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ����Ʈ ī�䰡 ���ִ� ������ �� ���� ���� N�� �־�����.

�� ���� N �ٿ��� N * N ũ���� ����Ʈ ī�信�� �Ȱ� �ִ� ����Ʈ ������ ���� ������ �־�����.


[���]

�׽�Ʈ ���̽� ������ŭ T���� �ٿ� ������ �׽�Ʈ ���̽��� ���� ���� ����Ѵ�.

�� ���� "#t"�� �����ϰ� ������ �ϳ� �� ���� ������ ����Ѵ�. (t�� 1���� �����ϴ� �׽�Ʈ ���̽��� ��ȣ�̴�)

����ؾ� �� ������ ������ ��� �� ����Ʈ�� ���� ���� ���� ���� ����Ʈ �� �̴�.

����, ����Ʈ�� ���� �� ���� ��� ������ -1�̴�.
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
	if (x < 0 || y < 0 || x >= n || y >= n)//������ ���
		return false;//false
	return true;//true
}
void quickSort(int first, int last)// qsort
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)//���� �� �ּҰ� 
	{
		pivot = first;//ù���� ���� pivot���� ���� 
		i = first;
		j = last;

		while (i < j)//�����Ǳ� ������ 
		{
			while (menu[i] <= menu[pivot] && i < last)//last�� �Ѿ�� �ʾƾ��� 
			{
				i++;
			}
			// pivot���� ū ���� i  
			while (menu[j] > menu[pivot])//������ pivot�� ó�� ���Ҵ� while���� ������ �Ѿ�� ����
			{
				j--;
			}
			//pivot���� ���� ���� j 

			if (i < j)
			{
				temp = menu[i];
				menu[i] = menu[j];
				menu[j] = temp;
			}
			// i�� j ��ü
			// �ݺ��ϸ� pivot�� �������� �������� ū������ ������ 
		}

		temp = menu[pivot];
		menu[pivot] = menu[j];
		menu[j] = temp;
		//pivot�� j�� �ٲٰ� 
		//j�� �������� �����Ͱ� ū������ ���� �ٽ� ȣ�� 
		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
bool test(int item)//�ߺ��˻� 
{
	quickSort(0, item - 1);//���� , 0~item-1��° �ּұ��� ��� 

	int temp = menu[0];

	for (int i = 1; i < item; i++)
		if (temp == menu[i])//�ߺ� �˻� 
			return false;
		else
			temp = menu[i];

	return true;
}
void cal()
{
	int x, y, dot, uu = 0, fo = 0, on = 0;

	for (int i = 0; i < n - 2; i++)//������ i 
		for (int j = 1; j < n - 1; j++)//j
			for (int u = 1; u < n - 1; u++)//i,j���� u��ŭ �밢�� 
				for (int v = 1; v < n - 1; v++)//u��ŭ ���� v��ŭ �밢�� 
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
						for (on = 0; on < uu; on++)//uu�� 
						{
							x += ix[fo];
							y += iy[fo];//�̷����� �ߺ��� 

							if (!rng(x, y))//���� ��� 
								break;
							else//���� ����
								menu[dot++] = map[x][y];
						}
						if (on < uu)//�������� ��� break�� ������ ��� 
							break;
					}
					if (fo == 4 && test(dot))//4���� �� �߰��ǰ� , ��ġ���� �˻� 
						if (ma < dot)//�ִ밪 ���� 
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