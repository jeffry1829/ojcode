#include <bits/stdc++.h>
using namespace std;

main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int ans = (b * (a / b) == a) ? 0 : b * (a / b + 1) - a;
    if (a < b) ans = b - a;
    cout << ans << '\n';
  }
  return 0;
}