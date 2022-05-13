#include <iostream>

using namespace std;

typedef struct node {
  struct node *prev;
  struct node *next;
  int value;
} NODE;

void InsertData(NODE **pp_head, int data) {
  NODE *p, *cpy = NULL, *previous = NULL;
  //노드가 이미 존재하는 경우
  if (NULL != *pp_head) {
    p = *pp_head;
    //첫번째 노드의 앞에 들어가야 하는 경우
    if (data < p->value) {
      cpy = *pp_head;
      *pp_head = (NODE*)malloc(sizeof(NODE));
      p = *pp_head;
    }
    //중간이나 끝에 들어가야 하는 경우
    else {
      //다음 노드의 value가 data보다 클때까지 포인터를 다음으로 넘긴다
      while(NULL != p->next && p->next->value < data) p = p->next;
      cpy = p->next;
      p->next = (NODE*)malloc(sizeof(NODE));
      previous = p;
      p = p->next;
    }
  }
  //최초의 노드일 경우
  else {
    //동적할당으로 저장공간 만듬
    *pp_head = (NODE*)malloc(sizeof(NODE));
    p = *pp_head;
  }
  //현재 노드 값 저장
  p->value = data;
  p->next = cpy;
  p->prev = previous;
}

void DeleteData(NODE **pp_head, int data) {
  NODE *p, *cpy;
  //노드가 없는 경우
  if (*pp_head == NULL) {
    cout << "NO NODE\n";
    return;
  }
  p = *pp_head;
  //해당 노드가 첫번째 노드일 경우
  if (p->value == data) {
    cpy = p;
    *pp_head = p->next;
    p->next->prev = NULL;
    free(cpy);
    return;
  }
  //마지막 노드이거나 다음 노드의 값이 data보다 작을때까지 포인터 이동
  while (NULL != p->next && p->next->value < data) p = p->next;
  //해당 노드를 찾은 경우
  if (p->next->value == data) {
    cpy = p->next;
    p->next = p->next->next;
    if (p->next != NULL)
      p->next->prev = p;
    free(cpy);
  }
  //해당 노드를 못 찾았을 경우
  else
    cout << "NOT FOUND\n";
}

void FindData(NODE **pp_head, int data) {
  int cnt = 1;
  NODE *p;
  p = *pp_head;
  //첫번째 노드인 경우
  if (p->value == data) {
    cout << "position of the number: 1\n";
    return;
  }
  //마지막 노드이거나 다음 노드의 값이 더 작을때까지 반복
  while (NULL != p->next && p->next->value < data) {
    p = p->next;
    cnt++;
  }
  //해당 노드를 찾은 경우
  if (p->next->value == data)
    cout << "position of the number: " << cnt+1 << '\n';
  //해당 노드를 못 찾았을 경우
  else
    cout << "NOT FOUND\n";
}

void PrintData(NODE **pp_head) {
  NODE *p;
  p = *pp_head;
  //노드가 없을때
  if (p == NULL) {
    cout << "NO NODE\n";
    return;
  }
  //다음 노드가 없을때까지 값 출력
  while (NULL != p) {
    cout << p->value << " ";
    p = p->next;
  }
  cout << "\n";
}

int main() {
  
  NODE *head = NULL, *p;
  while (1) {
    int n;
    cout << "==========\n" << "1: InsertData\n" << "2: DeleteData\n" << "3: FindData\n" << "4: PrintData\n" << "5: End\n";
    cin >> n;
    if (n == 1) {
      int m;
      cout << "Enter Number\n";
      cin >> m;
      InsertData(&head,m);
    }
    if (n == 2) {
      int m;
      cout << "Enter Number\n";
      cin >> m;
      DeleteData(&head,m);
    }
    if (n == 3) {
      int m;
      cout << "Enter Number\n";
      cin >> m;
      FindData(&head,m);
    }
    if (n == 4)
      PrintData(&head);
    if (n == 5) 
      break;
  }

  return 0;
}
