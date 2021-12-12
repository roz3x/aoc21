
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;


int m[10][10];
set<pair<int,int>> has;
queue<pair<int,int>> nines;


void insert(int i, int j) {
  if (i>=0 && i<10) {
    if (j>=0 && j<10 ) {
      if (!has.count({i,j})) {
        m[i][j]++;
        if (m[i][j] > 9) {
          nines.push({i,j});
          has.insert({i,j});
        }
      }
    }
  }
}
int main() {
  string s;
  for (int i=0;i<10;i++) {
    cin >> s;
    for (int j=0;j<10;j++) {
      m[i][j] = s[j] - '0';
    }
  }

  for (int tt=0;tt<1000;tt++) {

    dbg(m);
    // increase energy by 1
    // collect the indexes where enery is greater then nine
    for (int i=0;i<10;i++) {
      for (int j=0;j<10;j++) {
        m[i][j]++;
        if (m[i][j] > 9)  { nines.push({i,j});  has.insert({i,j});}
      }
    }

    while(!nines.empty()) {
      int i,j;
      i = nines.front().first;
      j = nines.front().second;
      // cout << i << " " << j << endl;

      m[i][j] = 0;

      insert(i+1,j);
      insert(i+1,j-1);
      insert(i+1,j+1);
      insert(i,j-1);
      insert(i,j+1);
      insert(i-1,j);
      insert(i-1,j-1);
      insert(i-1,j+1);
      nines.pop();
    }

    if (has.size()==100) {
      cout << tt << endl;
      break;
    }
    has.clear();
    nines = queue<pair<int,int>>();

  }

  
}

