#include <bits/stdc++.h>
using namespace std;
const int _n = 2e5 + 10;
int t, n, a;
bool vis[_n];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    memset(vis, 0, sizeof vis);
    bool ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> a;
      a += i, a %= n;
      if (a < 0) a += n;
      if (ans and vis[a]) ans = 0;
      vis[a] = 1;
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}