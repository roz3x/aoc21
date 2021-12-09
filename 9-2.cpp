
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;

vector<vector<int>> m(100, vector<int>(100, 0));
vector<vector<bool>> done(100, vector<bool>(100, false));
vector<vector<int>> found(100, vector<int>(100, 0));
void recur(int i , int j , int k) {
  if (i < 0 || i >= 100) {
    return;
  }
  if (j < 0 || j >= 100) {
    return;
  }
  if (m[i][j]==9) return;
  if (done[i][j]) return;
  done[i][j] = true;
  found[i][j] = k;
  recur(i-1,j,k);
  recur(i+1,j,k);
  recur(i,j-1,k);
  recur(i,j+1,k);
}
int main() {
  string s;
  for (int i=0;i<100;i++)  {
    cin >> s;
    for (int j=0;j<100;j++)
      m[i][j] = s[j] - '0';
  }
  

  int cnt = 1;
  for (int i=0;i<100;i++) {
    for(int j=0;j<100;j++) {
      if (m[i][j]!=9 && !done[i][j]) {
        recur(i , j, cnt);
        cnt++;
      }
    }
  }

  map<int,int> lu;
  for (int i=0;i<100;i++) {
    for (int j=0;j<100;j++) {
      lu[found[i][j]]++;
    }
  } 
  vector<int> largest;
  for (auto i : lu) {
    if (i.first != 0) {
      largest.push_back(i.second);
    }
  }
  sort(largest.begin(), largest.end(), greater<int>());

  long long int prod = 1;
  for (int i=0;i<3;i++) prod *= largest[i];
  cout << prod << endl;

}

