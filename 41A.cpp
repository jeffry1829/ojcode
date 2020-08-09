#include <bits/stdc++.h>
using namespace std;
string s1, s2;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2;
  if (s1.length() != s2.length()) {
    cout << "NO\n";
    return 0;
  }
  int x = 0, y = s2.length() - 1;
  for (int i = 0; i < s2.length(); i++) {
    if (s1[x + i] != s2[y - i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}