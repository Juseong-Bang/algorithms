/*
입력
첫째 줄에 N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)이 주어진다. 둘째 줄부터 N개의 줄에 지도가 주어진다. 각 칸의 높이는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 지나갈 수 있는 길의 개수를 출력한다.
12:58
*/

#include<iostream>
using namespace std;
int n, l, road;//size , length , number 

int map[100][100] = { 0, };
int check(int i, int j, int w) {//w>0 가로방향 진행 ,다음것과의 차이 리턴
	if (w>0)
		return map[i][j + 1] - map[i][j];
	if (w<0)
		return map[j + 1][i] - map[j][i];
}
void path() {
	int x, y, w = 1, s = 0;
	bool ch = true, tw = true;

	for (int i = 0; i<n; i++)
	{
		ch = true;
		s = 0;
		for (int j = 0; j<n - 1; j++) {
			int a = check(i, j, w);
			if (a<-1 || a>1)//다음 경사로와 차이가 1이상 난다면 
			{
				ch = false;
				break;
			}
			else if (a == 0) {
				s++;
			}
			else if (a>0) {//올라가는 경사로?
				if (s + 1<l) {//지금까지 포함 해서 짧음
					ch = false;
					break;
				}
				else// 길이가 됨 
					s = 0;
			}
			else if (a<0) {//내려가는 경사로?
				s = -1;
				for (int k = 1; k<l; k++) {//j+1 부터 l-1개 비교 
					if (j + l >= n) {// 길이가 n 이 넘어갈수 없음 
						ch = false;
						j = n - 1;
						break;
					}
					else if (check(i, j + k, w) != 0)//높이가 다르면 
					{
						ch = false;
						break;
					}
				}

				if (!ch) {
					break;
				}
				j += (l - 1);
			}
		}
		if (ch) {
			road++;
			//cout << i << ",";
		}
		if (i == n - 1 && tw) {
			i = -1;
			w = -1;
			tw = false;
			//cout << "|";
		}
	}
}
int main() {
	cin >> n >> l;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			cin >> map[i][j];
	//cout << endl;
	path();
//	cout << ":" << road;
}