/*
����
N(2��N��10,000)���� ������ �̷���� ���� �ִ�. �̵� �� �� ���� �� ���̿��� �ٸ��� ��ġ�Ǿ� �־ ������ �ٴ� �� �ִ�.

���� �߰��������� �� ���� ���� ������ ���� �ΰ� ��ǰ�� �����ϴ� ���� �ϰ� �ִ�.
��ǰ�� �����ϴ� ���� ���忡�� �ٸ� �������� ���� ���̴� ��ǰ�� �����ؾ� �� ���� ����� �Ѵ�.
�׷��� ������ �ٸ����� �߷������� �ֱ� ������ ���δ�� ��ǰ�� �ű� �� ����. ���� �߷������� �ʰ��ϴ� ���� ��ǰ�� �ٸ��� ������ �Ǹ� �ٸ��� �������� �ȴ�.

�� ���� �̵����� �ű� �� �ִ� ��ǰ���� �߷��� �ִ밪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, M(1��M��100,000)�� �־�����. ���� M���� �ٿ��� �ٸ��� ���� ������ ��Ÿ���� �� ���� A, B(1��A, B��N), C(1��C��1,000,000,000)�� �־�����.
�̴� A�� ���� B�� �� ���̿� �߷������� C�� �ٸ��� �����Ѵٴ� �ǹ��̴�.

���� ���� �� ���� ���̿� ���� ���� �ٸ��� ���� ���� ������, ��� �ٸ��� ������̴�.

������ �ٿ��� ������ ��ġ�� �ִ� ���� ��ȣ�� ��Ÿ���� ���� �ٸ� �� ������ �־�����.
������ �ִ� �� ���� �����ϴ� ��δ� �׻� �����ϴ� �����͸� �Է����� �־�����.

���
ù° �ٿ� ���� ����Ѵ�.
*/
#include<iostream>
#include<queue>
using namespace std;

int n, m, s, d;
int b[100000][2] = { 0, };//�ٸ� �������� 
long c[100000] = { 0, };//�߷� ����
typedef struct brid {
	int s;
	int e;
	long w;
}br;
queue <br> q;

int bfs()
{
	br es;
	


}
int main() 
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
		cin >> b[i][0] >> b[i][1] >> c[i];
	
	cin >> s >> d;

	int ret = bfs();

}