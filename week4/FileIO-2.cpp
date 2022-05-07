#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
  while (1) {
    int n;
    cout << "================\n";
    cout << "1 - write new user info\n";
    cout << "2 - add new user info\n";
    cout << "3 - print user info\n";
    cout << "4 - end\n";
    cout << "================\n";
    cin >> n;

    if (n == 1 || n == 2) {
      int userCount,score[3];
      ofstream file;
      if (n == 1)
        file.open ("user_info.txt", ios::out | ios::trunc);
      else
        file.open ("user_info.txt", ios::out | ios::app);
      cout << "enter number of users\n";
      cin >> userCount;
      while (userCount--) {
        cin >> score[0] >> score[1] >> score[2];
        file << score[0] << ' ' << score[1] << ' ' << score[2] << ' ' << round((score[0]+score[1]+score[2])/0.3)/10 << '\n';
      }
      file.close();
    }

    else if (n == 3) {
      ifstream file;
      file.open ("user_info.txt", ios::in);
      char line[100];
      while (!file.eof()) {
        file.getline(line,100);
        cout << line << endl;
      }
      file.close();
    }

    else if (n == 4)
      break;
  }
  
}