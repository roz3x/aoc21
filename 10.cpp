
#include <bits/stdc++.h>
#ifdef DEBUG
#include <dbg.h>
#endif
using namespace std;

const int N = 94;
set<char> opens = {'{', '(', '<', '['};
map<char,char> rev;
map<char,int> reward;
map<char, int> panality;

int main() {
  string s;
  rev['}'] = '{';
  rev[']'] = '[';
  rev['>'] = '<';
  rev[')'] = '(';

  reward['('] = 1;
  reward['['] = 2;
  reward['{'] = 3;
  reward['<'] = 4;

  panality[')'] = 3;
  panality[']'] = 57;
  panality['}'] = 1197;
  panality['>'] = 25137;

  vector<long long int> additives;
  for (int i=0;i<N;i++) {
    cin >> s;
    stack<char> a;

    bool found = false;
    for (auto c : s) {
      if (opens.count(c)) {
        a.push(c);
      } else {
        if (a.top()!=rev[c]) {
          found = true;
          break;
        } else {
          a.pop();
        }
        
      }
    }
    if (!found) {
      long long int sum = 0;
      while(!a.empty()) {
        sum *= 5;
        sum += reward[a.top()];
        a.pop();
      }
      additives.push_back(sum);
    }

  }
  sort(additives.begin(), additives.end());
  cout << additives[(additives.size()-1)/2] << endl;

}

