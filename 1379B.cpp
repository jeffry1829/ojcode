#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a, b, c, l, r, m;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> l >> r >> m;
    for (int a = l; a <= r; a++) {
      if (m - (m / a) * a <= r - l and m / a > 0) {
        cout << a << " " << l + m - (m / a) * a << " " << l << '\n';
        break;
      }
      if (((m / a) + 1) * a - m <= r - l and m / a > 0) {
        cout << a << " " << l << " " << l + ((m / a) + 1) * a - m << '\n';
        break;
      }
      if (m / a == 0 and a - m <= r - l) {
        cout << a << " " << l << " " << l + a - m << '\n';
        break;
      }
    }
  }
  return 0;
}