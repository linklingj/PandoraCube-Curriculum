#include <iostream>
#include <stack>

using namespace std;

//인자로 받은 문자열을 출력
void PrintString(string s) {
  cout << s;
}

//문자열의 길이를 반환
int StringLength(string s) {
  return s.length();
}

//문자열을 거꾸로 출력
void ReverseString(string s) {
  stack <char> st;
  int length = StringLength(s);
  //스택에 글자를 순서대로 넣는다
  for (int i = 0; i < length; i++) {
    st.push(s[i]);
  }
  //스택의 위에서 부터 하나씩 출력하고 스택에서 없앤다
  for (int i = 0; i < length; i++) {
    cout << st.top();
    st.pop();
  }
}

int main() {
  //입력받음
  string sentence;
  getline(cin,sentence);

  PrintString(sentence);
  cout << '\n';
  ReverseString(sentence);
}