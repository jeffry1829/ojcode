#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _n = 1010;
int n, l, a[_n], maxx = -0x7f7f7f7f;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    maxx = max(maxx, a[i] - a[i - 1]);
  }
  maxx = max(maxx, max(a[0] << 1, (l - a[n - 1]) << 1));
  cout << setprecision(9) << 1.0 * maxx / 2.0 << '\n';
  return 0;
}