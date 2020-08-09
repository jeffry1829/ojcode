#include <bits/stdc++.h>
using namespace std;
int t, n, a[50], s[2];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    s[0] = s[1] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if ((i & 1) != (a[i] & 1)) s[a[i] & 1]++;
    }
    if (s[0] != s[1])
      cout << -1 << '\n';
    else
      cout << s[0] << '\n';
  }
  return 0;
}