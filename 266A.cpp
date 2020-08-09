#include <bits/stdc++.h>
using namespace std;
int n, res;
char _prev;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> s;
  _prev = s[0];
  for (int i = 1; i < n; i++) {
    if (_prev == s[i])
      res++;
    else {
      _prev = s[i];
    }
  }
  cout << res << '\n';
  return 0;
}