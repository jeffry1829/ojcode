#include <bits/stdc++.h>
using namespace std;
int n, t;
string s;
char _prev;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> t >> s;
  for (int i = 0; i < t; i++) {
    _prev = s[0];
    for (int j = 1; j < n; j++) {
      char t = s[j];
      if (s[j] == 'G' and _prev == 'B') swap(s[j], s[j - 1]);
      _prev = t;
    }
  }
  cout << s << '\n';
  return 0;
}