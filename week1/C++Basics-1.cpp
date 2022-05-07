#include <iostream>
using namespace std;

//graph는 출력할 수를 저장한 2차원 배열
int graph[1000][1000];
//a는 다음 출력할 숫자이다
int a=1;

//y,x는 시작 좌표를 나타내고 length는 사각형의 크기를 나타낸다
void Square(int y, int x, int length) {
  //오른쪽으로 length만큼 수를 채움
  for (int i = 0; i < length; i++) {
    graph[y][x+i]=a;
    a++;
  }
  //끝난 위치에서 아래로 length-1만큼 수를 채움
  for (int i = 0; i < length-1; i++) {
    graph[y+i+1][x+length-1]=a;
    a++;
  }
  //오른쪽으로 채움
  for (int i = 0; i < length-1; i++) {
    graph[y+length-1][x+length-2-i]=a;
    a++;
  }
  //위로 채움
  for (int i = 0; i < length-2; i++) {
    graph[y+length-2-i][x]=a;
    a++;
  }
}

int main() {
  int n;
  cin >> n;
  //n부터 2씩 줄여가며 크기가 i인 사각형을 채운다
  for(int i=n; i>0; i-=2) {
    //사각형의 시작 위치는 첫번째 사각형은 0,0에서 두번째는 1,1에서...시작, 사각형의 크기는 i
    Square((n-i)/2,(n-i)/2,i);
  }
  //출력
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++)
      cout << graph[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}