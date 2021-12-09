
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;

vector<vector<vector<int>>> input(void) {
  vector<vector<vector<int>>> res;
  for (int i=0;i<100;i++) {
    vector<vector<int>> a(5, vector<int>(5,0));
    for (int i=0;i<5;i++)
      for (int j=0;j<5;j++) cin >> a[i][j];

    res.push_back(a);
  }
  return res;
}

void report(vector<vector<int>> &a, vector<vector<bool>> &b, int c) {
  int sum=0;
  for (int i=0;i<5;i++) 
    for (int j=0;j<5;j++)
      if (!b[i][j]) sum+=a[i][j];

  cout << sum * c << endl;

}

int main() {
  int draw[100];
  for (int i=0;i<100;i++) {
    scanf("%d,", &draw[i]);
  }
  
  auto res = input();
  vector<vector<vector<bool>>> done(100, vector<vector<bool>>(5, vector<bool>(5, false)));

  set<int> dusted;

  for (int i=0;i<100;i++) {

    for (int j=0;j<100;j++) {

      for (int k=0;k<5;k++) 
        for (int t=0;t<5;t++)
          if(res[j][k][t]==draw[i]) done[j][k][t]=true;
    }

    // check completed rows
    //

    for (int j=0;j<100;j++) {
      for (int k=0;k<5;k++) {
        int cnt=0;
        for (int t=0;t<5;t++) {
          if (done[j][k][t]) cnt++;
        }
        if (cnt==5) {
          report(res[j], done[j], draw[i]);
        }
      }
    }


    // check columns
    //

    for (int j=0;j<100;j++) {
      for (int k=0;k<5;k++) {
        int cnt =0;
        for (int t=0;t<5;t++) {
          if (done[j][t][k]) cnt++;
        }
        if (cnt == 5) {
          report(res[j], done[j], draw[i]);
        }
      }
    }
  }

}

