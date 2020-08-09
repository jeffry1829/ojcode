#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[1010], b[1010];
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i] == b[j]) {
          cout << "YES\n1 " << a[i] << '\n';
          goto A;
        }
      }
    }
    cout << "NO\n";
  A:
    continue;
  }
  return 0;
}