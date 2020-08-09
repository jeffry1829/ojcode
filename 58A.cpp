#include <bits/stdc++.h>
using namespace std;
string _s = "hello", s;
int idx = 0;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == _s[idx]) idx++;
  }
  if (idx > 4)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}