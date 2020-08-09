#include <bits/stdc++.h>
using namespace std;
char s[210];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  int i = 0, len = strlen(s);
  while (1) {
    if (s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B' and i + 2 < len) {
      i += 3;
    } else
      break;
  }
  bool _prev = 0;
  while (1) {
    if (s[i] == '\0') break;
    if (s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B' and i + 2 < len) {
      if (!_prev) cout << " ";
      i += 3;
      _prev = 1;
    } else {
      cout << s[i];
      _prev = 0;
      i++;
    }
  }
  return 0;
}