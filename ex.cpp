//https://www.acmicpc.net/problem/2178
//BOJ_2178_미로탐색
 
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
 
int n;  //row
int m;  //column
 
bool map[100][100];  //true - can go, false - can't go
int check[100][100]; //지나온길 기록
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //up, down, left, right check.
 
//input
void In(){
    cin >> n >> m;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++) {
            int b;
            scanf("%1d", &b);
 
            if(b==1){
                map[i][j] = true;
            }
        }
    }
}
 
//output
void Out(int num){
    printf("%d\n", num);
}
 
//check [y, x] is in or not
bool isInside(int a, int b){
    return (a >= 0 && a < n) && (b >=0 && b < m);
}
 
 
int bfs(){
    int cur_y=0, cur_x=0;   //current y, x
 
    queue<pair<int, int> > q;   //queue for bfs search
    q.push(pair<int, int>(cur_y,cur_x));
    check[cur_y][cur_x] = 1;    //bfs가 지나가면서 몇번째만에 그 점에 접근했는지
 
    while(!q.empty()){
 
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
 
        if((cur_y == n) && (cur_x == m)) break; //도착지점
 
        for(int i=0; i<4; i++){
            //up, down, left, right !!
            int next_y = cur_y + dir[i][0];
            int next_x = cur_x + dir[i][1];
 
            //next y, x가 배열 내부에 있고, check 2차원배열에 기록된적 없고, map에 true로 되어있으면
            if(isInside(next_y, next_x) && check[next_y][next_x]==0 && map[next_y][next_x]){
                check[next_y][next_x] = check[cur_y][cur_x] +1; //이전 방문값 + 1 = 다음 방문
                q.push(pair<int, int>(next_y, next_x)); //방문한 곳 push push
            }
        }
    }
 
    /*  bfs로 만든 check 배열 출력해보기
    for(int i=0;i<n; i++){
        for(int j=0; j<m ; j++){
            cout << check[i][j];
        }
        cout << endl;
    }
    */
 
    return check[n-1][m-1];
}
 
 
int main(void){
    In();
    Out(bfs());
    return 0;
}
