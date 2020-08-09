#include <bits/stdc++.h>
using namespace std;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'a') s[i] = s[i] + 'a' - 'A';
    if (s[i] == 'a' or s[i] == 'o' or s[i] == 'y' or s[i] == 'e' or s[i] == 'u' or s[i] == 'i')
      continue;
    cout << '.' << s[i];
  }
  cout << '\n';
  return 0;
}