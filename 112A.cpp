#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int len;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2;
  len = s1.length();
  int res = 0;
  for (int i = 0; i < len; i++) {
    if (s1[i] < 'a') s1[i] = s1[i] - 'A' + 'a';
    if (s2[i] < 'a') s2[i] = s2[i] - 'A' + 'a';
    if (s1[i] < s2[i]) {
      res = -1;
      break;
    }
    if (s1[i] > s2[i]) {
      res = 1;
      break;
    }
  }
  cout << res << '\n';
  return 0;
}