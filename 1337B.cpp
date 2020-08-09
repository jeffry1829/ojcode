#include <bits/stdc++.h>
using namespace std;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t, x, n, m;
  cin >> t;
  while (t--) {
    cin >> x >> n >> m;
    while (n) {
      if ((x >> 1) + 10 >= x) break;
      x >>= 1, x += 10, n--;
    }
    while (m--) x -= 10;
    cout << (x <= 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}