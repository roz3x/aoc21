
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;


int mat[1000][1000];

int main() {
  
  int x1,x2,y1,y2;
  while((scanf("%d,%d -> %d,%d", &x1,&y1,&x2,&y2))!=EOF) {
    if (x1==x2)  {
      int m, M;
      m = min(y1,y2);
      M = max(y1,y2);
      for (int i=m;i<=M;i++) {
        mat[x1][i]++;
      }
    } else if (y1==y2) {
      int m , M;
      m = min(x1,x2);
      M= max(x1,x2);
      for (int i=m;i<=M;i++) {
        mat[i][y1]++;
      }
    } else if (abs(x1-x2)==abs(y1-y2)) {
      int delx = x1 < x2 ? 1 : -1;
      int dely = y1 < y2 ? 1 : -1;

      for (int i=x1;i!=x2;i+=delx) {
        mat[i][y1]++;
        y1+=dely;
      }
      mat[x2][y2]++;
    }
  }
  int cnt=0;
  for (int i=0;i<1000;i++)
    for (int j=0;j<1000;j++)
      if (mat[i][j] >= 2) cnt++;
  printf("%d\n", cnt);
}

