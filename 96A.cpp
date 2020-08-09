#include <bits/stdc++.h>
using namespace std;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  int a = 0, b = 0;
  if (s[0] == '0')
    a++;
  else
    b++;
  string res = "NO\n";
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == '0' and s[i - 1] == '0')
      a++;
    else if (s[i] == '1' and s[i - 1] == '1')
      b++;
    if (s[i] != s[i - 1] and s[i] == '0') a = 1, b = 0;
    if (s[i] != s[i - 1] and s[i] == '1') a = 0, b = 1;
    if (a >= 7 or b >= 7) {
      res = "YES\n";
      break;
    }
  }
  cout << res;
  return 0;
}