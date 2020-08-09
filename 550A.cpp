#include <bits/stdc++.h>
using namespace std;
char s[100010];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> s;
  int l = strlen(s);
  bool ab = 0, ba = 0;
  for (int i = 0; i < l - 1; i++) {
    if (!ab and s[i] == 'A' and s[i + 1] == 'B') {
      ab = 1, i++;
      continue;
    }
    if (ab and !ba and s[i] == 'B' and s[i + 1] == 'A') ba = 1;
  }
  if (ab and ba) {
    cout << "YES\n";
    return 0;
  }
  ab = ba = 0;
  for (int i = 0; i < l - 1; i++) {
    if (!ba and s[i] == 'B' and s[i + 1] == 'A') {
      ba = 1, i++;
      continue;
    }
    if (ba and !ab and s[i] == 'A' and s[i + 1] == 'B') ab = 1;
  }
  if (ab and ba) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}