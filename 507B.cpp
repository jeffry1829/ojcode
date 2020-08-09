#include <bits/stdc++.h>
#define int long long
using namespace std;
int r, x, y, xx, yy;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> r >> x >> y >> xx >> yy;
  int ans = 1.0 * sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)) / (2.0 * r);
  if (abs(1.0 * ans * 2.0 * r - 1.0 * sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy))) > 1e-8) ans += 1;
  cout << ans << '\n';
  return 0;
}