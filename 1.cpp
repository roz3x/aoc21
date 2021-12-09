
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;


int main() {
  vector<int> v;
  int a;
  while ((scanf("%d", &a))!=EOF) {
    v.push_back(a);
  }
  vector<int> n;
  for (int i=0;i<v.size();i++) {
    int sum = 0;
    for (int j=0;j<3;j++) sum += v[i+j];
    n.push_back(sum);
  }
  dbg(n);
  int cnt = 0;
  for (int i=1;i<n.size();i++) {
    if (n[i] > n[i-1]) cnt++;
  }
  cout << cnt << endl;
}

