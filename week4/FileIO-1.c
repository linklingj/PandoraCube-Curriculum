#include <stdio.h>

void Write(FILE *p_file) {
  int userCount = 0;
  int score[3] = {0,};

  printf ("enter number of user");
  scanf ("%d", &userCount);

  printf ("enter user info(math, korean, english)\n");
  while (userCount--) {
    scanf ("%d %d %d", &score[0], &score[1], &score[2]);
    fprintf (p_file, "%d %d %d %.1f\n", score[0], score[1], score[2], (score[0]+score[1]+score[2])/3.0);
  }
}

void Read(FILE *p_file) {
  char ch;
  if(NULL != p_file) {
    while(EOF != fscanf(p_file, "%c", &ch)) {
      printf("%c", ch);
    }
  }
}

int main() {
  printf ("================\n"); 
  printf ("1 - write new user info\n"); 
  printf ("2 - add new user info\n"); 
  printf ("3 - print user info\n"); 
  printf ("4 - end\n"); 
  printf ("================\n");
  while (1) {
    int n;
    printf ("enter number");
    scanf ("%d", &n);
    if (n > 4 || n < 1) {
      printf("error\n");
      break;
    }
    if (n == 1) {
      FILE *p_file = fopen("user_info.txt","wt");
      Write(p_file);
      fclose(p_file);
    }
    else if (n == 2) {
      FILE *p_file = fopen("user_info.txt","at");
      Write(p_file);
      fclose(p_file);
    }
    else if (n == 3) {
      FILE *p_file = fopen("user_info.txt","rt");
      Read(p_file);
      fclose(p_file);
    }
    else if (n == 4) break;
  }
  

  return 0;
}
