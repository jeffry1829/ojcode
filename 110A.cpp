#include <bits/stdc++.h>
using namespace std;
int cnt[8];
char c;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  while (c = getchar(), c < '0' || c > '9')
    if (c == -1) return 0;
  cnt[c - '0']++;
  while (c = getchar(), c >= '0' && c <= '9') {
    cnt[c - '0']++;
  }
  if (cnt[4] + cnt[7] == 4 || cnt[4] + cnt[7] == 7) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}