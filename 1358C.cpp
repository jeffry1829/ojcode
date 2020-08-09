#include <bits/stdc++.h>
#define y1 knaiskndoasnd
using namespace std;
int t, x1, x2, y1, y2;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 1ll * (y2 - y1) * (x2 - x1) + 1ll << '\n';
  }
  return 0;
}