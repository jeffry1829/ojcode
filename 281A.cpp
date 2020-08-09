#include <bits/stdc++.h>
using namespace std;
string s;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  if (s[0] >= 'a') s[0] = s[0] - 'a' + 'A';
  cout << s << '\n';
  return 0;
}