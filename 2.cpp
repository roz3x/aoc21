
#include <bits/stdc++.h>
#ifdef DEBUG
#include <dbg.h>
#endif
using namespace std;

int main() {
  char  direction[0xff];
  int dist;
  int x=0,y=0;
  while((scanf("%s%d", direction, &dist))!=EOF) {
    if (strcmp("forward", direction)) {
      x+=dist;
    }  else if (strcmp("up", direction)) {
      y-=dist;
    }  else  if (strcmp("down", direction)) {
      y+=dist;
    } else {
      printf("%s",  direction) ;
    }


  }
  cout << x  * y << endl;
}

