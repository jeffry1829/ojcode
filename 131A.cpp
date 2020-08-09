#include <bits/stdc++.h>
using namespace std;
string s;
bool fst, lat = 1;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  if (s[0] < 'a') fst = 1;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] >= 'a') {
      lat = 0;
      break;
    }
  }
  if (fst and lat) {
    for (int i = 0; i < s.length(); i++) {
      cout << (char)(s[i] - 'A' + 'a');
    }
    cout << '\n';
  } else if (!fst and lat) {
    cout << (char)(s[0] - 'a' + 'A');
    for (int i = 1; i < s.length(); i++) {
      cout << (char)(s[i] - 'A' + 'a');
    }
    cout << '\n';
  } else {
    cout << s << '\n';
  }
  return 0;
}