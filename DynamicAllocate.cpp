#include <iostream>
#include <stack>

using namespace std;

int n,m;

//인벤토리의 x,y좌표에 존재하는 아이템 개수를 1 올린다
void GetItem(int y, int x, int *arr[]) {
  arr[y][x]++;
}

//인벤토리의 x,y좌표에 존재하는 아이템 개수를 1 내린다
void UseItem(int y, int x, int *arr[]) {
  if(arr[y][x] > 0)
    arr[y][x]--;
}

//인벤토리에 존재하는 모든 아이템의 개수를 출력한다
void Printitem(int *arr[]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << ' ';
    }
    printf("\n");
  }
}

int main() {
  //n*m크기의 2차원배열을 동적할당
  cin >> m >> n;
  int** item = (int**)malloc(sizeof(int*) * n);
  for (int i=0; i<n; i++) {
    item[i] = (int*)malloc(sizeof(int) * m);
  }
  //배열의 모든 값을 0으로 초기화
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      item[i][j] = 0;
    }
  }
  bool stop = false;
  char ch;
  int y,x;
  //p가 나올 때 까지 반복해서 입력 받음
  while (!stop) {
    cin >> ch;
    if(ch == 'g') {
      cin >> x >> y;
      GetItem(y,x,item);
    }
    if(ch == 'u') {
      cin >> x >> y;
      UseItem(y,x,item);
    }
    if(ch == 'p') 
      stop = true;
  }
  Printitem(item);
}