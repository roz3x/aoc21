
#include <bits/stdc++.h>
#ifdef DEBUG
  #include <dbg.h>
#endif
using namespace std;

vector<int> a;
int main() {
  
  int tmp;
  while(scanf("%d,", &tmp) != EOF) {
    a.push_back(tmp);
  }

  vector<long long> cnt(10);
  for (int i=0;i<a.size();i++) {
    cnt[a[i]]++;
  }

  
  for (int i=0;i<256;i++) { 
    long long tmp = cnt[0];
    for (int i=1;i<=8;i++) {
      cnt[i-1] = cnt[i];
    }
    cnt[6] += tmp;
    cnt[8] = tmp;
  }

  long long  sum =0;
  for (auto i : cnt)  sum+=i;
  cout  << sum << endl;

}

