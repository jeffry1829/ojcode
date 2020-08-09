#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> r;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  r.push_back(0);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+') {
      r.push_back(0);
      continue;
    }
    r.back() = r.back() * 10 + s[i] - '0';
  }
  sort(r.begin(), r.end());
  cout << r[0];
  for (int i = 1; i < r.size(); i++) {
    cout << '+' << r[i];
  }
  cout << '\n';
  return 0;
}