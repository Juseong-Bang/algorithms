/*
�Է�
ù° �ٿ� 1�� ��Ϲ����� ����, ��° �ٿ� 2�� ��Ϲ����� ����, ��° �ٿ� 3�� ��Ϲ����� ����, ��° �ٿ� 4�� ��Ϲ����� ���°� �־�����. ���´� 8���� ������ �̷���� �ְ�, 12�ù������ �ð���� ������� �־�����. N���� 0, S���� 1�� ��Ÿ���ִ�.

�ټ�° �ٿ��� ȸ�� Ƚ�� K(1 �� K �� 100)�� �־�����. ���� K�� �ٿ��� ȸ����Ų ����� ������� �־�����. �� ����� �� ���� ������ �̷���� �ְ�, ù ��° ������ ȸ����Ų ��Ϲ����� ��ȣ, �� ��° ������ �����̴�. ������ 1�� ���� �ð� �����̰�, -1�� ���� �ݽð� �����̴�.

���
�� K�� ȸ����Ų ���Ŀ� �� ��Ϲ����� ������ ���� ����Ѵ�. ������ ������ ���� ����Ѵ�.

1�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 1��
2�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 2��
3�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 4��
4�� ��Ϲ����� 12�ù����� N���̸� 0��, S���̸� 8��
*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct roll {
	int gn;//��� ��ȣ 
	int n;//���� Ƚ�� n>0 -> cw,  n<0 -> ccw
}roll;

bool g[4][8] = { false, };//n=false, s=true
int t;
roll mo[100];
queue <pair<roll, int> > q;//  

void ch(int num, int c)//num��° ��Ϲ����� c�� ȸ�� 
{
	bool tmp = 0;
	int ctr = 0;

	if (c<0) {//c�� �����϶� 
		ctr = 7 + c;//-1ȸ���� 7ȸ���̶� ���� 
	}

	for (int i = 0; i<8; i++) {
		tmp = g[num][(i + ctr) % 8];
		g[num][(i + ctr) % 8] = g[num][i % 8];
		g[num][i % 8] = tmp;
	}
}

int value() {
	int ret = 0;
	int tw = 1;
	for (int i = 0; i<4; i++) {//ȸ���� ��ŭ 
		ret += (g[i][0] * tw);
		tw *= 2;
	}
	return ret;
}
int bfs()
{
	int a, b, c;

	for (int i = 0; i<t; i++) {//ȸ���� ��ŭ 
		q.push(make_pair(mo[i], 0));
		while (!q.empty()) {

			a = q.front().first.gn;//a== i gn ��° ��Ϲ����� ȸ�� 
			b = q.front().first.n;//b== n ����
			c = q.front().second;//������ ���� ==0 < == -1 ,  > ==  1
			q.pop();
			if (c == 0) {
				for (int s = 0; s<(b>0) ? b : -b; s++)
				{
					if (0 <= a - 1)//���� ������
						if (g[a - 1][2] != g[a][6])//��� �ִ� ������ �ٸ� ���̸� 
						{
							if (b>0)
							{
								q.push(make_pair(roll{ a - 1,-1 }, -1));
								ch(a - 1, -1);
							}
							else {
								q.push(make_pair(roll{ a - 1,1 }, -1));
								ch(a - 1, 1);
							}
						}
					if (a + 1 <= 3)//������ ������ 
						if (g[a][2] != g[a + 1][6])//��� �ִ� ������ �ٸ� ���̸� 
						{
							if (b>0) {
								q.push(make_pair(roll{ a + 1,-1 }, 1));
								ch(a + 1, -1);
							}
							else {
								q.push(make_pair(roll{ a + 1,1 }, 1));
								ch(a + 1, 1);
							}
						}
					ch(a, b>0 ? 1 : -1);// �ڱ��ڽ� ������
				}
			}
			else
			{
				if (0 <= a - 1 && c == -1)// ���� 
					if (g[a - 1][2] != g[a][6])//��� �ִ� ������ �ٸ� ���̸� 
					{
						if (b>0)
						{
							q.push(make_pair(roll{ a - 1,-1 }, -1));
							ch(a - 1, -1);
						}
						else {
							q.push(make_pair(roll{ a - 1,1 }, -1));
							ch(a - 1, 1);
						}
					}
				if (a + 1 <= 3 && c == +1)

					if (g[a][2] != g[a + 1][6])//��� �ִ� ������ �ٸ� ���̸� 
					{
						if (b>0) {
							q.push(make_pair(roll{ a + 1,-1 }, 1));
							ch(a + 1, -1);
						}
						else {
							q.push(make_pair(roll{ a + 1,1 }, 1));
							ch(a + 1, 1);
						}
					}

			}

		}
	}
	/*
	if(a==0){

	}else if(a==1){

	}else if(a==2){

	}else if(a==3){

	}
	*/
	return value();
}
int main() {

	for (int i = 0; i<4; i++)
		for (int j = 0; j<8; j++)
			cin >> g[i][j];

	cin >> t;

	for (int i = 0; i<t; i++) {
		cin >> mo[i].gn;
		cin >> mo[i].n;
	}
	cout << bfs() << endl;
}