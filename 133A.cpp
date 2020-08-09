#include <bits/stdc++.h>
using namespace std;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'H' or s[i] == 'Q' or s[i] == '9') {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}