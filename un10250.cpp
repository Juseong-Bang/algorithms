/*
�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (4 �� N, M �� 500)

��° �ٺ��� N���� �ٿ� ���̿� �� �ִ� ���� �־�����. i��° ���� j��° ���� ���������� i��° ĭ, ���ʿ������� j��° ĭ�� �� �ִ� ���̴�. �Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.
*/
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n, m;
int map[500][500] = { 0, };
int ch[500][500] = { false, };
int ix[4] = { 0,0,-1,1 };
int iy[4] = { 1,-1,0,0 };
long mx = -1;

queue<pair<int, int> > q;

int cnt() {
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ch[i][j])
				ret += map[i][j];
	return ret;
}
bool rang(int x, int y) {

	if (x < 0 || y < 0 || n - 1 < x || m - 1 < y)
		return false;
	return true;
}
void dfs(int x, int y, int num) //x,y,����
{

	if (num == 4) {//4���� ����ٸ� 
		int re = cnt();//�ջ� 
		if (mx == -1 || re > mx)
			mx = re;//�ִ밪 ���� 
		/*
		if (re == 7)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					cout << ch[i][j] << ",";
				cout << endl;
			}
			*/
		return;// ���� 
	}
	ch[x][y] = true;
	
	if (num == 3) { // �� ��� 
		int xl, yl, xh, yh;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (ch[i][j] == true)
				{
					if (i > xh)
						xh = i;
					else if (i < xl)
						xl = i;
					if (j > yh)
						yh = j;
					else if (j < yl)
						yl = j;
				}

	}

	// 4�� ���� ���� 
	for (int i = 0; i < 4; i++) {
		int nx = x + ix[i];
		int ny = y + iy[i];
		if (rang(nx, ny) && !ch[nx][ny]) {
			dfs(nx, ny, num + 1);
			ch[nx][ny] = false;
		}
	}
	

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			memset(ch, 0, sizeof(ch));
			dfs(i, j, 0);
		}
	cout << mx;
}