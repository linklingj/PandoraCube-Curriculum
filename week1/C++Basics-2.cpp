#include <iostream>
using namespace std;

int n;
int graph[1000][1000];
int a=1;
//방향[y][x]  오른쪽,아래,왼쪽,위,오른쪽
int dir[5][2] = {{0,1},{1,0},{0,-1},{-1,0},{0,1}};

void Square(int y, int x, int d) {
  //d가 4일때 0으로 초기화
  d=d%4;
  //정해진 칸에 a값을 저장
  graph[y][x]=a++;
  //그래프의 다음칸이 0이고 범위 안일때 직진(방향 안바꾸고 앞칸으로 이동)
  if(graph[y+dir[d][0]][x+dir[d][1]]==0 && y+dir[d][0]<n && y+dir[d][0]>=0 && x+dir[d][1]<n && x+dir[d][1]>=0)
    Square(y+dir[d][0],x+dir[d][1],d);
  //범위를 벗어나거나 다른 수를 만났을 때 아직 출력이 안끝났으면 옆으로 꺾음(방향+1)
  else if(a<=n*n)
    Square(y+dir[d+1][0],x+dir[d+1][1],d+1);
  else
    return;
}

int main() {
  cin >> n;
  //배열 0으로 초기화
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }
  Square(0,0,0);
  //출력
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      cout << graph[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}