#include <bits/stdc++.h>
using namespace std;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  int up = 0;
  bool doup = 0;
  for (int i = 0; i < s.length(); i++)
    if (s[i] < 'a') up++;
  if (up > s.length() - up) doup = 1;
  if (doup) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'a')
        cout << (char)(s[i] - 'a' + 'A');
      else
        cout << (char)s[i];
    }
    cout << '\n';
  } else {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] < 'a')
        cout << (char)(s[i] + 'a' - 'A');
      else
        cout << (char)s[i];
    }
    cout << '\n';
  }
  return 0;
}